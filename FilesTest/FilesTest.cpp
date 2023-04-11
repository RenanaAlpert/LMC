#include "pch.h"
#include "CppUnitTest.h"
#include "LMC_Assembly.h"
#include <iostream>
#include <fstream>

namespace TEST =  Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
namespace VisualStudio
{
namespace CppUnitTestFramework
{
std::wstring ToString(const experis::LMC_Assembly& a_LMC_Assembly)
{
	std::stringstream output;
	output << a_LMC_Assembly;
	const std::string gridAsAtring = output.str();
	return ToString(gridAsAtring);
}
}
}
}

namespace FilesTest
{
	TEST_CLASS(FilesTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"C:\\Users\\IMOE001\\Desktop\\test0\\inputCode0.txt"}};
			int myArc = 2;
			experis::LMC_Assembly(myArc,myArgv);
			std::string expecetSymFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\expected_inputCode0.sym";
			std::string expecetMachCodeFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\expected_inputCode0.lmc";
			std::string actualSymFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\inputCode0.sym";
			std::string actualMachCodeFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\inputCode0.lmc";
			experis::LMC_Assembly(myArc,myArgv);

			std::string expectedLine{};
			std::string actualLine{};

			std::ifstream expectedSym;
			expectedSym.open(expecetSymFileName, std::ios::in);
			std::ifstream actualSym;
			actualSym.open(actualSymFileName, std::ios::in);

			while(!expectedSym.eof() && !actualSym.eof())
			{
				std::getline(expectedSym, expectedLine);
				std::getline(actualSym, actualLine);
				TEST::Assert::AreEqual(expectedLine,actualLine);
			}
			TEST::Assert::IsTrue(expectedSym.eof() && actualSym.eof());



			std::ifstream expectedMchCod;
			expectedMchCod.open(expecetMachCodeFileName, std::ios::in);
			std::ifstream actualMchCod;
			actualMchCod.open(actualMachCodeFileName, std::ios::in);

			while(!expectedMchCod.eof() && !actualMchCod.eof())
			{
				std::getline(expectedMchCod, expectedLine);
				std::getline(actualMchCod, actualLine);
				TEST::Assert::AreEqual(expectedLine,actualLine);
			}
			TEST::Assert::IsTrue(expectedMchCod.eof() && actualMchCod.eof());

		}
	};
}
