#pragma once
#include <string>
#include <vector>
#include "CommandText.h"
#include "CmdTyp.h"

namespace experis
{

class Commands
{
public:
	explicit Commands();
	explicit Commands(std::initializer_list<std::string> a_listCommands);
	Commands(const Commands& a_other) = delete;
	Commands& operator=(const Commands& a_other) = delete;
	~Commands();

	std::optional<Key> GetLable(size_t a_index);
	std::optional<Key> GetOpcode(size_t a_index);
	std::optional<Key> GetAddress(size_t a_index);
	experis::CmdType GetType(size_t a_index);
	size_t Size();

private:
	void PushBack(std::string& a_newItem);

	std::vector<CommandText*> m_commandsList;
};

}