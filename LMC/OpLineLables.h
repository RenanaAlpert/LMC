#pragma once

#include <optional>
#include <string>
#include "KeyVal.h"
#include "ValLable.h"

namespace experis
{

class OpLineLables
{
public:

	explicit OpLineLables() = delete;  
	explicit OpLineLables(const OpLineLables& a_opLineLable) = delete; 
	explicit OpLineLables(const std::optional<KeyVal>& a_lineLable, const std::optional<ValLable>& a_valLable);
	OpLineLables& operator=(const OpLineLables& a_opLineLable) = delete; 
	~OpLineLables();

	const std::optional<KeyVal>& GetLineLable() const;
	const std::optional<ValLable>& GetValLable() const;

private:
	std::optional<KeyVal> m_lineLable;
	std::optional<ValLable> m_valLable;
};

}//experis