#include "OpLineLables.h"

namespace experis
{

OpLineLables::OpLineLables(const std::optional<KeyVal>& a_lineLable, const std::optional<ValLable>& a_valLable)
	: m_lineLable{a_lineLable}
	, m_valLable{a_valLable}
{
}
	
OpLineLables::~OpLineLables()
{
}

const std::optional<KeyVal>& OpLineLables::GetLineLable() const
{
	return this->m_lineLable;
}

const std::optional<ValLable>& OpLineLables::GetValLable() const
{
	return this->m_valLable;
}

}//experis
