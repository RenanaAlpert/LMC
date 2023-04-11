#include <vector>
#include "Using.h"
#include "SymbolsValidator.h"

namespace experis
{

const bool ValueInVector(const Key& a_key, const std::vector<Key> a_lineLables)
{
	for(Key lineLable : a_lineLables)
	{
		if (a_key == lineLable)
		{
			return true;
		}
	}
	return false;
}

const bool IsValidSymbols(const Commands& a_commands) //TODO cam be prittyer....
{
	std::vector<Key> lineLables{};

	std::optional<Key> lineLable{};
	for(size_t i = 0; i < a_commands.Size(); ++i)
	{
		lineLable = a_commands.GetLable(i);
		if (lineLable.has_value())
		{
			if(ValueInVector(lineLable.value(), lineLables))
			{
				return false;
			}
			lineLables.push_back(lineLable.value());
		}
	}

	std::optional<Key> valLable{};
	for(size_t i = 0; i < a_commands.Size(); ++i)
	{
		valLable = a_commands.GetAddress(i);
		if (valLable.has_value())
		{
			if (!ValueInVector(valLable.value(), lineLables))
			{
				return false;
			}
		}
	}

	return true;
}

std::string ToApperCase(const std::string& a_toUp)
{
    std::string toReturn{};
    for (char c : a_toUp)
    {
		if (c >= 'a' && c <= 'z')
		{
			toReturn.push_back(c - 32);
		}
		else
		{
			toReturn.push_back(c);
		}
    }
    return toReturn;
}

}//experis




//#include <vector>
//#include "SymbolsValidator.h"
//
//namespace experis
//{
//	
//SymbolsValidator::SymbolsValidator(const Cmds& a_cmds)
//	: m_cmds{a_cmds}
//{
//}
//
//SymbolsValidator::~SymbolsValidator()
//{
//}
//
//const bool SymbolsValidator::IsValidSymbols() const //TODO cam be prittyer....
//{
//	std::vector<Key> lineLables{};
//
//	std::optional<Key> lineLable{};
//	for(size_t i = 0; i < m_cmds.GetLinesNumber(); ++i)
//	{
//		lineLable = m_cmds.GetCommand(i).GetLineLable();
//		if (lineLable.has_value())
//		{
//			if(ValueInVector(lineLable.value(), lineLables))
//			{
//				return false;
//			}
//			lineLables.push_back(lineLable.value());
//		}
//		
//	}
//
//	std::optional<Key> valLable{};
//	for(size_t i = 0; i < m_cmds.GetLinesNumber(); ++i)
//	{
//		valLable = m_cmds.GetCommand(i).GetValLable();
//		if (valLable.has_value())
//		{
//			if (!ValueInVector(valLable.value(), lineLables))
//			{
//				return false;
//			}
//		}
//	}
//
//	return true;
//}
//
//const bool SymbolsValidator::ValueInVector(const Key& a_key, const std::vector<Key> a_lineLables) const
//{
//	for(Key lineLable : a_lineLables)
//	{
//		if (a_key == lineLable)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//}//experis






//#include <vector>
//#include "SymbolsDataValidator.h"
//
//namespace experis
//{
////untrusted_SymbolsData m_untrusted_symbolsData;
//
////explicit SymbolsDataValidator() = delete;
////SymbolsDataValidator(const SymbolsDataValidator& a_symbolsDataValidator) = delete;
////SymbolsDataValidator& operator=(const SymbolsDataValidator& a_symbolsDataValidator) = delete;
//
//	
//SymbolsDataValidator::SymbolsDataValidator(const untrusted_SymbolsData& a_untrusted_symbolsData)
//	: m_untrusted_symbolsData{a_untrusted_symbolsData}
//{
//}
//
//SymbolsDataValidator::~SymbolsDataValidator()
//{
//}
//
//
//const bool SymbolsDataValidator::IsKeyAppearsPreviosly(const Key& a_key, const std::vector<KeyVal>& a_vector, size_t a_upToIdx) const
//{
//	for(size_t i = 0; i < a_upToIdx; ++i)
//	{
//		if(a_vector.at(i).GetKey() == a_key)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//const bool SymbolsDataValidator::IsAllKeysAppearOnce(const std::vector<KeyVal>& a_vecor) const
//{
//	const size_t vectorSize = a_vecor.size();
//	for(size_t i = 0; i < vectorSize; ++i)
//	{
//		if (IsKeyAppearsPreviosly(a_vecor.at(i).GetKey(), a_vecor, i))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//const bool SymbolsDataValidator::IsDictionariesKeysAppearOnce() const
//{
//	const std::vector<KeyVal>& txtDict = this->m_untrusted_symbolsData.m_dictionaryTXT;
//	if (!IsAllKeysAppearOnce(txtDict))
//	{
//		return false;
//	}
//
//	const std::vector<KeyVal>& dataDict = this->m_untrusted_symbolsData.m_dictionaryDATA;
//	if (!IsAllKeysAppearOnce(dataDict))
//	{
//		return false;
//	}
//
//	for(KeyVal txtKeyVal : txtDict)
//	{
//		if (IsKeyAppearsPreviosly(txtKeyVal.GetKey(), dataDict, dataDict.size()))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//const bool SymbolsDataValidator::IsValLablesKeyInDictionary(const Key& a_key) const
//{
//	const std::vector<KeyVal>& txtDict = this->m_untrusted_symbolsData.m_dictionaryTXT;
//	const std::vector<KeyVal>& dataDict = this->m_untrusted_symbolsData.m_dictionaryDATA;
//
//	return IsKeyAppearsPreviosly(a_key, txtDict, txtDict.size()) 
//		|| IsKeyAppearsPreviosly(a_key, dataDict, dataDict.size());
//}
//
//const bool SymbolsDataValidator::IsAllValLablesKeysInDictionaries() const
//{
//	const std::vector<ValLable>& valLables = this->m_untrusted_symbolsData.m_valLables;
//	for(ValLable valLable : valLables)
//	{
//		if(!IsValLablesKeyInDictionary(valLable.GetKey()))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//const bool SymbolsDataValidator::IsValidSymbolData() const
//{
//	return this->IsAllValLablesKeysInDictionaries() && this->IsDictionariesKeysAppearOnce();
//}
//
//}//experis
//
//
