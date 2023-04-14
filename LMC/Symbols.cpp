#include <cassert>
#include <fstream>
#include <iostream>
#include "Symbols.h"
#include "HandyFuncs.h"
#include "Exceptions.h"

namespace experis
{

Symbols::Symbols(const Commands& a_commands)
	: m_symbols{InitializeFromCmds(a_commands)}
{
}

Symbols::~Symbols()
{
}

std::optional<size_t> Symbols::KeyDictIdx(const Key& a_key, const std::vector<Symbol>& a_symbols) const
{
	for (size_t i = 0; i < a_symbols.size(); ++i)
	{
		if (a_symbols.at(i).GetKey() == a_key)
		{
			return std::optional<size_t>{i};
		}
	}
	return std::optional<size_t>{};
}

const bool Symbols::IsLableInSymbols(const Key& a_key, const std::vector<Symbol> a_symbols) const
{
	for(Symbol symbol : a_symbols)
	{
		if(symbol.GetKey() == a_key)
		{
			return true;
		}
	}
	return false;
}

std::vector<Symbol> Symbols::InitializeFromCmds(const Commands& a_commands) const
{
	std::vector<Symbol> symbols = std::vector<Symbol>{};

	for (size_t i = 0; i < a_commands.Size(); ++i)
	{
		const std::optional<Key> optionalLineLable = a_commands.GetLable(i);
		if (optionalLineLable.has_value())
		{
			if (IsStringAlphaPrefix(optionalLineLable.value()))
			{
				const Key lineLable = optionalLineLable.value();

				if(IsLableInSymbols(lineLable, symbols))
				{
					LineLablesException error{"Line lable appears more than once!!! ", lineLable};
					throw error;
				}

				CmdSegment cmdSegment = a_commands.GetSegment(i);
				KeyVal keyVal = KeyVal(optionalLineLable.value(), i);
				Symbol symbol = Symbol(keyVal, cmdSegment);

				symbols.push_back(symbol);
			}
		}
	}

	for (size_t i = 0; i < a_commands.Size(); ++i)
	{
		std::optional<Key> optionalAdressLable = a_commands.GetAddress(i);

		if (optionalAdressLable.has_value())
		{
			if (IsStringAlphaPrefix(optionalAdressLable.value()))
			{
				const Key addressLable = optionalAdressLable.value();
				std::optional<size_t> keyDictIdx = KeyDictIdx(addressLable, symbols);
				if (keyDictIdx.has_value())
				{
					symbols.at(keyDictIdx.value()).AddReferenceIdx(i);
				}
				else
				{
					AddressLableException error{"Address lable is undefined!!! ", addressLable};
					throw error;
				}
			}
		}
	}
	return symbols;
}



const std::optional<Val> Symbols::GetLableVal(const Key& a_key) const
{
	for(Symbol symbol : this->m_symbols)
	{
		if (symbol.GetKey() == a_key)
		{
			return std::optional<Val>{symbol.GetVal()};
		}
	}
	return std::optional<Val>{};
}

std::ostream& operator<<(std::ostream& a_os, const Symbols& a_symbols)
{
	for(Symbol symbol : a_symbols.m_symbols)
	{
		a_os << symbol;
	}
	a_os << std::endl;
	return a_os;
}

void SymbolsToFile(const std::string& a_outFileName, const Symbols& a_symbols)
{
	
	std::fstream fs{a_outFileName, std::ios::out};
	if (!fs.is_open())
	{
		std::cout << "Failed to open file - " << a_outFileName << " for writing!!!" << std::endl;
		throw InputFileOpeningException{"Input file coulf not be opened", a_outFileName};
	}
	else
	{
		fs << a_symbols;
		fs.clear();
		fs.close();
		std::cout << "Succedded to write symbols to file - " << a_outFileName << std::endl;
	}
}

}//experis


 
 

//std::vector<Symbol> Symbols::InitializeFromCmds(const Cmds& a_cmds) const
//{
//	std::vector<Symbol> symbolTable = std::vector<Symbol>{};
//
//	for (size_t i = 0; i < a_cmds.GetLinesNumber(); ++i)
//	{
//		std::optional<Key> opKey = a_cmds.At(i).GetLineLable();
//		if (opKey.has_value())
//		{
//			CmdSegment cmdType = a_cmds.At(i).GetCmdType();
//			KeyVal keyVal = KeyVal(opKey.value(), i);
//			Symbol symbolTableCell = Symbol(keyVal, cmdType);
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
// 
// 
// 
// 
// 
// 
// 
// 
// 
//std::optional<Symbol&> Symbols::SymbolWithKey(const Key& a_key, std::vector<Symbol>& a_symbols) const
//{
//	for (Symbol& symbol : a_symbols)
//	{
//		if(symbol.GetKey() == a_key)
//		{
//			return std::optional<Symbol&>{symbol};	
//		}
//	}
//	return std::optional<Symbol&>{};
//}