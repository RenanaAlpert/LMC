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
			const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"FilesTest\\FilesTest1\\inputCode0.txt"}};
			int myArc = 2;
			experis::LMC_Assembly(myArc,myArgv);
			//std::string expecetSymFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\expected_inputCode0.sym";
			std::string expecetSymFileName = "FilesTest\\FilesTest1\\expected_inputCode0.sym";
			//std::string expecetMachCodeFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\expected_inputCode0.lmc";
			std::string expecetMachCodeFileName = "FilesTest\\FilesTest1\\expected_inputCode0.lmc";
			//std::string actualSymFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\inputCode0.sym";
			std::string actualSymFileName = "FilesTest\\FilesTest1\\inputCode0.sym";
			//std::string actualMachCodeFileName = "C:\\Users\\IMOE001\\Desktop\\test0\\inputCode0.lmc";
			std::string actualMachCodeFileName = "FilesTest\\FilesTest1\\inputCode0.lmc";
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

			//TODO release memory!!

		}
		TEST_METHOD(TestMethod2)
		{
			const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"FilesTest\\FilesTest2\\inputCode0.txt"}, new const char[]{"/bin"}};
			int myArc = 3;
			experis::LMC_Assembly(myArc,myArgv);
			std::string expecetSymFileName = "FilesTest\\FilesTest2\\expected_inputCode0.sym";
			//RANANA====> create expected bin that you have checked by hand
			//std::string expecetMachCodeFileName = "FilesTest\\FilesTest2\\expected_inputCode0.bin";
			std::string actualSymFileName = "FilesTest\\FilesTest2\\inputCode0.sym";
			//std::string actualMachCodeFileName = "FilesTest\\FilesTest2\\inputCode0.bin";
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


			//RENANA================> Compare in binary
			/*std::ifstream expectedMchCod;
			expectedMchCod.open(expecetMachCodeFileName, std::ios::);
			std::ifstream actualMchCod;
			actualMchCod.open(actualMachCodeFileName, std::ios::);

			while(!expectedMchCod.eof() && !actualMchCod.eof())
			{
				std::getline(expectedMchCod, expectedLine);
				std::getline(actualMchCod, actualLine);
				TEST::Assert::AreEqual(expectedLine,actualLine);
			}
			TEST::Assert::IsTrue(expectedMchCod.eof() && actualMchCod.eof());*/

			//TODO release memory!!

		}
		TEST_METHOD(TestMethod3)
		{
			const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"FilesTest\\FilesTest3\\inputCode0.txt"}, new const char[]{"FilesTest\\FilesTest3\\MC0"}, new const char[]{"FilesTest\\FilesTest3\\SYM0"}};
			int myArc = 4;
			experis::LMC_Assembly(myArc,myArgv);
			std::string expecetSymFileName = "FilesTest\\FilesTest3\\expected_inputCode0.sym";
			std::string expecetMachCodeFileName = "FilesTest\\FilesTest3\\expected_inputCode0.lmc";
			std::string actualSymFileName = "FilesTest\\FilesTest3\\SYM0";
			std::string actualMachCodeFileName = "FilesTest\\FilesTest3\\MC0";
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

			//TODO release memory!!

		}
		TEST_METHOD(TestMethod4)
		{
			const char **myArgv = new const char*[]{new const char[]{"LMC.exe"},new const char[]{"FilesTest\\FilesTest4\\inputCode0.txt"},new const char[]{"/bin"}, new const char[]{"FilesTest\\FilesTest4\\MC0"}, new const char[]{"FilesTest\\FilesTest4\\SYM0"}};
			int myArc = 5;
			experis::LMC_Assembly(myArc,myArgv);
			std::string expecetSymFileName = "FilesTest\\FilesTest4\\expected_inputCode0.sym";
			//RANANA=====> insert manually the expected bunary file
			//std::string expecetMachCodeFileName = "FilesTest\\FilesTest4\\expected_inputCode0.bin";
			std::string actualSymFileName = "FilesTest\\FilesTest4\\SYM0";
			//std::string actualMachCodeFileName = "FilesTest\\FilesTest4\\MC0";
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


			//RANANA============> Here....
			/*std::ifstream expectedMchCod;
			expectedMchCod.open(expecetMachCodeFileName, std::ios::in);
			std::ifstream actualMchCod;
			actualMchCod.open(actualMachCodeFileName, std::ios::in);

			while(!expectedMchCod.eof() && !actualMchCod.eof())
			{
				std::getline(expectedMchCod, expectedLine);
				std::getline(actualMchCod, actualLine);
				TEST::Assert::AreEqual(expectedLine,actualLine);
			}
			TEST::Assert::IsTrue(expectedMchCod.eof() && actualMchCod.eof());*/

			//TODO release memory!!

		}
	};
}
