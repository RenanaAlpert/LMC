#pragma once

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
	//const bool IsCodeFileExists() const;
	//void CreateMachineCodeFile() const; //TODO asset sucsess

	const int m_argc;
	const char **m_argv;
};

}//experis




