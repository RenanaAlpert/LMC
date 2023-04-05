#pragma once
#include <list>
#include <ostream>
//#include "KeyVal.h"
//#include "ValLable.h"
#include "OpLineLables.h"

namespace experis
{

class untrusted_SymbolsData
{
public:
	friend std::ostream& operator<<(std::ostream& a_os, const untrusted_SymbolsData& a_untrusted_symbolsData); //TODO Better than getters?

	explicit untrusted_SymbolsData();
	explicit untrusted_SymbolsData(const untrusted_SymbolsData& a_untrusted_SymbolsData) = delete; 
	untrusted_SymbolsData& operator=(const untrusted_SymbolsData& a_untrusted_SymbolsData) = delete; 
	~untrusted_SymbolsData();

	void AddOpLineLables(const OpLineLables& a_opLineLable);

private:
	void AddLineLable(const KeyVal& a_keyVal);     //TODO hwo to assure it was successfull?
	void AddValLable(const ValLable& a_valLable);  //TODO hwo to assure it was successfull?

	std::list<KeyVal> m_dictionary;
	std::list<ValLable> m_valLables;
};

std::ostream& operator<<(std::ostream& a_os, const untrusted_SymbolsData& a_untrusted_symbolsData); //TODO Better than method?

}//experis

	//explicit untrusted_SymbolsData(const KeyVal& a_keyVal);//TODO Change to OpLineLables??????????????????
	//explicit untrusted_SymbolsData(const ValLable& a_valLable);//TODO Change to OpLineLables??????????????????
	//explicit untrusted_SymbolsData(const KeyVal& a_keyVal, const ValLable& a_valLable);//TODO Change to OpLineLables??????????????????

