#pragma once
#include <string>
#include <vector>

namespace experis
{

class CommandToNumber
{
public:
	explicit CommandToNumber() = delete;
	explicit CommandToNumber(const std::string& a_Txt, size_t a_opcode);
	CommandToNumber(const CommandToNumber& a_other);
	CommandToNumber& operator=(const CommandToNumber& a_other) = delete;
	~CommandToNumber() = default;

	std::string GetTxtCmd() const;
	size_t GetOpcode() const;

private:
	std::string m_txtCmd;
	size_t m_opcode;
};

} // experis