#include <cassert>
#include <fstream>
#include <iostream>
#include "from_trusted_Symbols.h"

namespace experis
{

//from_trusted_Symbols::from_trusted_Symbols(const Cmds& a_cmds)
//	: m_symbolTable{InitializeFromCmds(a_cmds)}
//{
//}

from_trusted_Symbols::from_trusted_Symbols(const Commands& a_commands)
	: m_symbolTable{InitializeFromCmds(a_commands)}
{
}

from_trusted_Symbols::~from_trusted_Symbols()
{
}

size_t from_trusted_Symbols::KeyDictIdx(const Key& a_key, const std::vector<SymbolTableCell>& a_symbolTable) const
{
	for (size_t i = 0; i < a_symbolTable.size(); ++i)
	{
		if (a_symbolTable.at(i).GetKey() == a_key)
		{
			return i;
		}
	}
	assert(true);
}

//std::vector<SymbolTableCell> from_trusted_Symbols::InitializeFromCmds(const Cmds& a_cmds) const
//{
//	std::vector<SymbolTableCell> symbolTable = std::vector<SymbolTableCell>{};
//
//	for (size_t i = 0; i < a_cmds.GetLinesNumber(); ++i)
//	{
//		std::optional<Key> opKey = a_cmds.At(i).GetLineLable();
//		if (opKey.has_value())
//		{
//			CmdType cmdType = a_cmds.At(i).GetCmdType();
//			KeyVal keyVal = KeyVal(opKey.value(), i);
//			SymbolTableCell symbolTableCell = SymbolTableCell(keyVal, cmdType);
//			symbolTable.push_back(symbolTableCell);
//		}
//	}
//
//	for (size_t i = 0; i < a_cmds.GetLinesNumber(); ++i)
//	{
//		std::optional<Key> opKey = a_cmds.At(i).GetValLable();
//		if (opKey.has_value())
//		{
//			size_t keyDictIdx = KeyDictIdx(opKey.value(), symbolTable);
//			symbolTable.at(keyDictIdx).AddReferenceIdx(i);
//		}
//	}
//
//
//	return symbolTable;
//}

std::vector<SymbolTableCell> from_trusted_Symbols::InitializeFromCmds(const Commands& a_commands) const
{
	std::vector<SymbolTableCell> symbolTable = std::vector<SymbolTableCell>{};

	for (size_t i = 0; i < a_commands.Size(); ++i)
	{
		std::optional<Key> opKey = a_commands.GetLable(i);
		if (opKey.has_value())
		{
			if ((opKey.value().at(0) >= 'a' && opKey.value().at(0) <= 'z') || (opKey.value().at(0) >= 'A' && opKey.value().at(0) <= 'Z'))
			{
				CmdType cmdType = a_commands.GetType(i);
				KeyVal keyVal = KeyVal(opKey.value(), i);
				SymbolTableCell symbolTableCell = SymbolTableCell(keyVal, cmdType);
				symbolTable.push_back(symbolTableCell);
			}
		}
	}

	for (size_t i = 0; i < a_commands.Size(); ++i)
	{
		std::optional<Key> opKey = a_commands.GetAddress(i);
		if (opKey.has_value())
		{
			if ((opKey.value().at(0) >= 'a' && opKey.value().at(0) <= 'z') || (opKey.value().at(0) >= 'A' && opKey.value().at(0) <= 'Z'))
			{
				size_t keyDictIdx = KeyDictIdx(opKey.value(), symbolTable);
				symbolTable.at(keyDictIdx).AddReferenceIdx(i);
			}
		}
	}


	return symbolTable;
}


const std::optional<Val> from_trusted_Symbols::GetVal(const Key& a_key) const
{
	for(SymbolTableCell symbolTableCell : this->m_symbolTable)
	{
		if (symbolTableCell.GetKey() == a_key)
		{
			return std::optional<Val>{symbolTableCell.GetVal()};
		}
	}
	return std::optional<Val>{};
}

std::ostream& operator<<(std::ostream& a_os, const from_trusted_Symbols& a_from_trusted_Symbols)
{
	for(SymbolTableCell symbolTableCell : a_from_trusted_Symbols.m_symbolTable)
	{
		a_os << symbolTableCell;
	}
	a_os << std::endl;
	return a_os;
}

void SymbolsToFile(const std::string& a_outFileName, const from_trusted_Symbols& a_from_trusted_Symbols)
{
	
	std::fstream fs{a_outFileName, std::ios::out};
	if (!fs.is_open())
	{
		std::cout << "Failed to open file - " << a_outFileName << " for writing!!!" << std::endl; //TODO
	}
	else
	{
		fs << a_from_trusted_Symbols;
		fs.clear();
		fs.close();
		std::cout << "Succedded to write symbols to file - " << a_outFileName << std::endl;
	}
}

}//experis


 
 
