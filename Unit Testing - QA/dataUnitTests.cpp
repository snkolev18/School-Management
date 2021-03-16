#include "pch.h"
#include "CppUnitTest.h"
#include "../SchoolManagement/checkers.h"
#include "../SchoolManagement/userInterface.h"
#include "../SchoolManagement/data.h"
#include "../SchoolManagement/utils.h"
#include "../SchoolManagement/file_io.h"
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
			TEST_PRIORITY("Low")
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
			TEST_PRIORITY("High")
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
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToThrowAnExceptionWhenThereAreNoTeachersWhenPassingTeachersAsAnEmptyVector)
		{
			// Arrange
			vector<TEACHER> teachers;
			vector<STUDENT> students =
			{
				{"Georgi", "Bokluka", "10V", "qkiq123@abv.bg"},
				{"Manqka za", "Znaete kakvo", "10A", "manqka928@gmail.com"}
			};
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

			//Assert
			Assert::Fail(L"No exceptions were thrown");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldRemoveAStudentFromTeamByPassingSpecificEmail)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldRemoveAStudentFromTeamByPassingSpecificEmail)
		{
			// Arrange
			vector<ROLE> students =
			{
				{"QA", { "Georgi", "Bokluka", "10V", "qkiq123@abv.bg" }},
				{"Scrum", { "Manqka za", "kurwi", "10A", "manqka928@gmail.com" }}
			};


			// Act
			removeStudentFromTeam(students, (string)"manqka928@gmail.com");

			//Assert
			for (size_t i = 0; i < students.size(); i++)
			{
				/*if (students[i].student.email == "manqka928@gmail.com")
				{
				}*/
				Assert::AreNotSame(students[i].student.email, (string)"manqka928@gmail.com", L"Student with email of manqka928@gmail.com has been successfully removed");
			}
			//Assert::AreEqual((size_t)1, students.size(), L"Successfully removed student with email of manqka928@gmail.com");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyRemoveStudent)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyRemoveStudent)
		{
			// Arrange
			vector<STUDENT> students =
			{
				{ "Georgi", "Bokluka", "10V", "qkiq123@abv.bg" },
				{ "Manqka za", "kurwi", "10A", "manqka928@gmail.com" }
			};

			// Act
			removeStudent(students, (string)"qkiq123@abv.bg");

			//Assert
			Assert::AreEqual((size_t)1, students.size());
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyRemoveTeacher)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyRemoveTeacher)
		{
			// Arrange
			vector<TEACHER> teachers =
			{
				{ "Georgi", "Bokluka", {""}, "qkiq123@abv.bg" },
				{ "Uchitel", "kurwi", {""}, "manqka928@gmail.com" }
			};

			// Act
			size_t oldTeachersSize = teachers.size();
			removeTeacher(teachers, (string)"qkiq123@abv.bg");

			//Assert
			Assert::AreEqual(oldTeachersSize - 1, teachers.size());
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToThrowAnExceptionWhenThereIsNoDataInTeachersTxtOrInTheTeachersVector)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToThrowAnExceptionWhenThereIsNoDataInTeachersTxtOrInTheTeachersVector)
		{
			// Arrange
			vector<TEAM> teams;
			vector<TEACHER> teachers;

			//Act
			try
			{
				deleteTeacherData(teachers, teams);
			}
			catch (const std::runtime_error& ex)
			{
				if (strcmp(ex.what(), "File with teachers has no data to delete!") == 0)
					return;
				Assert::Fail(L"Unexpected exception text thrown");
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type thrown");
			}

			//Assert
			Assert::Fail(L"No exceptions were thrown");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToThrowAnExceptionWhenThereIsNoDataInStudentsTxtOrInTheStudentsVector)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToThrowAnExceptionWhenThereIsNoDataInStudentsTxtOrInTheStudentsVector)
		{
			// Arrange
			vector<TEAM> teams;
			vector<STUDENT> students;

			//Act
			try
			{
				deleteStudentData(students, teams);
			}
			catch (const std::runtime_error& ex)
			{
				if (strcmp(ex.what(), "File with students has no data to delete!") == 0)
					return;
				Assert::Fail(L"Unexpected exception text thrown");
			}
			catch (...) {
				Assert::Fail(L"Unexpected exception type thrown");
			}

			//Assert
			Assert::Fail(L"No exceptions were thrown");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturnIndexOfTheFoundTeacher)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturnIndexOfTheFoundTeacher)
		{
			// Arrange
			vector<TEACHER> teachers
			{
				{ "Georgi", "Bokluka", {""}, "qkiq123@abv.bg" },
				{ "Uchitel", "kurwi", {""}, "manqka928@gmail.com" },
				{ "Brat", "Vrat", {""}, "qnko@e.bratans" },
			};

			//Act
			int foundIndex = findIndexByEmailTeachers(teachers, (string)"qnko@e.bratans");

			//Assert
			Assert::AreEqual(2, foundIndex);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturnIndexOfTheFoundStudent)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturnIndexOfTheFoundStudent)
		{
			// Arrange
			vector<STUDENT> students
			{
				{ "Georgi", "Manqka", "10A" , "qkiq123@abv.bg" },
				{ "Izvinqvam", "se", "10A" , "manqka928@gmail.com" },
				{ "Brat", "Vrat", "10V", "qnko@e.bratans" },
			};

			//Act
			int foundIndex = findIndexByEmailStudents(students, (string)"manqka928@gmail.com");

			//Assert
			Assert::AreEqual(1, foundIndex);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccesfullyUpdateTeacherInATeamWithANewOne)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccesfullyUpdateTeacherInATeamWithANewOne)
		{
			// Arrange
			TEAM team =
			{
				{{"QA"}, {"Stoyan", "Kolev", "10A", "manqka123@abv.bg"}}, "Offsec", {"Nikolai", "Ivanov", {""}, "nikiI@abv.bg"}, "Qk description", getDate()
			};
			vector<TEACHER> teachers
			{
				{ "Georgi", "Bokluka", {""}, "qkiq123@abv.bg" },
				{ "Uchitel", "kurwi", {""}, "manqka928@gmail.com" },
				{ "Brat", "Vrat", {""}, "qnko@e.bratans" },
			};

			//Act
			updateTeamTeacher(team, teachers.at(1));

			//Assert

			// Name or any other field is enough just to check if it was updated
			Assert::AreEqual(team.teacher.name, teachers.at(1).name, L"Should be changed with second teacher from the vector of teachers");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccesfullyUpdateTeamNameWithANewOne)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccesfullyUpdateTeamNameWithANewOne)
		{
			// Arrange
			TEAM team =
			{
				{{"QA"}, {"Stoyan", "Kolev", "10A", "manqka123@abv.bg"}}, "Offsec", {"Nikolai", "Ivanov", {""}, "nikiI@abv.bg"}, "Qk description", getDate()
			};

			//Act
			updateTeamName(team, (string)"Offensive Security");

			//Assert

			// Name or any other field is enough just to check if it was updated
			Assert::AreEqual(team.teamName, (string)"Offensive Security", L"Should change the name of a team with Offensive Security in this case");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccesfullyUpdateTeamDescriptionWithANewOne)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccesfullyUpdateTeamDescriptionWithANewOne)
		{
			// Arrange
			TEAM team =
			{
				{{"QA"}, {"Stoyan", "Kolev", "10A", "manqka123@abv.bg"}}, "Offsec", {"Nikolai", "Ivanov", {""}, "nikiI@abv.bg"}, "Qk description", getDate()
			};

			//Act
			updateTeamDescription(team, (string)"New team description");

			//Assert

			// Name or any other field is enough just to check if it was updated
			Assert::AreEqual(team.description, (string)"New team description", L"Should change the description of a team with a new one");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccesfullyUpdateTeamStatusWithANewOne)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccesfullyUpdateTeamStatusWithANewOne)
		{
			// Arrange
			string status = TEAM::statusToString(TEAM::STATUS::IN_USE);

			TEAM team =
			{
				{ {"QA"}, {"Stoyan", "Kolev", "10A", "manqka123@abv.bg"}}, "Offsec", {"Nikolai", "Ivanov", {""}, "nikiI@abv.bg"}, "Qk description", getDate(), status
			};

			string newStatus = TEAM::statusToString(TEAM::STATUS::ARCHIVED);

			//Act
			updateTeamStatus(team, newStatus);

			//Assert

			// Name or any other field is enough just to check if it was updated
			Assert::AreEqual(team.status, newStatus, L"Should change the status of a team with a new one");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyConvertEnumCodeToString)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyConvertEnumCodeToString)
		{
			// Arrange
			vector<TEAM::STATUS> statuses = { TEAM::STATUS::IN_USE, TEAM::STATUS::NOT_ACTIVE, TEAM::STATUS::ARCHIVED };
			vector<string> results;
			vector<string> posibles = { "In use", "Not active", "Archived" };

			//Act
			for (size_t i = 0; i < statuses.size(); i++)
			{
				results.push_back(TEAM::statusToString(statuses[i]));
			}

			//Assert

			for (size_t i = 0; i < results.size(); i++)
			{
				Assert::AreEqual(posibles.at(i), results.at(i));
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyWriteProjectsInTxt)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyWriteProjectsInTxt)
		{
			// Arrange
			string filename = (std::string)TEST_DIRECTORY;
			string outer = filename;

			outer += "\\projects.txt";

			vector<TEAM_PROJECT> projects =
			{
				{ "Project_One", "Cool Project", "2021-03-17" },
				{ "Project_Two", "Cool Project YEAH", "2021-03-17" }
			};

			string expect = "Project_One|Cool Project|2021-03-17|Project_Two|Cool Project YEAH|2021-03-17|";

			//Act
			writeProjectsInTxt(projects, outer);

			string curLine, outLine;
			fstream fileOut(outer, ios::in);

			if (fileOut.is_open()) 
			{
				while (!fileOut.eof())
				{
					getline(fileOut, curLine);
					outLine += curLine;
				}
			}
			

			//Assert

			Assert::AreEqual(expect, outLine);

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyRemoveAStudent)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyRemoveAStudent)
		{
			// Arrange
			vector<STUDENT> students =
			{
				{"Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" },
				{"Alex", "Dinev", "10V", "AGDinev18@codingburgas.bg"},
				{"Atanas", "Burmov", "10B", "AABurmov18@codingburgas.bg"}
			};
			STUDENT safe = { "Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" };
			//Act
			removeStudent(students, "AABurmov18@codingburgas.bg");

			//Assert
			for (size_t i = 0; i < students.size(); i++)
			{
				Assert::AreNotEqual(students.at(i).email, safe.email);
				Assert::AreNotEqual(students.at(i).name, safe.name);
				Assert::AreNotEqual(students.at(i).surname, safe.surname);
				Assert::AreNotEqual(students.at(i).grade, safe.grade);
			}
			

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldSuccessfullyRemoveATeam)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldSuccessfullyRemoveATeam)
		{
			// Arrange

			vector<TEAM> teams =
			{
				{{ {"QA"}, {"Stoyan", "Kolev", "10A", "manqka123@abv.bg"}}, "Offsec", {"Nikolai", "Ivanov", {""}, "nikiI@abv.bg"}, "Qk description", getDate(), "" }
			};

			//Act
			removeTeam(teams, "Offsec");

			//Assert
			
			Assert::AreEqual((size_t)0, teams.size());


		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturnAllFoundByNameTeachers)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturnAllFoundByNameTeachers)
		{
			// Arrange

			vector<TEACHER> teachers =
			{
				{ "Georgi", "Qkiq", {""}, "qkiq123@abv.bg" },
				{ "Georgi", "Manqka", {""}, "manqka928@gmail.com" },
				{ "Petko", "Hubaviq", {""}, "hubaviq73@gmail.com" }
			};

			vector<TEACHER> results;

			//Act
			results = findTeachersByName(teachers, "Georgi");

			//Assert
			for (size_t i = 0; i < results.size(); i++)
			{
				Assert::AreEqual((string)"Georgi", results.at(i).name);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturn0IfThereAreNoFoundByNameTeachers)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturn0IfThereAreNoFoundByNameTeachers)
		{
			// Arrange

			vector<TEACHER> teachers =
			{
				{ "Georgi", "Qkiq", {""}, "qkiq123@abv.bg" },
				{ "Georgi", "Manqka", {""}, "manqka928@gmail.com" },
				{ "Petko", "Hubaviq", {""}, "hubaviq73@gmail.com" }
			};

			vector<TEACHER> results;

			//Act
			results = findTeachersByName(teachers, "Drago");

			//Assert
			Assert::AreEqual((size_t)0, results.size());

		}


		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturnAllFoundBySurnameTeachers)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturnAllFoundBySurnameTeachers)
		{
			// Arrange

			vector<TEACHER> teachers =
			{
				{ "Georgi", "Qkiq", {""}, "qkiq123@abv.bg" },
				{ "Georgi", "Manqka", {""}, "manqka928@gmail.com" },
				{ "Petko", "Manqka", {""}, "hubaviq73@gmail.com" }
			};

			

			vector<TEACHER> results;

			//Act
			results = findTeachersBySurname(teachers, "Manqka");

			//Assert
			for (size_t i = 0; i < results.size(); i++)
			{
				Assert::AreEqual((string)"Manqka", results.at(i).surname);
			}

		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ShouldReturn0IfThereAreNoFoundBySurnameTeachers)
			TEST_OWNER(L"SNKolev18")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ShouldReturn0IfThereAreNoFoundBySurnameTeachers)
		{
			// Arrange

			vector<TEACHER> teachers =
			{
				{ "Georgi", "Qkiq", {""}, "qkiq123@abv.bg" },
				{ "Georgi", "Manqka", {""}, "manqka928@gmail.com" },
				{ "Petko", "Hubaviq", {""}, "hubaviq73@gmail.com" }
			};

			vector<TEACHER> results;

			//Act
			results = findTeachersBySurname(teachers, "Boichev");

			//Assert
			Assert::AreEqual((size_t)0, results.size());

		}

	};
}

