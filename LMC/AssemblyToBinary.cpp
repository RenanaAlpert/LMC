#include "AssemblyToBinary.h"
#include "Commands.h"
#include "from_trusted_Symbols.h"
#include "SymbolsValidator.h"
#include <cassert>

namespace experis
{

bool IsDigit(Key a_address)
{
	for (char c : a_address)
	{
		if (c < '0' || c > '9')
		{
			return false;
		}
	}
	return true;
}

std::vector<MechinLanguage> TxtToBinary(std::vector<std::string>& a_text)
{
	Commands cmds{a_text};
	from_trusted_Symbols convertTable{cmds};
	std::vector<MechinLanguage> binaryCmds{};
	for (size_t i = 0 ; i < cmds.Size() ; ++i)
	{
		std::optional<Key> op = cmds.GetOpcode(i);
		assert(op.has_value());
		size_t opcode = detail::FindOpcode(op.value());
		
		size_t address = 0;
		std::optional<Key> val = cmds.GetAddress(i);
		if (val.has_value())
		{
			if (IsDigit(val.value()))
			{
				address = std::stoi(val.value());
			}
			else
			{
				std::optional<size_t> mayAddress = convertTable.GetVal(val.value());
				if(mayAddress.has_value())
				{
					address = mayAddress.value();
				}
			}
		}
		MechinLanguage cmd = opcode + address;
		binaryCmds.push_back(cmd);
	}
	return binaryCmds;
}

size_t detail::FindOpcode(const std::string& a_opcode)
{
	for(size_t i = 0 ; i < CMDS.size() ; ++i)
	{
		if (CMDS.at(i).GetTxtCmd() == ToApperCase(a_opcode))
		{
			return CMDS.at(i).GetOpcode();
		}
	}
	return 10;
}

} // experis