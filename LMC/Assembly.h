#pragma once
#include <string>

namespace experis
{

struct Command
{
	int m_opcode;
	int m_address;
};

struct CommandText
{
	std::string m_lable;
	std::string m_opcode;
	std::string m_address;

	CommandText(const std::string& lable, const std::string& opcode, const std::string& address)
		: m_lable(lable), m_opcode(opcode), m_address(address)
	{
	}
};

Command AssemblyToBinary(const std::string& a_command);

}