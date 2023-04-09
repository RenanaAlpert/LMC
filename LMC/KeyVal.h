#pragma once

#include <string>
#include <ostream>
#include "Using.h"

namespace experis
{

class KeyVal
{
public:

	explicit KeyVal() = delete;  
	KeyVal(const KeyVal& a_keyVal); 
	explicit KeyVal(const Key& a_key, const Val& a_val);
	KeyVal& operator=(const KeyVal& a_keyVal) = delete; 
	~KeyVal();

	const Key& GetKey() const;
	const Val& GetVal() const;

private:
	Key m_key;
	Val m_val;
};

//const bool operator==(const KeyVal& a_keyVal1, const KeyVal& a_keyVal2);
//std::ostream& operator<<(std::ostream& a_os, const KeyVal& a_keyVal);

}//experis

