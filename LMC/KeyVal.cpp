#include "KeyVal.h"

namespace experis
{

KeyVal::KeyVal(const Key& a_key, const Val& a_val)
	: m_key{a_key}
	, m_val{a_val}
{
}

KeyVal::KeyVal(const KeyVal& a_keyVal)
	: m_key{a_keyVal.m_key}
	, m_val{a_keyVal.m_val}
{
}

KeyVal::~KeyVal()
{
}

const Key& KeyVal::GetKey() const
{
	return this->m_key;
}

const Val& KeyVal::GetVal() const
{
	return this->m_val;
}

const bool operator==(const KeyVal& a_keyVal1, const KeyVal& a_keyVal2)
{
	return a_keyVal1.GetKey() == a_keyVal1.GetKey();
}

std::ostream& operator<<(std::ostream& a_os, const KeyVal& a_keyVal)
{
	a_os << "[Key: " << a_keyVal.GetKey() << " --- Val: " << a_keyVal.GetVal() << "]\n";
	return a_os;
}

}//experis
