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
	void trusted_CreateSymbolFile() const; //TODO asset sucsess
	const bool IsValidArguments() const;
	const bool IsCodeFileExists() const;
	const std::string GetInputCodeFilePath() const;
	const std::string GetOutputSymbolFilePath() const;
	const std::string GetOutputMachinCodeFilePath() const;
	void ArgumentsValidation();
	void InputCodeFileExistenceCheck();
	void CreateMachineCodeFile() const;

	//void CreateMachineCodeFile() const; //TODO asset sucsess

	const int m_argc;
	const char **m_argv;
};

std::vector<std::string> ReadFromFile(const std::string& a_fileName);
void WriteNumsToFile(const std::string& a_output, const std::vector<MechinLanguage>& a_writeToFile);
void WriteNumToBinary(const std::string& a_output, const std::vector<MechinLanguage>& a_writeToFile);

//ficted for tests
std::ostream& operator<<(std::ostream& a_os, const LMC_Assembly& a_LMC_Assembly);

}//experis




