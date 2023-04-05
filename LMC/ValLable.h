#pragma once

#include <ostream>
#include "Using.h"

//#include <optional>
//#include <string>

namespace experis
{

class ValLable
{
public:

	explicit ValLable() = delete;  
	ValLable(const ValLable& a_valLable); 
	explicit ValLable(const Key& a_key, const size_t& a_atLineNum);
	ValLable& operator=(const ValLable& a_valLable) = delete; 
	~ValLable();

	const Key& GetKey() const;
	const size_t GetAtLineNum() const;

private:
	Key m_key;
	size_t m_atLineNum;
};

std::ostream& operator<<(std::ostream& a_os, const ValLable& a_valLable);

}//experis

