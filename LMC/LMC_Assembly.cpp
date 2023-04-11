#include <string>
#include <fstream>
#include <cassert>
#include "LMC_Assembly.h"
#include "ExtentionsHandler.h"
#include "from_trusted_Symbols.h"
#include "Commands.h"
#include "SymbolsValidator.h"
#include "Exceptions.h"

namespace experis
{

LMC_Assembly::LMC_Assembly(const int a_argc, const char **a_argv)
	: m_argc{a_argc}
	, m_argv{a_argv}
{
	ArgumentsValidation();
	InputCodeFileExistenceCheck();
	if(!IsValidSymbols(Commands(GetInputCodeFilePath())))
	{
		throw SymbolsException{};
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
	const std::string inputCodeFilePath = GetInputCodeFilePath();
	const std::string outputSymbolFilePath = GetOutputSymbolFilePath();

	SymbolsToFile(outputSymbolFilePath, from_trusted_Symbols(Commands(inputCodeFilePath)));
}

//void LMC_Assembly::CreateMachineCodeFile() const //<=====================================RENANA
//{
//  const std::string inputCodeFilePath = GetInputCodeFilePath();
//	const std::string outputMachinCodeFilePath = GetOutputMachinCodeFilePath();
// 
// 	switch (this->m_argc) 
//	{
//	case 2 || 4:
//	{
//		// create from inputCodeFilePath a TEXT file with the name outputMachinCodeFilePath // <=====RENENA
//	}
//	case 3 || 5:
//	{
//		// create from inputCodeFilePath a BIN file with the name outputMachinCodeFilePath // <=====RENENA
//	}
//	default:
//		assert(true); //programming bug. should not get here because it was checked in the constructor
//	}
//}

const std::string LMC_Assembly::GetInputCodeFilePath() const
{
	return *(this->m_argv + 1);
}

const std::string LMC_Assembly::GetOutputSymbolFilePath() const
{
	const std::string inputCodeFilePath = GetInputCodeFilePath();

	switch (this->m_argc)
	{
	case 2 || 3:
	{
		return ChangeExtention(inputCodeFilePath, ".sym");
	}
	case 4:
	{
		return *(this->m_argv + 3);
	}
	case 5:
	{
		return *(this->m_argv + 4);
	}
	default:
		assert(true); 
	}
}

const std::string LMC_Assembly::GetOutputMachinCodeFilePath() const
{
	assert(this->m_argc == 2 || this->m_argc == 3 || this->m_argc == 4 || this->m_argc == 5);

	const std::string inputCodeFilePath = GetInputCodeFilePath();

	switch (this->m_argc) 
	{
	case 2:
	{
		return ChangeExtention(inputCodeFilePath, ".lmc");
	}
	case 3:
	{
		return ChangeExtention(inputCodeFilePath, ".bin");
	}
	case 4: 
	{
		return *(this->m_argv + 3);
	}
	case 5: 
	{
		return *(this->m_argv + 4);
	}
	default:
	{
		assert(true);
	}
	}
}

void LMC_Assembly::ArgumentsValidation() 
{
	switch (this->m_argc)
	{
	case 2:
	{
		break;
	}
	case 3 || 5:
	{
		if (*(this->m_argv + 2) != std::string("/bin"))
		{
			MainArgumentsException error{"Second input argument is not \"/bin\" !!! "};
			throw error;
		}
	}
	case 4:
	{
		break;
	}
	default:
		MainArgumentsException error{"Invalid number of input arguments !!! "};
		throw error;
	}
}

void LMC_Assembly::InputCodeFileExistenceCheck()
{
   std::ifstream infile;
   infile.open(*(this->m_argv + 2));
   if(infile.is_open()) 
   {
	   infile.close();
   } 
   else 
   {
		throw InputFileOpeningException{};
   }
}


}//experis








//const bool LMC_Assembly::IsValidArguments() const
//{
//	switch (this->m_argc)
//	{
//	case 2:
//	{
//		return true;
//	}
//	case 3:
//	{
//		return *(this->m_argv + 2) == std::string("/bin");
//
//	}
//	case 4:
//	{
//		return true;
//	}
//	case 5:
//	{
//		return *(this->m_argv + 2) == std::string("/bin");
//	}
//	default:
//		return false;
//	}
//}

//const bool LMC_Assembly::IsCodeFileExists() const
//{
//   std::ifstream infile;
//   infile.open(*(this->m_argv + 2));
//   if(infile.is_open()) 
//   {
//	   infile.close();
//       return true;
//   } else 
//   {
//       return false;
//   }
//}