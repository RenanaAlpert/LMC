#pragma once
#include <string>
#include <vector>
#include "CommandText.h"
#include "LMC_Defenitions.h"

namespace experis
{

class Commands
{
public:
	explicit Commands();
	//explicit Commands(std::initializer_list<std::string> a_listCommands);
	explicit Commands(std::vector<std::string> a_listCommands);
	explicit Commands(const std::string& a_codeFilePath);
	Commands(const Commands& a_other) = delete;
	Commands& operator=(const Commands& a_other) = delete;
	~Commands();

	std::optional<Key> GetLable(size_t a_index) const;
	std::optional<Key> GetOpcode(size_t a_index) const;
	std::optional<Key> GetAddress(size_t a_index) const;
	CmdSegment GetSegment(size_t a_index) const;
	size_t Size() const;

private:
	void PushBack(std::string& a_newItem);

	std::vector<CommandText*> m_commandsList;
};

}
