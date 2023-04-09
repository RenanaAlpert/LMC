#include "SymbolTableCell.h"

namespace experis
{

SymbolTableCell::SymbolTableCell(const KeyVal& a_keyVal, const CmdType& a_cmdType)
	: m_cmdType{a_cmdType}
	, m_keyVal{a_keyVal}
	, m_kyeReferenceIdxs{}
{
}

SymbolTableCell::SymbolTableCell(const SymbolTableCell& a_symbolTableCell)
	: m_cmdType{a_symbolTableCell.m_cmdType}
	, m_keyVal{a_symbolTableCell.m_keyVal}
	, m_kyeReferenceIdxs{a_symbolTableCell.m_kyeReferenceIdxs}
{
}


SymbolTableCell::~SymbolTableCell()
{
}
	
void SymbolTableCell::AddReferenceIdx(size_t a_ind)
{
	this->m_kyeReferenceIdxs.push_back(a_ind);
}

const Key& SymbolTableCell::GetKey() const
{
	return this->m_keyVal.GetKey();
}

const Val& SymbolTableCell::GetVal() const
{
	return this->m_keyVal.GetVal();
}

const CmdType& SymbolTableCell::GetCmdType() const
{
	return this->m_cmdType;
}

const std::vector<size_t>&SymbolTableCell:: GetKyeReferenceIdxs() const
{
	return this->m_kyeReferenceIdxs;
}

std::ostream& operator<<(std::ostream& a_os, const SymbolTableCell& a_symbolTableCell)
{
	a_os << a_symbolTableCell.GetCmdType();
	a_os << "\n:" << a_symbolTableCell.GetKey();
	a_os << "\n=" << a_symbolTableCell.GetVal() << std::endl;
	for(size_t idx : a_symbolTableCell.GetKyeReferenceIdxs())
	{
		a_os << "@" << idx << "\n";
	}
	a_os << std::endl;
	return a_os;
}


}//experis