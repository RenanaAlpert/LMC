#pragma once
#include <vector>
#include "Using.h"

namespace experis
{

class LMC_Assembly
{

public:
	explicit LMC_Assembly() = delete;
	explicit LMC_Assembly(const int a_argc, const char **a_argv);
	LMC_Assembly(const LMC_Assembly& a_LMC_assembly) = delete; 
	LMC_Assembly& operator=(const LMC_Assembly& a_LMC_assembly) = delete; 
	~LMC_Assembly();

private:
	void ArgumentsValidation() const;
	//const bool IsValidArguments() const;
	void InputCodeFileExistenceCheck() const;
	//const bool IsCodeFileExists() const;

	const std::string GetInputCodeFilePath() const;
	const std::string GetOutputSymbolFilePath() const;
	const std::string GetOutputMachinCodeFilePath() const;

	void CreateSymbolFile() const;
	void CreateMachineCodeFile() const;

	const int m_argc;
	const char **m_argv;
};

std::vector<std::string> ReadFromFile(const std::string& a_fileName);
void WriteNumsToFile(const std::string& a_output, const std::vector<MechinLanguage>& a_writeToFile);
void WriteNumToBinary(const std::string& a_output, const std::vector<MechinLanguage>& a_writeToFile);

//Unreal!! - Just for tests
std::ostream& operator<<(std::ostream& a_os, const LMC_Assembly& a_LMC_Assembly);

}//experis












	//void trusted_CreateSymbolFile() const; //TODO asset sucsess
	//void ArgumentsValidation();
	//void InputCodeFileExistenceCheck();


