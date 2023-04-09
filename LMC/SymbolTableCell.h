#pragma once

#include <vector>
#include "KeyVal.h"
#include "CmdType.h"

namespace experis
{

class SymbolTableCell
{
public:
	friend std::ostream& operator<<(std::ostream& a_os, const SymbolTableCell& a_symbolTableCell); //TODO const this??
	
	explicit SymbolTableCell() = delete;
	explicit SymbolTableCell(const KeyVal& a_keyVal, const CmdType& a_cmdType);
	SymbolTableCell(const SymbolTableCell& a_symbolTableCell); 
	SymbolTableCell& operator=(const SymbolTableCell& a_symbolTableCell) = delete; 
	~SymbolTableCell();

	void AddReferenceIdx(size_t a_ind); //TODO endure success?
	const Key& GetKey() const;
	const Val& GetVal() const;
	const CmdType& GetCmdType() const;
	const std::vector<size_t>& GetKyeReferenceIdxs() const;

private:
	CmdType m_cmdType;
	KeyVal m_keyVal; //TODO const? reference?
	std::vector<size_t> m_kyeReferenceIdxs;	
};

std::ostream& operator<<(std::ostream& a_os, const SymbolTableCell& a_symbolTableCell);

}//experis



