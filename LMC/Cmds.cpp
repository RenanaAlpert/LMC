//#include <cassert>
//#include "Cmds.h"
//
//namespace experis
//{
//
//Cmds::Cmds()
//	: m_commands{}
//{
//}
//
//Cmds::Cmds(const Cmds& a_cmds)
//	: m_commands{a_cmds.m_commands}
//{
//}
//
//Cmds::~Cmds()
//{
//}
//
//const Cmd& Cmds::GetCommand(size_t a_ind) const
//{
//	return this->m_commands.at(a_ind);
//}
//
//void Cmds::AddCmd(Cmd a_cmd)
//{
//	this->m_commands.push_back(a_cmd);
//}
//
//const size_t Cmds::GetLinesNumber() const
//{
//	return this->m_commands.size();
//}
//
//const Cmd& Cmds::At(size_t a_idx) const
//{
//	assert(a_idx < this->m_commands.size());
//	return this->m_commands.at(a_idx);
//}
//
//}//experis
//	 
//	
//
