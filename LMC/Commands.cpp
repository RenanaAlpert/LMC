#include "Commands.h"
#include <cassert>
#include <fstream>

namespace experis
{

Commands::Commands()
	: m_commandsList{}
{
}

//Commands::Commands(std::initializer_list<std::string> a_listCommands)
//	: m_commandsList{}
//{
//	for (std::string s : a_listCommands)
//	{
//		this->PushBack(s);
//	}
//}

Commands::Commands(std::vector<std::string> a_listCommands)
	: m_commandsList{}
{
	for (std::string s : a_listCommands)
	{
		this->PushBack(s);
	}
}

Commands::Commands(const std::string& a_codeFilePath)
	: m_commandsList{}
{
	std::ifstream infile;
	infile.open(a_codeFilePath);
    if(infile.is_open()) 
	{	std::string codeLine{};
		while(std::getline(infile, codeLine))
		{
			this->PushBack(codeLine);
		}
        infile.close();
    } 
	else 
	{
        //TODO throw
    }
}

Commands::~Commands()
{
	for (size_t i = 1 ; i <= m_commandsList.size() ; ++i)
	{
		delete this->m_commandsList.at(m_commandsList.size() - i);
	}
	/*while (m_commandsList.size() > 0)
	{
		delete this->m_commandsList.at(m_commandsList.size() - 1);
	}*/
}

std::optional<Key> Commands::GetLable(size_t a_index) const
{
	return this->m_commandsList.at(a_index)->GetLable();
}


std::optional<Key> Commands::GetOpcode(size_t a_index) const
{
	return this->m_commandsList.at(a_index)->GetOpcode();
}

std::optional<Key> Commands::GetAddress(size_t a_index) const
{
	return this->m_commandsList.at(a_index)->GetAddress();
}

CmdType Commands::GetType(size_t a_index) const//TODO better switch
{
	assert(this->m_commandsList.at(a_index)->GetOpcode().has_value());
	return (this->m_commandsList.at(a_index)->GetOpcode().value() == "DAT" 
		|| this->m_commandsList.at(a_index)->GetOpcode().value() == "dat") ? CmdType::DATA : CmdType::TXT;
}

size_t Commands::Size() const
{
	return this->m_commandsList.size();
}

void Commands::PushBack(std::string& a_newItem)
{
	CommandText* com = new CommandText(a_newItem);
	this->m_commandsList.push_back(com);
}

}
