#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "CommandText.h"
#include "Commands.h"
#include "AssemblyToBinary.h"
#include "Using.h"
#include <optional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAssemblyToBinary
{
	TEST_CLASS(TestAssemblyToBinary)
	{
	public:
		
		std::vector<std::string> v{"        lda space", "        sta char", "loop    lda char", "        otc", "        add one", "        sta char", "        sub max", "        brz end", "        bra loop", "end     hlt", "space   dat 32", "one     dat 1", "max     dat 127", "char    dat"};
		experis::Commands cmds{v};

		TEST_METHOD(TestConvertToBinary)
		{
			std::vector<experis::MechinLanguage> machineCode = experis::TxtToBinary(v);

			experis::MechinLanguage toEq = 510;
			Assert::AreEqual(toEq, machineCode.at(0));

			toEq = 313;
			Assert::AreEqual(toEq, machineCode.at(1));

			toEq = 513;
			Assert::AreEqual(toEq, machineCode.at(2));

			toEq = 922;
			Assert::AreEqual(toEq, machineCode.at(3));

			toEq = 111;
			Assert::AreEqual(toEq, machineCode.at(4));

			toEq = 313;
			Assert::AreEqual(toEq, machineCode.at(5));

			toEq = 212;
			Assert::AreEqual(toEq, machineCode.at(6));

			toEq = 709;
			Assert::AreEqual(toEq, machineCode.at(7));

			toEq = 602;
			Assert::AreEqual(toEq, machineCode.at(8));

			toEq = 0;
			Assert::AreEqual(toEq, machineCode.at(9));

			toEq = 32;
			Assert::AreEqual(toEq, machineCode.at(10));

			toEq = 1;
			Assert::AreEqual(toEq, machineCode.at(11));

			toEq = 127;
			Assert::AreEqual(toEq, machineCode.at(12));

			toEq = 0;
			Assert::AreEqual(toEq, machineCode.at(13));
		}
	};
}
