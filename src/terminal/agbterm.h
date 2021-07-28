#pragma once
#include<string>

namespace AGBTerm{
    /* Runs specified command by string */
    void run(const std::string& cmd);
    /* Returns a reference to the console output */
    std::string cout();
    /* Prints string to console output without being regarded as a command */
    /// NOTE: A newline is automatically appended at the end of each string
    void cin(const std::string& in);
};