#pragma once

#include "Using.h"

namespace experis
{

enum class CmdSegment
{
	DATA,
	TXT,
};
std::ostream& operator<<(std::ostream& a_os, const CmdSegment& a_cmdSegment);

static const std::vector<Key> COMMAND = { "HLT", "ADD", "SUB", "STO", "STA", "LDA", "BRA", "BRZ", "BRP", "INP", "OUT", "OTC", "DAT" };

//Renana======================> COMMAND ====> bring CMDS from Assembly2Binary and handle duality
}//experis

