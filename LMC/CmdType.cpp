#include <ostream>
#include "CmdType.h"

namespace experis
{

std::ostream& operator<<(std::ostream& a_os, const CmdType& a_cmdType)
{
	switch(a_cmdType)
	{

	case CmdType::DATA:
	{
		a_os << "DATA";
		break;
	}
	case CmdType::TXT:  //TODO what???
	{
		a_os << "TXT";
		break;
	}
	default:
	{
		break;
	}

	}

	return a_os;
}

}//experis

