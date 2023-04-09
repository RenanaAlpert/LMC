#include <string>
#include "LMC_Assembly.h"
#include "ExtentionsHandler.h"
#include "from_trusted_Symbols.h"
#include "Commands.h"

namespace experis
{
//const int m_argc;
//const char **m_argv;

LMC_Assembly::LMC_Assembly(const int a_argc, const char **a_argv)
	: m_argc{a_argc}
	, m_argv{a_argv}
{
	if(true)//IsValidArguments() //IsCodeFileExists// && valid sym tbl && valid machine code
	{
		trusted_CreateSymbolFile();
		//CreateMachineCodeFile();
	}
	else
	{
		//show invalidation message! THROW!!
	}
}
LMC_Assembly::~LMC_Assembly()
{
}

void LMC_Assembly::trusted_CreateSymbolFile() const
{
	switch (this->m_argc)
	{
	case(2):
	{
		const std::string codeFilePath = *(this->m_argv + 1);
		const std::string newExtention = ".sym";
		const std::string symbolsFilePath = ChangeExtention(codeFilePath, newExtention);
		/*Commands commands{};
		SymbolsToFile(symbolsFilePath, from_trusted_Symbols());*/
	}
	default:
		break;
	}
}

//void LMC_Assembly::CreateMachineCodeFile() const
//{
//}

const bool LMC_Assembly::IsValidArguments() const //TODO think again
{
	switch (this->m_argc)
	{
	case 2:
	{
		return true;
	}
	case 3:
	{
		return *(this->m_argv + 2) == std::string("/bin");
	}
	case 4:
	{
		return true;
	}
	case 5:
	{
		return *(this->m_argv + 2) == std::string("/bin");
	}
	default:
		return false; //TODO throw
	}
}


//const bool LMC_Assembly::IsCodeFileExists() const //TODO think again
//{
//}




}//experis



