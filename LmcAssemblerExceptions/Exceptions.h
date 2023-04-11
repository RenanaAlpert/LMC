#pragma once

#include <exception>

namespace experis
{

struct MainArgumentsException : std::exception
{
    MainArgumentsException(const char *a_msg);
    const char *m_msg;
};

struct InputFileOpeningException : std::exception
{
};

struct SymbolsException : std::exception
{
};

}//experis

