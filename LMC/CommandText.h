#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Using.h"

namespace experis
{

class CommandText
{
public:
	explicit CommandText() = delete;
	explicit CommandText(const std::string& a_command);
	//explicit CommandText(const std::initializer_list<std::string> a_listCommands);
	CommandText(const CommandText& a_other) = delete;
	CommandText& operator=(const CommandText& a_other) = delete;
	~CommandText(); 

	std::optional<Key> GetLable();	
	std::optional<Key> GetAddress();	
private:
	
	std::vector<std::string> Split(const std::string& a_toSplit, const char a_howSplit);
	void SetMembers(const std::string a_lable, const std::string a_opcode, const std::string a_address);
	void build(const std::string& a_command);

	Key m_lable;
	Key m_opcode;
	Key m_address;
};

}
