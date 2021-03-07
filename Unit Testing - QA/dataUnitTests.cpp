#include "pch.h"
#include "CppUnitTest.h"
#include "../SchoolManagement/checkers.h"
#include "../SchoolManagement/userInterface.h"
#include "../SchoolManagement/data.h"
#include <vector>
#include <string>
#include <fstream>

#pragma warning

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

#define TEST_DIRECTORY getCurrentDirectory(__FILE__);

string getCurrentDirectory(string path) 
{
	const size_t last_slash_idx = path.rfind('\\');
	if (std::string::npos != last_slash_idx)
	{
		return path.substr(0, last_slash_idx);
	}
	return "";
}

namespace UnitTestingQA
{
	TEST_CLASS(checkersUnitTests)
	{
	public:

		TEST_METHOD(ExpectToThrowAnExceptionIfThereIsNoDataInStudentsFile)
		{
			// Arrange
			vector<STUDENT> students =
			{
				{"Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" },
				{"Alex", "Dinev", "10V", "AGDinev18@codingburgas.bg"},
				{"Atanas", "Burmov", "10B", "AABurmov18@codingburgas.bg"}
			};
			string expect = "Stoyan|Kolev|10A|SNKolev18@codingburgas.bg|Alex|Dinev|10V|AGDinev18@codingburgas.bg|Atanas|Burmov|10B|AABurmov18@codingburgas.bg|";
			string filename = (std::string)TEST_DIRECTORY;
			string outer = filename;
			
			outer += "\\students.txt";

			// Act

			//writeStudentsInTxt(students);
			ofstream file(outer, ios::out);
			if (file.is_open())
			{
				for (size_t i = 0; i < students.size(); i++)
				{
					file << students[i].delimitInfo() << endl;
				}
			}
			string lines, out;
		
			ifstream fileOut(outer, ios::in);
			if (fileOut.is_open()) 
			{
				while (!fileOut.eof())
				{
					getline(fileOut, lines);
					out += lines;
				}
			}
			// Assert
			Assert::AreEqual(expect, out);

		}
	};
}
