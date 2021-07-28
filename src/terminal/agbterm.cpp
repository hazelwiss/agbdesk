#include"agbterm.h"
#include<unordered_map>
#include<functional>
#include<vector>
#include<utility>
#include<array>
#include<stdexcept>
#define CMD_ENTRY [](const CommandArgs& args)

constexpr char DEFAULT_ARG[] = ":";
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
void printNL(const std::string& str){ out += str+"\n"; }

std::array<std::function<void(const CommandArgs&)>, (size_t)COMMAND::NUMCMDS+1> cmdarray = {
    CMD_ENTRY{  //  FLUSH
        cmdlog = std::vector<std::string>();
        out = std::string();
    },
    CMD_ENTRY{  //  PRINT
        printNL(args.at(DEFAULT_ARG));
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
        return ret;
    } else
        printNL("invalid command.");
    return DecodedCommand{.cmd=COMMAND::NUMCMDS};
}

void AGBTerm::run(const std::string& cmd){
    auto dcmd = decodeCommand(cmd);
    cmdlog.emplace_back(cmd.data());
    cmdarray[(size_t)dcmd.cmd](dcmd.args);
} 