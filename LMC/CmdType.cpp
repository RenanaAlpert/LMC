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
	}

	case CmdType::TXT:  //TODO what???
	{
		a_os << "TXT";
	}

	}

	return a_os;
}

}//experis

