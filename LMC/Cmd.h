#pragma once

#include <string>
#include <optional>
#include "CmdType.h"

namespace experis
{
class Cmd
{
public:

	explicit Cmd() = delete;  
	Cmd(const Cmd& a_cmd); 
	explicit Cmd(const CmdType& a_cmdType, const std::optional<std::string>& a_lineLable, const std::optional<std::string>& a_valLable);
	Cmd& operator=(const Cmd& a_cmd) = delete; 
	~Cmd();

	const CmdType& GetCmdType() const;
	const std::optional<std::string>& GetLineLable() const;
	const std::optional<std::string>& GetValLable() const;


private:
	CmdType m_cmdType;
	std::optional<std::string> m_lineLable;
	std::optional<std::string> m_valLable;

};
}//experis


