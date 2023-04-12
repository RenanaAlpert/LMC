#pragma once

#include <exception>
#include <string>

namespace experis
{

struct MainArgumentsException : std::exception
{
    MainArgumentsException(const char *a_msg);
    const char *m_msg;
};

struct LineLablesException : std::exception
{
    LineLablesException(const char *a_msg, const std::string m_lineLable);
    const char *m_msg;
    const std::string m_lineLable;
};

struct AddressLableException : std::exception
{
    AddressLableException(const char *a_msg, const std::string a_addressLable);
    const char *m_msg;
    const std::string m_addressLable;
};


struct InputFileOpeningException : std::exception
{
    InputFileOpeningException(const char *a_msg, const std::string a_fileName);
    const char *m_msg;
    const std::string m_fileName;
};

struct SymbolsException : std::exception
{
};

struct IllegalInputException : std::exception
{
    IllegalInputException(const char *a_msg, const std::string a_command);
    const char *m_msg;
    const std::string m_command;
};

}//experis

