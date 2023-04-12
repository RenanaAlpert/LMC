#include <iostream>
#include <optional>
#include "LMC_Assembly.h"


//In Command Prompt:
//C:\Users\IMOE001\source\repos\LMC\x64\Debug>LMC.exe C:\Users\IMOE001\Desktop\inputCode0.txt

int main(int argc, const char **argv)
{
	/*const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"C:\\Users\\IMOE001\\Desktop\\inputCode0.txt"}};
	int myArc = 2;
	experis::LMC_Assembly(myArc,myArgv);*/

	experis::LMC_Assembly(argc,argv);


}//main





















//========================================DONT FORGET====================================================================================//
	//THINK:
	// - flag?? - do we have untrusted/trusted/any symbolData at all?
	// - check valid file.
	// - asserts.
	// - throw.
	// - TE//STS!!!