#pragma once

#include <optional>
#include <string>

namespace experis
{

namespace inner
{
	//TODO think about non-exeptable cases of a_codeFilePath
	std::Key RemoveExtention(const std::Key& a_codeFilePath);

	//TODO think about un-valid argument cases
	std::Key& AddExtention(std::Key&  a_codeFilePath, const std::Key& a_newExtention);

}//inner
 
const std::Key ChangeExtention(const std::Key& a_codeFilePath, const std::Key& a_newExtention);

}//experis
