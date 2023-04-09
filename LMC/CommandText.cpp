#include "CommandText.h"
#include <cassert>

namespace experis
{

CommandText::CommandText(const std::string& a_command)
{
    this->build(a_command);
}

CommandText::~CommandText()
{
}

std::optional<Key> CommandText::GetLable()
{
    if (this->m_lable.empty())
    {
        return std::optional<Key>{};
    }
    return this->m_lable;
}

std::optional<Key> CommandText::GetOpcode()
{
    if (this->m_opcode.empty())
    {
        return std::optional<Key>{};
    }
    return this->m_opcode;
}

std::optional<Key> CommandText::GetAddress()
{
    if (this->m_address.empty())
    {
        return std::optional<Key>{};
    }
    return this->m_address;
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

void CommandText::SetMembers(const std::string a_lable, const std::string a_opcode, const std::string a_address)
{
   this->m_lable = a_lable;
   this->m_opcode = a_opcode;
   this->m_address = a_address;
}

void CommandText::build(const std::string& a_command)
{
    std::vector<std::string> partsOfCommand  = Split(a_command, ' ');
    assert(partsOfCommand.size() <= 3 && partsOfCommand.size() > 0);
    if (partsOfCommand.size() == 3)
    {
        SetMembers(partsOfCommand.at(0), partsOfCommand.at(1), partsOfCommand.at(2));
    }
    else if (partsOfCommand.size() == 2)
    {
        SetMembers("", partsOfCommand.at(0), partsOfCommand.at(1));
    }
    else
    {
        SetMembers("", partsOfCommand.at(0), "");
    }
}

}