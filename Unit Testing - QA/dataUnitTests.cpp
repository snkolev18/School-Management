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

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyWriteDataInStudentsTxtFile)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyWriteDataInStudentsTxtFile)
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

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturnFoundStudentByEmail)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturnFoundStudentByEmail)
		{
			// Arrange
			vector<STUDENT> students =
			{
				{"Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" },
				{"Alex", "Dinev", "10V", "AGDinev18@codingburgas.bg"},
				{"Atanas", "Burmov", "10B", "AABurmov18@codingburgas.bg"}
			};


			// Act
			STUDENT found = findStudentByEmail(students, (string)"AGDinev18@codingburgas.bg");
			// Assert

			for (size_t i = 0; i < students.size(); i++)
			{
				if (students[i].email == found.email)
				{
					Assert::AreEqual(students[i].name, found.name);
					Assert::AreEqual(students[i].surname, found.surname);
					Assert::AreEqual(students[i].grade, found.grade);
				}
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldFailTheSearchOfAStudent)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldFailTheSearchOfAStudent)
		{
			// Arrange
			vector<STUDENT> students =
			{
				{"Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" },
				{"Alex", "Dinev", "10V", "AGDinev18@codingburgas.bg"},
				{"Atanas", "Burmov", "10B", "AABurmov18@codingburgas.bg"}
			};


			// Act
			STUDENT found = findStudentByEmail(students, (string)"AGDinev@codingburgas.bg");
			// Assert

			for (size_t i = 0; i < students.size(); i++)
			{
				if (students[i].email == found.email)
				{
					Assert::AreEqual(students[i].name, found.name);
					Assert::AreEqual(students[i].surname, found.surname);
					Assert::AreEqual(students[i].grade, found.grade);
				}
				else
				{
					Assert::Fail(L"Couldn't find such student");
				}
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToThrowAnExceptionWhenThereAreNoStudentsWhenPassingStudentsAsAnEmptyVector)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToThrowAnExceptionWhenThereAreNoStudentsWhenPassingStudentsAsAnEmptyVector)
		{
			// Arrange
			vector<TEACHER> teachers = { {"Petar", "Edi koi si", {""},  "mail@mail.com"} };
			vector<STUDENT> students;
			vector<TEAM> teams;
			vector<string> whiteListedRoles = { "Scrum", "QA", "Backend", "Frontend" };


			// Act
			try
			{
				teams.push_back(inputTeam(whiteListedRoles, students, teachers, teams));
			}
			catch (const std::runtime_error& ex)
			{
				if (strcmp(ex.what(), "There are no students to add in a team") == 0)
					return;
				Assert::Fail(L"Unexpected exception text thrown");
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type thrown");
			}

			Assert::Fail(L"No exceptions were thrown");

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToThrowAnExceptionWhenThereAreNoTeachersWhenPassingTeachersAsAnEmptyVector)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToThrowAnExceptionWhenThereAreNoTeachersWhenPassingTeachersAsAnEmptyVector)
		{
			// Arrange
			vector<TEACHER> teachers;
			vector<STUDENT> students = { {"Georgi", "Bokluka", "10V", "qkiq123@abv.bg"}, {"Manqka za", "Znaete kakvo", "10A", "manqka928@gmail.com"} };
			vector<TEAM> teams;
			vector<string> whiteListedRoles = { "Scrum", "QA", "Backend", "Frontend" };


			// Act
			try
			{
				teams.push_back(inputTeam(whiteListedRoles, students, teachers, teams));
			}
			catch (const std::runtime_error& ex)
			{
				if (strcmp(ex.what(), "There are no teachers to add in a team") == 0)
					return;
				Assert::Fail(L"Unexpected exception text thrown");
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type thrown");
			}

			Assert::Fail(L"No exceptions were thrown");
			//Assert
		}
	};
}
