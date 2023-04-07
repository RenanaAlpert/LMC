#include <iostream>
#include "untrusted_SymbolsData.h"



int main()
{
	experis::untrusted_SymbolsData untrusted_symbolsData{};

	experis::ValLable valLable0{std::string("space"), 0};
	experis::OpLineLables opLineLables0{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable0}};
	untrusted_symbolsData.AddOpLineLables(opLineLables0);

	experis::ValLable valLable1{std::string("char"), 1};
	experis::OpLineLables opLineLables1{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable1}};
	untrusted_symbolsData.AddOpLineLables(opLineLables1);

	experis::KeyVal keyVal2{std::string("loop"), 2};
	experis::ValLable valLable2{std::string("char"), 2};
	experis::OpLineLables opLineLables2{std::optional<experis::KeyVal>{keyVal2}, std::optional<experis::ValLable>{valLable2}};
	untrusted_symbolsData.AddOpLineLables(opLineLables2);

	experis::OpLineLables opLineLables3{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{}};
	untrusted_symbolsData.AddOpLineLables(opLineLables3);

	experis::ValLable valLable4{std::string("one"), 4};
	experis::OpLineLables opLineLables4{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable4}};
	untrusted_symbolsData.AddOpLineLables(opLineLables4);

	experis::ValLable valLable5{std::string("char"), 5};
	experis::OpLineLables opLineLables5{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable5}};
	untrusted_symbolsData.AddOpLineLables(opLineLables5);

	experis::ValLable valLable6{std::string("max"), 6};
	experis::OpLineLables opLineLables6{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable6}};
	untrusted_symbolsData.AddOpLineLables(opLineLables6);

	experis::ValLable valLable7{std::string("end"), 7};
	experis::OpLineLables opLineLables7{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable7}};
	untrusted_symbolsData.AddOpLineLables(opLineLables7);

	experis::ValLable valLable8{std::string("loop"), 8};
	experis::OpLineLables opLineLables8{std::optional<experis::KeyVal>{}, std::optional<experis::ValLable>{valLable8}};
	untrusted_symbolsData.AddOpLineLables(opLineLables8);

	experis::KeyVal keyVal9{std::string("end"), 9};
	experis::OpLineLables opLineLables9{std::optional<experis::KeyVal>{keyVal9}, std::optional<experis::ValLable>{}};
	untrusted_symbolsData.AddOpLineLables(opLineLables9);

	std::cout << untrusted_symbolsData;



	//========================================ACCHIEVED====================================================================================//

	/* - OUTPUT - 
	------------------------------------
	====== Dictionary =======
	[Key: loop --- Val: 2]
	[Key: end --- Val: 9]

	====== ValLables =======
	[Key: space --- @Line#: 0]
	[Key: char --- @Line#: 1]
	[Key: char --- @Line#: 2]
	[Key: one --- @Line#: 4]
	[Key: char --- @Line#: 5]
	[Key: max --- @Line#: 6]
	[Key: end --- @Line#: 7]
	[Key: loop --- @Line#: 8]
	*/


	//========================================NEXT PHASE====================================================================================//

	/*TO RECEIVE NEXT OUTPUT!!
	-----------------------------------------------------------------------------------------------
	-----------------------------------------------------------------------------------------------
	====== @@@TEXT@@@ Dictionary =======          @@@ ====== DAT Dictionary =======@@@
	[Key: loop --- Val: 2]                        @@@[Key: loop --- Val: 2]        @@@
	[Key: end --- Val: 9]                         @@@[Key: end --- Val: 9]         @@@

	====== ValLables =======
	[Key: space --- @Line#: 0]
	[Key: char --- @Line#: 1]
	[Key: char --- @Line#: 2]
	[Key: one --- @Line#: 4]
	[Key: char --- @Line#: 5]
	[Key: max --- @Line#: 6]
	[Key: end --- @Line#: 7]
	[Key: loop --- @Line#: 8]
	*/


	//=================================QUESTIONS TO DISCUSS====================================================================================//

	//PHASE 3 -> to take ValLables and insert to TEXT dictionary and DAT Dictionary = = = SYMBOL TABLE
	//Will fail if untrusted is not valid

	// OR?????? TO devide into two mini phases: 3) checks validity + 4) creates SYMBOL TABLE from trusted symboldData 


//========================================DONT FORGET====================================================================================//
	//THINK:
	// - flag?? - do we have untrusted/trusted/any symbolData at all?
	// - check valid file.
	// - asserts.
	// - throw.
}
