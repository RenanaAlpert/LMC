#include <iostream>
#include <optional>
//#include "from_trusted_Symbols.h"
#include "LMC_Assembly.h"


int main(int argc, const char **argv)
{
	
	//experis::Commands commands("samplAsm1.txt");
	//experis::from_trusted_Symbols symbolTable = experis::from_trusted_Symbols(commands);
	///*std::cout << symbolTable;

	//experis::Key key = "loop";
	//std::optional<experis::Val> optnlVal = symbolTable.GetVal(key);
	//if (optnlVal.has_value())
	//{
	//	std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	//}
	//else
	//{
	//	std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	//}

	//key = "one";
	//optnlVal = symbolTable.GetVal(key);
	//if (optnlVal.has_value())
	//{
	//	std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	//}
	//else
	//{
	//	std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	//}

	//key = "two";
	//optnlVal = symbolTable.GetVal(key);
	//if (optnlVal.has_value())
	//{
	//	std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	//}
	//else
	//{
	//	std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	//}

	//key = "char";
	//optnlVal = symbolTable.GetVal(key);
	//if (optnlVal.has_value())
	//{
	//	std::cout << "Key = "<< key <<" ::: Val = " << symbolTable.GetVal(key).value() << std::endl;
	//}
	//else
	//{
	//	std::cout << "Key = "<< key <<" ::: does not exist in cmds " << std::endl;
	//}*/
	//const std::string& outFileName = "First.sym";
	//experis::SymbolsToFile(outFileName, symbolTable);

	/*std::cout << argc << std::endl;
	std::cout << *argv << std::endl;
	std::cout << *(argv+1) << std::endl;*/

	/*char **myArgv = new char*[2];
	char *firstArg = new char[]{"LMC.exe"};
	char *secArg = new char[]{"inputCode0.txt"};
	*myArgv = firstArg;
	*(myArgv +1) = secArg;*/

	//const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"C:\\Users\\IMOE001\\Desktop\\inputCode0.txt"}};

	//std::cout << *myArgv << std::endl;
	//std::cout << *(myArgv+1) << std::endl;

	//int myArc = 2;

	//experis::LMC_Assembly(myArc,myArgv);
	experis::LMC_Assembly(argc,argv);



















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
	// - TE//STS!!!
}
