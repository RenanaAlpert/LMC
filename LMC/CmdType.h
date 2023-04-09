#pragma once

namespace experis
{

enum class CmdType //TODO better!!!
{
	DATA,
	TXT,
};

std::ostream& operator<<(std::ostream& a_os, const CmdType& a_cmdType);


}//experis

