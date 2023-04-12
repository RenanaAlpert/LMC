#include "CommandText.h"
#include "HandyFuncs.h"
#include "Exceptions.h"
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

bool CommandText::VecContain(const std::vector<char>& a_vec, const char a_c) const
{
    for ( char c : a_vec)
    {
        if (c == a_c)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::string> CommandText::Split(const std::string& a_toSplit, const std::vector<char>& a_howSplit)
{
    std::vector<std::string> partsOfString{};
	int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= a_toSplit.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (VecContain(a_howSplit, a_toSplit[i]) || i == a_toSplit.size()) {
            endIndex = i;
            std::string temp;
            temp.append(a_toSplit, startIndex, endIndex - startIndex);
            startIndex = endIndex + 1;
            if (temp == "")
            {
                continue;
            }
            partsOfString.push_back(temp);
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
    std::vector<char> toSplit{' ', '\t', '\n'};
    std::vector<std::string> partsOfCommand  = Split(a_command, toSplit);
    assert(partsOfCommand.size() <= 3 && partsOfCommand.size() > 0);
    if (partsOfCommand.size() == 3 && ValueInVector(ToApperCase(partsOfCommand.at(1)), COMMAND))
    {
        SetMembers(partsOfCommand.at(0), partsOfCommand.at(1), partsOfCommand.at(2));
    }
    else if (partsOfCommand.size() == 2)
    {
        if (ValueInVector(ToApperCase(partsOfCommand.at(0)), COMMAND))
        {
            SetMembers("", partsOfCommand.at(0), partsOfCommand.at(1));
        }
        else if (ValueInVector(ToApperCase(partsOfCommand.at(1)), COMMAND))
        {
            SetMembers(partsOfCommand.at(0), partsOfCommand.at(1), "");
        }
        else
        {
            IllegalInputException error{"Illegal input command", a_command};
            throw error;
        }
    }
    else if (ValueInVector(ToApperCase(partsOfCommand.at(0)), COMMAND))
    {
        SetMembers("", partsOfCommand.at(0), "");
    }
    else
    {
        IllegalInputException error{"Illegal input command", a_command};
        throw error;
    }
}

}
