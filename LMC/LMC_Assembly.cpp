#include <string>
#include <fstream>
#include <cassert>
#include "LMC_Assembly.h"
#include "ExtentionsHandler.h"
#include "from_trusted_Symbols.h"
#include "Commands.h"
#include "SymbolsValidator.h"

namespace experis
{

LMC_Assembly::LMC_Assembly(const int a_argc, const char **a_argv)
	: m_argc{a_argc}
	, m_argv{a_argv}
{
	if(!IsValidArguments()) 
	{
		// THROW!!
	}

	if(!IsCodeFileExists())
	{
		//THROW!!
	}

	const std::string codeFilePath = *(this->m_argv + 1);	
	if(!IsValidSymbols(Commands(codeFilePath)))
	{
		//THROW!!
	}

	//if(false)//!valid machine code <==================================RENANA
	//{
	//	//THROW!!
	//}


	trusted_CreateSymbolFile();
	//CreateMachineCodeFile(); <==========================================RENANA
}

LMC_Assembly::~LMC_Assembly()
{
}

void LMC_Assembly::trusted_CreateSymbolFile() const
{
	const std::string inputCodeFilePath = *(this->m_argv + 1);

	std::string outputSymbolFilePath{};
	switch (this->m_argc)
	{
	case 2 || 3:
	{
		outputSymbolFilePath = ChangeExtention(inputCodeFilePath, ".sym");
	}
	case 4:
	{
		outputSymbolFilePath = *(this->m_argv + 3);
	}
	case 5:
	{
		outputSymbolFilePath = *(this->m_argv + 4);
	}
	default:
		assert(true); 
	}
	SymbolsToFile(outputSymbolFilePath, from_trusted_Symbols(Commands(inputCodeFilePath)));
}

//void LMC_Assembly::CreateMachineCodeFile() const //<=====================================RENANA
//{
//  const std::string inputCodeFilePath = *(this->m_argv + 1);
//
//	std::string outputMachineCodeFilePath{};
// 	switch (this->m_argc) 
//	{
//	case 2:
//	{
//		outputMachineCodeFilePath = ChangeExtention(inputCodeFilePath, ".lmc");
//		// create TEXT file with the name outputMachineCodeFilePath
//	}
//	case 3:
//	{
//		outputMachineCodeFilePath = ChangeExtention(inputCodeFilePath, ".bin");
//		// create BIN file with the name outputMachineCodeFilePath
//	}
//	case 4: 
//	{
//		outputMachineCodeFilePath = *(this->m_argv + 3);
//		// create TEXT file with the name outputMachineCodeFilePath
//	}
// case 5: 
//	{
//		outputMachineCodeFilePath = *(this->m_argv + 4);
//		// create BIN file with the name outputMachineCodeFilePath
//	}
//	default:
//		assert(); //programming bug. should not get here because it was checked in the constructor
//	}
// 
//}

const bool LMC_Assembly::IsValidArguments() const
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
		return false;
	}
}

const bool LMC_Assembly::IsCodeFileExists() const
{
   std::ifstream infile;
   infile.open(*(this->m_argv + 2));
   if(infile.is_open()) 
   {
	   infile.close();
       return true;
   } else 
   {
       return false;
   }
}


}//experis



