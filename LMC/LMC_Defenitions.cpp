#include <ostream>
#include "LMC_Defenitions.h"

namespace experis
{

std::ostream& operator<<(std::ostream& a_os, const CmdSegment& a_cmdSegment)
{
	switch(a_cmdSegment)
	{

	case CmdSegment::DATA:
	{
		a_os << "DATA";
		break;
	}
	case CmdSegment::TXT:  //TODO what???
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

