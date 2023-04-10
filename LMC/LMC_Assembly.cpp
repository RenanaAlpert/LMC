#include <string>
#include <fstream>
#include "LMC_Assembly.h"
#include "ExtentionsHandler.h"
#include "from_trusted_Symbols.h"
#include "Commands.h"
#include "SymbolsValidator.h"

namespace experis
{
//const int m_argc;
//const char **m_argv;

LMC_Assembly::LMC_Assembly(const int a_argc, const char **a_argv)
	: m_argc{a_argc}
	, m_argv{a_argv}
{
	if(!IsValidArguments()) 
	{
		// THROW!!
	}
<<<<<<< Updated upstream
	else if(!IsCodeFileExists())
	{
		//THROW!!
	}
	else if(false)//!IsValidSymbols(Commands{}))
=======
	else if(!IsCodeFileExists)
	{
		//THROW!!
	}
	else if(!IsValidSymbols(Commands{}))
>>>>>>> Stashed changes
	{
		//THROW!!
	}
	else if(false)//valid machine code
	{
		//THROW!!
	}
	else
	{
		trusted_CreateSymbolFile();
		//CreateMachineCodeFile();
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
		SymbolsToFile(symbolsFilePath, from_trusted_Symbols(commands));*/
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

const bool LMC_Assembly::IsCodeFileExists() const
{
   std::ifstream infile;
   infile.open(*(this->m_argv + 2));
   if(infile) {
      return true;
   } else {
      return false;
   }
}

//const bool LMC_Assembly::IsCodeFileExists() const //TODO think again
//{
//}




}//experis



