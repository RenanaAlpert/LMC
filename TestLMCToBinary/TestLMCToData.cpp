#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "CommandText.h"
#include "Commands.h"
#include <optional>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLMCToData
{
	TEST_CLASS(TestLMCToData)
	{
	public:
		
		std::vector<std::string> v{"        lda space", "        sta char", "loop    lda char", "        otc", "        add one", "        sta char", "        sub max", "        brz end", "        bra loop", "end     hlt", "space   dat 32", "one     dat 1", "max     dat 127", "char    dat"};
		
		TEST_METHOD(TestCommandText3)
		{
			experis::CommandText c1{v.at(2)};

			Assert::IsTrue(c1.GetLable().has_value());
			std::string toCommper = "loop";
			Assert::AreEqual(toCommper, c1.GetLable().value());

			Assert::IsTrue(c1.GetOpcode().has_value());
			toCommper = "lda";
			Assert::AreEqual(toCommper, c1.GetOpcode().value());

			Assert::IsTrue(c1.GetAddress().has_value());
			toCommper = "char";
			Assert::AreEqual(toCommper, c1.GetAddress().value());
		}

		TEST_METHOD(TestCommandTextWithoutLable)
		{
			experis::CommandText c1{v.at(0)};

			Assert::IsFalse(c1.GetLable().has_value());

			Assert::IsTrue(c1.GetOpcode().has_value());
			std::string toCommper = "lda";
			Assert::AreEqual(toCommper, c1.GetOpcode().value());

			Assert::IsTrue(c1.GetAddress().has_value());
			toCommper = "space";
			Assert::AreEqual(toCommper, c1.GetAddress().value());
		}

		TEST_METHOD(TestCommandTextWithoutAddress)
		{
			experis::CommandText c1{v.at(v.size() - 1)};

			Assert::IsFalse(c1.GetAddress().has_value());
			
			Assert::IsTrue(c1.GetLable().has_value());
			std::string toCommper = "char";
			Assert::AreEqual(toCommper, c1.GetLable().value());
			
			Assert::IsTrue(c1.GetOpcode().has_value());
			toCommper = "dat";
			Assert::AreEqual(toCommper, c1.GetOpcode().value());
		}

		TEST_METHOD(TestCommandText1)
		{
			experis::CommandText c1{v.at(3)};

			Assert::IsFalse(c1.GetAddress().has_value());
			
			Assert::IsFalse(c1.GetLable().has_value());
			
			Assert::IsTrue(c1.GetOpcode().has_value());
			std::string toCommper = "otc";
			Assert::AreEqual(toCommper, c1.GetOpcode().value());
		}

		TEST_METHOD(TestCommands)
		{
			experis::Commands cmds{v};

			Assert::IsFalse(cmds.GetLable(0).has_value());
			Assert::IsTrue(cmds.GetOpcode(0).has_value());
			std::string toCommper = "lda";
			Assert::AreEqual(toCommper, cmds.GetOpcode(0).value());
			Assert::IsTrue(cmds.GetAddress(0).has_value());
			toCommper = "space";
			Assert::AreEqual(toCommper, cmds.GetAddress(0).value());

			Assert::IsFalse(cmds.GetLable(1).has_value());
			Assert::IsTrue(cmds.GetOpcode(1).has_value());
			toCommper = "sta";
			Assert::AreEqual(toCommper, cmds.GetOpcode(1).value());
			Assert::IsTrue(cmds.GetAddress(1).has_value());
			toCommper = "char";
			Assert::AreEqual(toCommper, cmds.GetAddress(1).value());

			Assert::IsTrue(cmds.GetLable(2).has_value());
			toCommper = "loop";
			Assert::AreEqual(toCommper, cmds.GetLable(2).value());
			Assert::IsTrue(cmds.GetOpcode(2).has_value());
			toCommper = "lda";
			Assert::AreEqual(toCommper, cmds.GetOpcode(2).value());
			Assert::IsTrue(cmds.GetAddress(2).has_value());
			toCommper = "char";
			Assert::AreEqual(toCommper, cmds.GetAddress(2).value());

			Assert::IsFalse(cmds.GetAddress(3).has_value());
			Assert::IsFalse(cmds.GetLable(3).has_value());
			Assert::IsTrue(cmds.GetOpcode(3).has_value());
			toCommper = "otc";
			Assert::AreEqual(toCommper, cmds.GetOpcode(3).value());

			Assert::IsFalse(cmds.GetLable(4).has_value());
			Assert::IsTrue(cmds.GetOpcode(4).has_value());
			toCommper = "add";
			Assert::AreEqual(toCommper, cmds.GetOpcode(4).value());
			Assert::IsTrue(cmds.GetAddress(4).has_value());
			toCommper = "one";
			Assert::AreEqual(toCommper, cmds.GetAddress(4).value());

			Assert::IsFalse(cmds.GetLable(5).has_value());
			Assert::IsTrue(cmds.GetOpcode(5).has_value());
			toCommper = "sta";
			Assert::AreEqual(toCommper, cmds.GetOpcode(5).value());
			Assert::IsTrue(cmds.GetAddress(5).has_value());
			toCommper = "char";
			Assert::AreEqual(toCommper, cmds.GetAddress(5).value());

			Assert::IsFalse(cmds.GetLable(6).has_value());
			Assert::IsTrue(cmds.GetOpcode(6).has_value());
			toCommper = "sub";
			Assert::AreEqual(toCommper, cmds.GetOpcode(6).value());
			Assert::IsTrue(cmds.GetAddress(6).has_value());
			toCommper = "max";
			Assert::AreEqual(toCommper, cmds.GetAddress(6).value());

			Assert::IsFalse(cmds.GetLable(7).has_value());
			Assert::IsTrue(cmds.GetOpcode(7).has_value());
			toCommper = "brz";
			Assert::AreEqual(toCommper, cmds.GetOpcode(7).value());
			Assert::IsTrue(cmds.GetAddress(7).has_value());
			toCommper = "end";
			Assert::AreEqual(toCommper, cmds.GetAddress(7).value());

			Assert::IsFalse(cmds.GetLable(8).has_value());
			Assert::IsTrue(cmds.GetOpcode(8).has_value());
			toCommper = "bra";
			Assert::AreEqual(toCommper, cmds.GetOpcode(8).value());
			Assert::IsTrue(cmds.GetAddress(8).has_value());
			toCommper = "loop";
			Assert::AreEqual(toCommper, cmds.GetAddress(8).value());

			Assert::IsFalse(cmds.GetAddress(9).has_value());
			Assert::IsTrue(cmds.GetLable(9).has_value());
			toCommper = "end";
			Assert::AreEqual(toCommper, cmds.GetLable(9).value());
			Assert::IsTrue(cmds.GetOpcode(9).has_value());
			toCommper = "hlt";
			Assert::AreEqual(toCommper, cmds.GetOpcode(9).value());

			Assert::IsTrue(cmds.GetLable(10).has_value());
			toCommper = "space";
			Assert::AreEqual(toCommper, cmds.GetLable(10).value());
			Assert::IsTrue(cmds.GetOpcode(10).has_value());
			toCommper = "dat";
			Assert::AreEqual(toCommper, cmds.GetOpcode(10).value());
			Assert::IsTrue(cmds.GetAddress(10).has_value());
			toCommper = "32";
			Assert::AreEqual(toCommper, cmds.GetAddress(10).value());

			Assert::IsTrue(cmds.GetLable(11).has_value());
			toCommper = "one";
			Assert::AreEqual(toCommper, cmds.GetLable(11).value());
			Assert::IsTrue(cmds.GetOpcode(11).has_value());
			toCommper = "dat";
			Assert::AreEqual(toCommper, cmds.GetOpcode(11).value());
			Assert::IsTrue(cmds.GetAddress(11).has_value());
			toCommper = "1";
			Assert::AreEqual(toCommper, cmds.GetAddress(11).value());

			Assert::IsTrue(cmds.GetLable(12).has_value());
			toCommper = "max";
			Assert::AreEqual(toCommper, cmds.GetLable(12).value());
			Assert::IsTrue(cmds.GetOpcode(12).has_value());
			toCommper = "dat";
			Assert::AreEqual(toCommper, cmds.GetOpcode(12).value());
			Assert::IsTrue(cmds.GetAddress(12).has_value());
			toCommper = "127";
			Assert::AreEqual(toCommper, cmds.GetAddress(12).value());

			Assert::IsFalse(cmds.GetAddress(13).has_value());
			Assert::IsTrue(cmds.GetLable(13).has_value());
			toCommper = "char";
			Assert::AreEqual(toCommper, cmds.GetLable(13).value());
			Assert::IsTrue(cmds.GetOpcode(13).has_value());
			toCommper = "dat";
			Assert::AreEqual(toCommper, cmds.GetOpcode(13).value());
		}
	};
}
