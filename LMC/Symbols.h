#pragma once

#include "Commands.h"
#include "Symbol.h"
#include <initializer_list>

namespace experis
{

class Symbols
{
public:

	friend std::ostream& operator<<(std::ostream& a_os, const Symbols& a_symbols);
	
	explicit Symbols() = delete;
	explicit Symbols(const Commands& a_commands);
	explicit Symbols(const Symbols& a_symbols) = delete; 
	Symbols& operator=(const Symbols& a_symbols) = delete; 
	~Symbols();

	const std::optional<Val> GetLableVal(const Key& a_key) const;


private:
	std::vector<Symbol> InitializeFromCmds(const Commands& a_commands) const;
	const bool IsLableInSymbols(const Key& a_key, const std::vector<Symbol> a_symbols) const;
	std::optional<size_t> KeyDictIdx(const Key& a_key, const std::vector<Symbol>& a_symbols) const;

	std::vector<Symbol> m_symbols;
};

std::ostream& operator<<(std::ostream& a_os, const Symbols& a_symbols); 
void SymbolsToFile(const std::string& a_outFileName, const Symbols& a_symbols);

}//experis












	//std::vector<Symbol> InitializeFromCmds(const Cmds& a_cmds) const;
	//std::optional<Symbol&> SymbolWithKey(const Key& a_key, std::vector<Symbol>& a_symbols) const;
	//size_t LableIdxInDict(const Key& a_key, const std::vector<Symbol>& a_symbol) const;