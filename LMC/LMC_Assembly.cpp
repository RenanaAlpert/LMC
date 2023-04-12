#include <string>
#include <fstream>
#include <cassert>
#include <iostream>

#include "ExtentionsHandler.h"
#include "Symbols.h"
#include "Commands.h"
#include "HandyFuncs.h"
#include "Exceptions.h"
#include "AssemblyToBinary.h"

#include "LMC_Assembly.h"

namespace experis
{

LMC_Assembly::LMC_Assembly(const int a_argc, const char **a_argv)
	: m_argc{a_argc}
	, m_argv{a_argv}
{
	ArgumentsValidation();
	InputCodeFileExistenceCheck();

	CreateSymbolFile();
	CreateMachineCodeFile();
}

LMC_Assembly::~LMC_Assembly()
{
}

void LMC_Assembly::CreateSymbolFile() const
{
	const std::string inputCodeFilePath = GetInputCodeFilePath();
	const std::string outputSymbolFilePath = GetOutputSymbolFilePath();

	SymbolsToFile(outputSymbolFilePath, Symbols(Commands(inputCodeFilePath)));
}

void LMC_Assembly::CreateMachineCodeFile() const 
{
	assert(this->m_argc >= 2 && this->m_argc <=5);

	const std::string inputCodeFilePath = GetInputCodeFilePath();
	const std::string outputMachinCodeFilePath = GetOutputMachinCodeFilePath();
 
	std::vector<std::string> input = ReadFromFile(inputCodeFilePath);
	std::vector<MechinLanguage> output = TxtToBinary(input);

	if(this->m_argc == 2 || this->m_argc == 4)
	{
		WriteNumsToFile(outputMachinCodeFilePath, output);
		std::cout << "Wrote nums to file\n";
	}
	else if(this->m_argc == 3 || this->m_argc == 5)
	{	
		WriteNumToBinary(outputMachinCodeFilePath, output);
		std::cout << "Wrote nums to binary\n";
	}
	return;
}

const std::string LMC_Assembly::GetInputCodeFilePath() const
{
	return *(this->m_argv + 1);
}

const std::string LMC_Assembly::GetOutputSymbolFilePath() const
{
	assert(this->m_argc >= 2 && this->m_argc <=5);

	const std::string inputCodeFilePath = GetInputCodeFilePath();

	if (this->m_argc == 2 || this->m_argc == 3)
	{
		return ChangeExtention(inputCodeFilePath, ".sym");
	}

	if (this->m_argc == 4)
	{
		return *(this->m_argv + 3);
	}

	if (this->m_argc == 5)
	{
		return *(this->m_argv + 4);
	}	
}

const std::string LMC_Assembly::GetOutputMachinCodeFilePath() const
{
	assert(this->m_argc >= 2 && this->m_argc <=5);

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
		return *(this->m_argv + 2);
	}
	case 5: 
	{
		return *(this->m_argv + 3);
	}
	default:
	{
		assert(true);
	}
	}
}

void LMC_Assembly::ArgumentsValidation()  const
{
	switch (this->m_argc)
	{
	case 2:
	{
		break;
	}
	case 3:
	{
		if (*(this->m_argv + 2) != std::string("/bin"))
		{
			MainArgumentsException error{"Second input argument is not \"/bin\" !!! "};
			throw error;
		}
		break;
	}
	case 4:
	{
		break;
	}
	case 5:
	{
		if (*(this->m_argv + 2) != std::string("/bin"))
		{
			MainArgumentsException error{"Second input argument is not \"/bin\" !!! "};
			throw error;
		}
		break;
	}
	default:
		MainArgumentsException error{"Invalid number of input arguments !!! "};
		throw error;
		break;
	}
}

void LMC_Assembly::InputCodeFileExistenceCheck() const
{
   const std::string inputCodeFilePath = GetInputCodeFilePath();
   std::ifstream infile(inputCodeFilePath);
   if(infile.is_open()) 
   {
	   infile.close();
   } 
   else 
   {
		throw InputFileOpeningException{};
   }
}

//RANANA==============> confirm changes
std::vector<std::string> ReadFromFile(const std::string& a_fileName)
{
	std::ifstream file{a_fileName};
	std::string untrusrt_line{};
	std::vector<std::string> commandsInFile{};
	while (!file.eof() && file.good())
	{
		std::getline(file, untrusrt_line);
		//if(!file.good())// || file.eof())
		//{
		//	break;
		//}
		commandsInFile.push_back(untrusrt_line);
	}
	return commandsInFile;
}

//RANANA==============> confirm changes and do throw
void WriteNumsToFile(const std::string& a_output, const std::vector<MechinLanguage>& a_writeToFile)
{
	std::ofstream outfile{a_output};
	if(!outfile.is_open())
	{
		// TODO throw
	}
	for (MechinLanguage cmd : a_writeToFile)
	{
		/*if(cmd < 10)
		{
			outfile << "00" << cmd << "\n";
		}
		else if (cmd >=10 && cmd < 100)
		{
			outfile << "0" << cmd << "\n";
		}
		else
		{
			outfile << cmd << "\n";
		}*/
		if(cmd < 10)
		{
			int i =0;
			outfile << i << i << cmd << "\n";
		}
		else if (cmd >=10 && cmd < 100)
		{
			int i =0;
			outfile << i << cmd << "\n";
		}
		else
		{
			outfile << cmd << "\n";
		}
	}
	outfile.close();
}

void WriteNumToBinary(const std::string& a_output, const std::vector<MechinLanguage>& a_writeToFile)
{
	std::ofstream file{a_output, std::ios::binary};
	for (MechinLanguage cmd : a_writeToFile)
	{
		file.put(char(cmd / 100));
		file.put(char(cmd % 100));
	}
	file.close();
}

//Unreal function - just for tests
std::ostream& operator<<(std::ostream& a_os, const LMC_Assembly& a_LMC_Assembly)
{
	a_os << "ficted for tests ::: std::ostream& operator<<(std::ostream& a_os, const LMC_Assembly& a_LMC_Assembly)\n";
	return a_os;
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