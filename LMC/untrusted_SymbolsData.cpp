#include "untrusted_SymbolsData.h"

namespace experis
{

untrusted_SymbolsData::untrusted_SymbolsData() 
	: m_dictionary{}
	, m_valLables{}
{
}


untrusted_SymbolsData::~untrusted_SymbolsData()
{
}

void untrusted_SymbolsData::AddLineLable(const KeyVal& a_keyVal)
{
	this->m_dictionary.push_back(a_keyVal);
}

void untrusted_SymbolsData::AddValLable(const ValLable& a_valLable)
{
	this->m_valLables.push_back(a_valLable);
}

void untrusted_SymbolsData::AddOpLineLables(const OpLineLables& a_opLineLable)
{
	if(a_opLineLable.GetLineLable().has_value())
	{
		this->AddLineLable(a_opLineLable.GetLineLable().value());
	}
	if(a_opLineLable.GetValLable().has_value())
	{
		this->AddValLable(a_opLineLable.GetValLable().value());
	}
}

std::ostream& operator<<(std::ostream& a_os, const untrusted_SymbolsData& a_untrusted_symbolsData)
{
	a_os << "====== Dictionary =======\n";
	for(KeyVal keyVal : a_untrusted_symbolsData.m_dictionary)
	{
		a_os << keyVal;
	}
	a_os << "\n====== ValLables =======\n";
	for(ValLable valLable : a_untrusted_symbolsData.m_valLables)
	{
		a_os << valLable;
	}
	return a_os;
}

}//experis



/*untrusted_SymbolsData::untrusted_SymbolsData(const KeyVal& a_keyVal) // TODO no body??
	: m_dictionary{}
	, m_valLables{}
{
	this->AddLineLable(a_keyVal);
}

untrusted_SymbolsData::untrusted_SymbolsData(const ValLable& a_valLable) // TODO no body??
	: m_dictionary{}
	, m_valLables{}
{
	this->AddValLable(a_valLable);
}

untrusted_SymbolsData::untrusted_SymbolsData(const KeyVal& a_keyVal, const ValLable& a_valLable) // TODO no body??
	: m_dictionary{}
	, m_valLables{}
{
	this->AddLineLable(a_keyVal);
	this->AddValLable(a_valLable);
}*/