//#pragma once
//
//#include <vector>
//#include "Cmd.h"
//
//namespace experis
//{
//class Cmds
//{
//public:
//
//	explicit Cmds();  
//	Cmds(const Cmds& a_cmds); 
//	Cmds& operator=(const Cmds& a_cmds) = delete; 
//	~Cmds();
//
//	const Cmd& GetCommand(size_t a_ind) const;
//	void AddCmd(Cmd a_cmd); //TODO assure success // const ref??
//	const size_t GetLinesNumber() const;
//	const Cmd& At(size_t a_idx) const;
//
//private:
//	std::vector<Cmd> m_commands;
//};
//}//experis
//
//
