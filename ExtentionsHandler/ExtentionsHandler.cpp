// ExtentionsHandler.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "ExtentionsHandler.h"
#include <iterator>

namespace experis
{

//TODO think about non-exeptable cases of a_codeFilePath
std::string inner::RemoveExtention(const std::string& a_codeFilePath)
{
	std::string codeFilePath = a_codeFilePath;

	for (; !codeFilePath.empty(); )
	{
		if (codeFilePath.back() == '.')
		{
			codeFilePath.pop_back();
			return codeFilePath;
		}
		codeFilePath.pop_back();
	}
	return codeFilePath;
}


//TODO think about un-valid argument cases
std::string& inner::AddExtention(std::string&  a_codeFilePath, const std::string& a_newExtention)
{
	a_codeFilePath += a_newExtention;
	return a_codeFilePath;
}

 
const std::string ChangeExtention(const std::string& a_codeFilePath, const std::string& a_newExtention)
{
	std::string noExntFtilePath = inner::RemoveExtention(a_codeFilePath);
	return inner::AddExtention(noExntFtilePath, a_newExtention);
}

}//experis
