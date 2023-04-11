#pragma once

//#include "Cmds.h"
#include "Commands.h"

namespace experis
{

static const std::vector<Key> COMMAND = { "HLT", "ADD", "SUB", "STO", "STA", "LDA", "BRA", "BRZ", "BRP", "INP", "OUT", "OTC", "DAT" };

const bool ValueInVector(const Key& a_key, const std::vector<Key> a_lineLables);
const bool IsValidSymbols(const Commands& a_cmds);

}//experis
