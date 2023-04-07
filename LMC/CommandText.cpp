#include "CommandText.h"
#include <cassert>

namespace experis
{

CommandText::CommandText(const std::string& a_lable, const std::string& a_opcode, const std::string& a_address)
    : m_lable(a_lable), m_opcode(a_opcode), m_address(a_address)
{
}

CommandText::CommandText(const std::string& a_command)
{
    this->build(a_command);
}

CommandText::~CommandText()
{
}

std::vector<std::string> CommandText::Split(const std::string& a_toSplit, const char a_howSplit)
{
    std::vector<std::string> partsOfString{};
	int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= a_toSplit.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (a_toSplit[i] == a_howSplit || i == a_toSplit.size()) {
            endIndex = i;
            std::string temp;
            temp.append(a_toSplit, startIndex, endIndex - startIndex);
            partsOfString.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return partsOfString;
}

void CommandText::build(const std::string& a_command)
{
    std::vector<std::string> partsOfCommand  = Split(a_command, ' ');
    assert(partsOfCommand.size() <= 3 && partsOfCommand.size() > 0);
    if (partsOfCommand.size() == 3)
    {
        CommandText(partsOfCommand.at(0), partsOfCommand.at(1), partsOfCommand.at(2));
    }
    else if (partsOfCommand.size() == 2)
    {
        CommandText("", partsOfCommand.at(0), partsOfCommand.at(1));
    }
    else
    {
        CommandText("", partsOfCommand.at(0), "");
    }
}

}