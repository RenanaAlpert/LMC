#include "Commands.h"

namespace experis
{

Commands::Commands()
	: m_commandsList{}
{
}

Commands::Commands(const std::initializer_list<std::string&> a_listCommands)
	: m_commandsList{}
{
	for (std::string& s : a_listCommands)
	{
		this->PushBack(s);
	}
}

Commands::~Commands()
{
	while (m_commandsList.size() > 0)
	{
		delete this->m_commandsList.at(m_commandsList.size() - 1);
	}
}

std::optional<Key> Commands::GetLable(size_t a_index)
{
	return this->m_commandsList.at(a_index)->GetLable();
}

std::optional<Key> Commands::GetAddress(size_t a_index)
{
	return this->m_commandsList.at(a_index)->GetAddress();
}

void Commands::PushBack(std::string& a_newItem)
{
	CommandText* com = new CommandText(a_newItem);
	this->m_commandsList.push_back(com);
}

}