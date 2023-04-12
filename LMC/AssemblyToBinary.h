#pragma once
#include <string>
#include <vector>
#include "Using.h"
#include "CommandToNumber.h"

namespace experis
{
	namespace detail
	{
		static const std::vector<CommandToNumber> CMDS = 
			{CommandToNumber{"HLT", 0},
			CommandToNumber{"ADD", 100},
			CommandToNumber{"SUB", 200},
			CommandToNumber{"STO", 300},
			CommandToNumber{"STA", 300},
			CommandToNumber{"LDA", 500},
			CommandToNumber{"BRA", 600},
			CommandToNumber{"BRZ", 700},
			CommandToNumber{"BRP", 800},
			CommandToNumber{"INP", 901},
			CommandToNumber{"OUT", 902},
			CommandToNumber{"OTC", 922},
			CommandToNumber{"DAT", 0}}; //Renana =======> Put in LMC_defenitions and handle duality

		size_t FindOpcode(const std::string& a_opcode);
	} // detail


std::vector<MechinLanguage> TxtToBinary(std::vector<std::string>& a_text);

}