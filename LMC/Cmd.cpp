#include "Cmd.h"

namespace experis
{

Cmd::Cmd(const Cmd& a_cmd)
	: m_cmdType{a_cmd.m_cmdType}
	, m_lineLable{a_cmd.m_lineLable}
	, m_valLable{a_cmd.m_valLable}
{
}

Cmd::Cmd(const CmdType& a_cmdType, const std::optional<std::string>& a_lineLable, const std::optional<std::string>& a_valLable)
	: m_cmdType{a_cmdType}
	, m_lineLable{a_lineLable}
	, m_valLable{a_valLable}
{
}

Cmd::~Cmd()
{
}

const CmdType& Cmd::GetCmdType() const
{
	return this->m_cmdType;
}

const std::optional<std::string>& Cmd::GetLineLable() const
{
	return this->m_lineLable;
}

const std::optional<std::string>&Cmd:: GetValLable() const
{
	return this->m_valLable;
}

}//experis

