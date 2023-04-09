#include <iostream>
#include <optional>
#include "from_trusted_Symbols.h"



int main(int argc, const char **argv)
{
	experis::Cmds cmds;

	experis::Cmd cmd0(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"space"});
	experis::Cmd cmd1(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"char"});
	experis::Cmd cmd2(experis::CmdType::TXT, std::optional<std::string>{"loop"}, std::optional<std::string>{"char"});
	experis::Cmd cmd3(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{});
	experis::Cmd cmd4(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"one"});
	experis::Cmd cmd5(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"char"});
	experis::Cmd cmd6(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"max"});
	experis::Cmd cmd7(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"end"});
	experis::Cmd cmd8(experis::CmdType::TXT, std::optional<std::string>{}, std::optional<std::string>{"loop"});
	experis::Cmd cmd9(experis::CmdType::TXT, std::optional<std::string>{"end"}, std::optional<std::string>{});
	experis::Cmd cmd10(experis::CmdType::DATA, std::optional<std::string>{"space"}, std::optional<std::string>{});
	experis::Cmd cmd11(experis::CmdType::DATA, std::optional<std::string>{"one"}, std::optional<std::string>{});
	experis::Cmd cmd12(experis::CmdType::DATA, std::optional<std::string>{"max"}, std::optional<std::string>{});
	experis::Cmd cmd13(experis::CmdType::DATA, std::optional<std::string>{"char"}, std::optional<std::string>{});

	cmds.AddCmd(cmd0);
	cmds.AddCmd(cmd1);
	cmds.AddCmd(cmd2);
	cmds.AddCmd(cmd3);
	cmds.AddCmd(cmd4);
	cmds.AddCmd(cmd5);
	cmds.AddCmd(cmd6);
	cmds.AddCmd(cmd7);
	cmds.AddCmd(cmd8);
	cmds.AddCmd(cmd9);
	cmds.AddCmd(cmd10);
	cmds.AddCmd(cmd11);
	cmds.AddCmd(cmd12);
	cmds.AddCmd(cmd13);

	experis::from_trusted_Symbols symbolTable = experis::from_trusted_Symbols(cmds);
	std::cout << symbolTable;

	experis::Key key = "loop";
	std::optional<experis::Val> optnlVal = symbolTable.GetVal(key);
	if (optnlVal.has_value())
	{
		std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	}
	else
	{
		std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	}

	key = "one";
	optnlVal = symbolTable.GetVal(key);
	if (optnlVal.has_value())
	{
		std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	}
	else
	{
		std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	}

	key = "two";
	optnlVal = symbolTable.GetVal(key);
	if (optnlVal.has_value())
	{
		std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	}
	else
	{
		std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	}

	key = "char";
	optnlVal = symbolTable.GetVal(key);
	if (optnlVal.has_value())
	{
		std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	}
	else
	{
		std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	}

	const std::string& outFileName = "First.sym";
	experis::SymbolsToFile(outFileName, symbolTable);




	// ------------------------------------------FROM RANANA--------------------------------------------------------------------------------//
	//for(i = 0; i < NumOfCmds ; ++i) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
	//                                                                                                                                      //
	//lablKeye = Commans.At(i).GetLable() ==> optional<Key> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
	//keyVal = lablKeye.has_value() ? std::optional<experis::KeyVal>{KeyVal{lablKeye.value(), i}} : std::optional<experis::KeyVal>{};       //
	//                                                                                                                                      //
	//adressKey = Commans.At(i).GetAdress() ==> optional<Key> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
	//valLable = adressKey.has_value() ? std::optional<experis::ValLable>{KeyVal{adressKey.value(), i}} : std::optional<experis::KeyVal>{}; //
	// -------------------------------------------------------------------------------------------------------------------------------------//
	// experis::OpLineLables opLineLables{keyVal, valLable};                                                                                //
	// -------------------------------------------------------------------------------------------------------------------------------------//



	// ------------------------------------------TO RANANA--------------------------------------------------------------------------------//
	// optional LableValue(key)

	//========================================ACCHIEVED====================================================================================//
	/*OUTPUT = > 
	=2
	@8

	TXT
	:end
	=9
	@7

	DATA
	:space
	=10
	@0

	DATA
	:one
	=11
	@4

	DATA
	:max
	=12
	@6

	DATA
	:char
	=13
	@1
	@2
	@5

	*/



//========================================DONT FORGET====================================================================================//
	//THINK:
	// - flag?? - do we have untrusted/trusted/any symbolData at all?
	// - check valid file.
	// - asserts.
	// - throw.
	// - TESTS!!!
}
