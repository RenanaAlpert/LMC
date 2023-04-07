#include "ValLable.h"

namespace experis
{

ValLable::ValLable(const Key& a_key, const size_t& a_atLineNum)
	: m_key{a_key}
	, m_atLineNum{a_atLineNum}
{
}

ValLable::ValLable(const ValLable& a_valLable)
	: m_key{a_valLable.m_key}
	, m_atLineNum{a_valLable.m_atLineNum}
{
}

ValLable::~ValLable()
{
}

const Key& ValLable::GetKey() const
{
	return this->m_key;
}

const size_t ValLable::GetAtLineNum() const
{
	return this->m_atLineNum;
}


std::ostream& operator<<(std::ostream& a_os, const ValLable& a_valLable)
{
	a_os << "[Key: " << a_valLable.GetKey() << " --- @Line#: " << a_valLable.GetAtLineNum() << "]\n";
	return a_os;
}

}//experis



//const Key& KeyVal::GetKey() const
//{
//	return this->m_key;
//}
//
//const Val& KeyVal::GetVal() const
//{
//	return this->m_val;
//}
//
//const bool operator==(const KeyVal& a_keyVal1, const KeyVal& a_keyVal2)
//{
//	return a_keyVal1.GetKey() == a_keyVal1.GetKey();
//}


/*KeyVal::KeyVal() = delete;  
KeyVal& KeyVal::operator=(const KeyVal& a_keyVal) = delete;*/ 
