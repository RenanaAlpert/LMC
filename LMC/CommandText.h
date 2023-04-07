#pragma once
#include <string>
#include <vector>

namespace experis
{

class CommandText
{
public:
	explicit CommandText() = delete;
	explicit CommandText(const std::string& a_lable, const std::string& a_opcode, const std::string& a_address);
	explicit CommandText(const std::string& a_command);
	//explicit CommandText(const std::initializer_list<std::string> a_listCommands);
	CommandText(const CommandText& a_other) = delete;
	CommandText& operator=(const CommandText& a_other) = delete;
	~CommandText(); 
	
private:
	std::vector<std::string> Split(const std::string& a_toSplit, const char a_howSplit);
	void build(const std::string& a_command);

	std::string m_lable;
	std::string m_opcode;
	std::string m_address;
};

}