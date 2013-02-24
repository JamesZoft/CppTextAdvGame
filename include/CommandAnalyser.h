#ifndef COMMANDANALYSER_H
#define COMMANDANALYSER_H
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include "Player.h"

class CommandAnalyser
{
    public:
        CommandAnalyser();
        virtual ~CommandAnalyser();
        static bool analyse(std::string command, Player *player);
    protected:

    private:
        static bool analyseMoveCommand(Player player);
         inline static bool regexSearch(std::string command, boost::regex regexString) { boost::smatch results; return boost::regex_search(command, results, regexString); }
        static void help();
        std::vector<std::string> commands = {"help", "quit"};
};

#endif // COMMANDANALYSER_H
