#include"agbterm.h"
#include<unordered_map>
#include<functional>
#include<vector>
#include<utility>
#include<array>
#include<stdexcept>
#include<memory>
#include<atomic>
#include<mutex>

#define CMD_ENTRY [](const CommandArgs& args)

constexpr char DEFAULT_ARG[] = ":";

struct CommandDecoder{
    CommandDecoder(const std::string& cmd){
        std::string argstr;
        if(size_t pos = cmd.find(' '); pos != std::string::npos)
            argstr = cmd.substr(pos);
        else
            return;
        argstr = std::string(std::find_if(argstr.begin(), argstr.end(), [](char c)->bool{ return c != ' '; }), argstr.end());
        while(argstr.size()){
            bool isstring{false};
            char stringc;
            size_t strpos = 0;
            std::string cutstr = std::string(argstr.begin(), std::find_if(argstr.begin(), argstr.end(), [&](char c){
                bool ret = isstring ? c == stringc : c == ' ';
                ++strpos;
                if(c == '\'' || c == '\"'){
                    isstring = true;
                    stringc = c;
                }
                return ret;
            }));
            std::erase_if(cutstr, [&](char c)->bool{ return c == '\"' || c == '\'' || (!isstring && c == ' '); });
            std::string arg;
            std::string value;
            if(cutstr.find(':') != std::string::npos){
                arg = cutstr.substr(0,cutstr.find(':'));
                value = cutstr.substr(cutstr.find(':')+1);
            } else{
                arg = DEFAULT_ARG;
                value = cutstr;
            }
            decoded[arg] = value;
            if(cutstr.size() >= argstr.size())
                argstr = "";
            else{
                argstr = argstr.substr(strpos);
                argstr = std::string(std::find_if(argstr.begin(), argstr.end(), [](char c)->bool{ return c != ' '; }), argstr.end());
            }

        }
    }
    std::unordered_map<std::string, std::string>&& moveMap(){ return std::move(decoded); }
protected:
    std::unordered_map<std::string, std::string> decoded;
};

using CommandArgs = std::unordered_map<std::string, std::string>;
enum class COMMAND{
    FLUSH=0,
    PRINT,
    HELP,
    NUMCMDS
};

std::vector<std::string> cmdlog;
std::string out;
std::unordered_map<std::string, COMMAND> cmdstrings{
    {"flush",   COMMAND::FLUSH},
    {"print",   COMMAND::PRINT},
    {"help",    COMMAND::HELP}
};
std::unordered_map<COMMAND, std::string> cmddesc{
    {COMMAND::FLUSH, "empties the command log and output."},
    {COMMAND::PRINT, "prints the argument out to the console."},
    {COMMAND::HELP,  "shows this menu."}
};
void printNL(const std::string& str){ (out += str)+="\n"; }

std::array<std::function<void(const CommandArgs&)>, (size_t)COMMAND::NUMCMDS+1> cmdarray = {
    CMD_ENTRY{  //  FLUSH
        cmdlog = std::vector<std::string>();
        out = std::string();
    },
    CMD_ENTRY{  //  PRINT
        if(args.contains(DEFAULT_ARG))
            printNL(args.at(DEFAULT_ARG));
        else{
            printNL("no string to print was specified!");
        }
    },
    CMD_ENTRY{  //  HELP
        printNL("these are the available commands:");
        for(const auto& e: cmdstrings){
            printNL(std::string("---  ")+e.first+std::string(": ")+cmddesc[e.second]);
        }
    },
    CMD_ENTRY{} //  NO COMMAND
};

struct DecodedCommand{
    COMMAND cmd;
    CommandArgs args{{DEFAULT_ARG, ""}};
};

DecodedCommand decodeCommand(const std::string& cmd){
    if(std::string cmdstr = cmd.substr(0, cmd.find(' ')); cmdstrings.contains(cmdstr)){
        DecodedCommand ret{.cmd = cmdstrings[cmdstr]};
        CommandDecoder decode(cmd);
        ret.args = decode.moveMap();
        return ret;
    } else
        printNL("invalid command.");
    return DecodedCommand{.cmd=COMMAND::NUMCMDS};
}

struct Access{
    Access(){ RequestAccess(); }
    ~Access(){ ReleaseAccess(); }
    void RequestAccess(){ while(is_occuipied); is_occuipied = true; mut.lock(); }
    void ReleaseAccess(){ mut.unlock(); is_occuipied = false; }
protected:
static inline std::mutex mut;
static inline std::atomic_bool is_occuipied{false};
};

void AGBTerm::run(const std::string& cmd){
    Access hold;
    auto dcmd = decodeCommand(cmd);
    cmdlog.emplace_back(cmd.data());
    cmdarray[(size_t)dcmd.cmd](dcmd.args);
} 
std::string AGBTerm::cout(){ Access hold; return out; }
void AGBTerm::cin(const std::string& in){ Access hold; printNL(in); }