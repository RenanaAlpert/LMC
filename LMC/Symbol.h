#pragma once

#include <vector>
#include "KeyVal.h"
#include "LMC_Defenitions.h"
#include "Using.h"

namespace experis
{

class Symbol
{
public:
	friend std::ostream& operator<<(std::ostream& a_os, const Symbol& a_symbol); //TODO const this - no because it isn't bellow to the class
	
	explicit Symbol() = delete;
	explicit Symbol(const KeyVal& a_keyVal, const CmdSegment& a_cmdSegment);
	Symbol(const Symbol& a_symbol); 
	Symbol& operator=(const Symbol& a_symbol) = delete; 
	~Symbol();

	void AddReferenceIdx(size_t a_ind);

	const Key& GetKey() const;
	const Val& GetVal() const;

private:
	const CmdSegment m_cmdSegment;
	const KeyVal m_keyVal; 
	Idxs m_keyApearrenceIdxs;	
};

std::ostream& operator<<(std::ostream& a_os, const Symbol& a_symbol);

}//experis




	//const CmdSegment& GetCmdSegment() const;
	//const Idxs& GetApearrenceIdxs() const;