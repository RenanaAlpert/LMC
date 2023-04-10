#pragma once

#include <optional>
#include <string>

namespace experis
{

namespace inner
{
	//TODO think about non-exeptable cases of a_codeFilePath
	std::string RemoveExtention(const std::string& a_codeFilePath);

	//TODO think about un-valid argument cases
	std::string& AddExtention(std::string&  a_codeFilePath, const std::string& a_newExtention);

}//inner
 
const std::string ChangeExtention(const std::string& a_codeFilePath, const std::string& a_newExtention);

}//experis
