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
};

struct SymbolsException : std::exception
{
};

}//experis

