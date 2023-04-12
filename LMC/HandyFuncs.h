#pragma once

#include "Commands.h"

namespace experis
{



const bool ValueInVector(const Key& a_key, const std::vector<Key>& a_lineLables);
//const bool IsValidSymbols(const Commands& a_cmds);
std::string ToApperCase(const std::string& a_toUp);
const bool IsStringAlphaPrefix(const std::string& a_string);

}//experis
