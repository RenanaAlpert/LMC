#include "pch.h"
#include "Exceptions.h"

namespace experis
{

MainArgumentsException::MainArgumentsException(const char *a_msg)
    : m_msg{a_msg}
{
}

LineLablesException::LineLablesException(const char *a_msg, const std::string a_lineLable)
    : m_msg{a_msg}
    , m_lineLable{a_lineLable}
{
}

AddressLableException::AddressLableException(const char *a_msg, const std::string a_addressLable)
    : m_msg{a_msg}
    , m_addressLable{a_addressLable}
{
}

}//experis
