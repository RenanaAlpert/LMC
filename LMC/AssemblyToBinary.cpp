#include "AssemblyToBinary.h"
#include "Commands.h"
#include "from_trusted_Symbols.h"
#include <cassert>

namespace experis
{

size_t GetOpcode(Key a_key)
{
	for (size_t i = 0 ; i < COMMAND.size() ; ++i)
	{
		if (COMMAND.at(i) == a_key)
		{
			return i;
		}
	}
	return -1;
}

size_t GetIO(Key a_key)
{
	for (size_t i = 0 ; i < COMMAND.size() ; ++i)
	{
		if (*(IO_COMMAND + i) == a_key)
		{
			return i;
		}
	}
	return -1;
}

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

std::vector<Command> TxtToBinary(std::vector<std::string>& a_text)
{
	Commands cmds{a_text};
	//from_trusted_Symbols convertTable{cmds};
	std::vector<Command> binaryCmds{};
	for (size_t i = 0 ; i < cmds.Size() ; ++i)
	{
		std::optional<Key> op = cmds.GetOpcode(i);
		assert(op.has_value());
		size_t opcode = GetOpcode(op.value());
		
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
				// TODO: waite to Nataliya
			}
		}
		else
		{
			if (opcode > 8)
			{
				opcode = 9;
				address = GetIO(op.value());
			}
		}
		Command cmd{opcode, address};
		binaryCmds.push_back(cmd);
	}
	return binaryCmds;
}

} // experis