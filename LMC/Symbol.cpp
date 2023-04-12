#include "Symbol.h"

namespace experis
{

Symbol::Symbol(const KeyVal& a_keyVal, const CmdSegment& a_cmdSegment)
	: m_cmdSegment{a_cmdSegment}
	, m_keyVal{a_keyVal}
	, m_keyApearrenceIdxs{}
{
}

Symbol::Symbol(const Symbol& a_symbol)
	: m_cmdSegment{a_symbol.m_cmdSegment}
	, m_keyVal{a_symbol.m_keyVal}
	, m_keyApearrenceIdxs{a_symbol.m_keyApearrenceIdxs}
{
}

Symbol::~Symbol()
{
}
	
void Symbol::AddReferenceIdx(size_t a_ind)
{
	this->m_keyApearrenceIdxs.push_back(a_ind);
}

const Key& Symbol::GetKey() const
{
	return this->m_keyVal.GetKey();
}

const Val& Symbol::GetVal() const
{
	return this->m_keyVal.GetVal();
}

std::ostream& operator<<(std::ostream& a_os, const Symbol& a_symbol)
{
	a_os << a_symbol.m_cmdSegment;
	a_os << "\n:" << a_symbol.GetKey();
	a_os << "\n=" << a_symbol.GetVal() << std::endl;
	for(size_t idx : a_symbol.m_keyApearrenceIdxs)
	{
		a_os << "@" << idx << "\n";
	}
	a_os << std::endl;
	return a_os;
}


}//experis























//const CmdSegment& Symbol::GetCmdSegment() const
//{
//	return this->m_cmdSegment;
//}
//
//const Idxs& Symbol::GetApearrenceIdxs() const
//{
//	return this->m_keyApearrenceIdxs;
//}