#include "CommandToNumber.h"

namespace experis
{

CommandToNumber::CommandToNumber(const std::string& a_Txt, size_t a_opcode)
	: m_txtCmd(a_Txt), m_opcode(a_opcode)
{
}

CommandToNumber::CommandToNumber(const CommandToNumber& a_other)
	: m_txtCmd{a_other.m_txtCmd}, m_opcode{a_other.m_opcode}
{
}

std::string CommandToNumber::GetTxtCmd() const
{
	return this->m_txtCmd;
}

size_t CommandToNumber::GetOpcode() const
{
	return this->m_opcode;
}

}