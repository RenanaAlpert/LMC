#pragma once
#include <string>
#include <vector>
#include "Using.h"

namespace experis
{

static const Key ERROR{};
static const Key IO = "IO";
static const Key DAT = "DAT";
static const Key INP = "INP";
static const Key OUT = "OUT";
static const Key OCT = "OCT";


static const std::vector<Key> COMMAND = {"HLT", "ADD", "SUB", "STO", ERROR, "LDA", "BRA", "BRZ", "BRP", INP, OUT, OCT, DAT};
static const Key IO_COMMAND[23] = 
	/*0-10*/{ERROR, INP, OUT, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
	/*11-20*/ ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
	/*21-22*/ ERROR, OCT};

struct Command
{
	int m_opcode;
	int m_address;
};

std::vector<Command> TxtToBinary(std::vector<std::string>& a_text);

}