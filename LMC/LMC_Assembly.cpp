#include <string>
#include "LMC_Assembly.h"
#include "ExtentionsHandler.h"

namespace experis
{
//const int m_argc;
//const char **m_argv;

LMC_Assembly::LMC_Assembly(const int a_argc, const char **a_argv)
	: m_argc{a_argc}
	, m_argv{a_argv}
{
	if(true)//IsValidArguments() &&  && valid sym tbl && valid machine code
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
	switch (m_argc)
	{
	case(2):
	{
		const std::string codeFilePath =* (m_argv + 1);
		const std::string newExtention = ".sym";
		const std::string symbolsFilePath = ChangeExtention(codeFilePath, newExtention);
	}
	default:
		break;
	}
}

//void LMC_Assembly::CreateMachineCodeFile() const
//{
//}

//IsValidArguments() 
//IsValidSourceFile())

}//experis




//void LMC_Assembly::SymbolsToFile( const std::string& a_outFileName, const Cmds& a_cmds)//,const bool a_isPrintToScreen, const bool a_isPrintToFile, const int a_int)
//{
//	
//	std::fstream fs{a_outFileName, std::ios::app};
//	if (! fs.is_open())
//	{
//		std::cout << "Failed to open file - " << a_filename << " for appending!!!" << std::endl;
//	}
//	else
//	{
//		fs << a_int;
//		fs.clear();
//		fs.close();
//	}
//	
//}