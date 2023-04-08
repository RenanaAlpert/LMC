#pragma once

#include "Cmds.h"
#include "SymbolTableCell.h"
#include <initializer_list>

namespace experis
{

class from_trusted_Symbols
{
public:

	friend std::ostream& operator<<(std::ostream& a_os, const from_trusted_Symbols& a_from_trusted_Symbols); //TODO Better than method?
	
	explicit from_trusted_Symbols() = delete;
	explicit from_trusted_Symbols(const Cmds& a_cmds);
	explicit from_trusted_Symbols(const from_trusted_Symbols& a_from_trusted_Symbols) = delete; 
	from_trusted_Symbols& operator=(const from_trusted_Symbols& a_from_trusted_Symbols) = delete; 
	~from_trusted_Symbols();

	const std::optional<Val> GetVal(const Key& a_key) const;


private:
	std::vector<SymbolTableCell> InitializeFromCmds(const Cmds& a_cmds) const;
	size_t KeyDictIdx(const Key& a_key, const std::vector<SymbolTableCell>& a_symbolTable) const;

	std::vector<SymbolTableCell> m_symbolTable;
};

std::ostream& operator<<(std::ostream& a_os, const from_trusted_Symbols& a_from_trusted_Symbols); //TODO Better than method?

}//experis


