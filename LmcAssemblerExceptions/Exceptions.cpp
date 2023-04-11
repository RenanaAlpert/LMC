#include "pch.h"
#include "Exceptions.h"

namespace experis
{

MainArgumentsException::MainArgumentsException(const char *a_msg)
    : m_msg{a_msg}
{
}

}//experis
