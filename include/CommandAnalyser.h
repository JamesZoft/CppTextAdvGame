#ifndef COMMANDANALYSER_H
#define COMMANDANALYSER_H
#include <string>
#include <vector>
#include <boost/regex.hpp>

class Player;

class CommandAnalyser
{
    public:
        CommandAnalyser();
        virtual ~CommandAnalyser();
        static bool analyse(std::string command, Player *player);
        static bool regexSearch(std::string command, boost::regex regexString);
    protected:

    private:
        static std::string getItemsAsString(Player *player);
        static std::string getMonstersAsString(Player *player);
        static bool analyseMoveCommand(Player player);
        static void help();
        std::vector<std::string> commands = {"help", "quit"};
};

#endif // COMMANDANALYSER_H
