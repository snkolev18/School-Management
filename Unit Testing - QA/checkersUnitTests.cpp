#include "pch.h"
#include "CppUnitTest.h"
//#include "../SchoolManagement/checkers.h"
//#include "../SchoolManagement/userInterface.h"
//#include "../SchoolManagement/data.h"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestingQA
{
	//TEST_CLASS(checkersUnitTests)
	//{
	//public:
	//	
	//	TEST_METHOD(checkEmailValidityShouldReturnTrueWhenEmailIsValid)
	//	{
	//		// Arrange
	//		string email = "SNKolev18@codingburgas.bg";

	//		// Act
	//		bool res = checkEmailValidity(email);

	//		// Assert
	//		Assert::AreEqual(true, res);

	//	}

	//	TEST_METHOD(checkEmailValidityShouldReturnFalseWhenEmailIsNotValid)
	//	{
	//		// Arrange
	//		string email = "SNKol\"ev18@codingburgas.bg";

	//		// Act
	//		bool res = checkEmailValidity(email);

	//		// Assert
	//		Assert::AreEqual(false, res);

	//	}

	//	TEST_METHOD(checkEmailValidityShouldReturnFalseWhenEmailIsNotValidForNInvalidCharacters)
	//	{
	//		// Arrange
	//		string email = "SNKolev18@codingburgas.bg";
	//		string invalid = "!#$%&'*+\"~\\/=?^`{|/}[],;:";
	//		//string invalid[26] = { "!", "#", "$", "%", "&", "\"", "*", "+","\"", "~", "\\", "/", "=", "?", "^", "`", "{", "|", "/", "}", "[", "]", ",", ";", ":","\"" };
	//		vector<string> combs;
	//		for (size_t i = 0; i < combs.size(); i++)
	//		{
	//			/*string hold;
	//			hold += invalid[i];*/
	//			email[5] = invalid[i];
	//			combs.push_back(email);
	//		}
	//		// Act
	//		vector<bool> checks;
	//		for (size_t i = 0; i < combs.size(); i++)
	//		{
	//			checks.push_back(checkEmailValidity(combs[i]));
	//		}
	//		

	//		// Assert
	//		for (int i = 0; i < checks.size(); i++)
	//		{
	//			Assert::IsFalse(checks[i]);

	//		}

	//	}

	//	TEST_METHOD(checkIfRoleIsWhiteListedShouldReturnTrueIfTheRoleExistInWhitelistingVector)
	//	{
	//		// Arrange
	//		string role = "Scrum Master";
	//		vector<string> whiteList = {  };

	//		// Act
	//		bool res = checkIfRoleIsWhiteListed(whiteList, role);

	//		// Assert
	//		Assert::AreEqual(true, res);

	//	}

	//	TEST_METHOD(shouldReturnTrueIfThereIsAlreadyAStudentWithGivenEmail)
	//	{
	//		// Arrange
	//		vector<STUDENT> students;
	//		students.push_back({ "Jekata", "Velikov", "10A", "DMKalchev18@codingburgas.bg" });
	//		students.push_back({ "Ili qm", "Ili ne", "10A", "ILIQM18@codingburgas.bg" });
	//		students.push_back({ "Stoyan", "Kolev", "10A", "SNKolev18@codingburgas.bg" });
	//		students.push_back({ "Life", "Georgiev", "10A", "GKGeorgiev@codingburgas.bg" });

	//		string tEmail = "SNKolev18@codingburgas.bg";
	//		

	//		// Act
	//		bool checker = checkForExistingEmailStudents(students, tEmail);

	//		// Assert
	//		Assert::AreEqual(true, checker, L"There is a student with that email");

	//	}

	//	TEST_METHOD(shouldReturnFalseIfThereIsNoStudentWithGivenEmail)
	//	{
	//		// Arrange
	//		vector<STUDENT> students;
	//		students.push_back({ "Jekata", "Velikov", "10A", "DMKalchev18@test.test" });
	//		students.push_back({ "Ili qm", "Ili ne", "10A", "ILIQM18@test.test" });
	//		students.push_back({ "Stoyan", "Kolev", "10A", "SNKolev18@c@test.test" });
	//		students.push_back({ "Life", "Georgiev", "10A", "GKGeorgiev@test.test" });

	//		string sEmail = "test@test.test";


	//		// Act
	//		bool checker = checkForExistingEmailStudents(students, sEmail);

	//		// Assert
	//		Assert::AreEqual(false, checker, L"There is NO student with that email");

	//	}

	//	TEST_METHOD(shouldReturnFalseIfThereIsNoTeacherWithGivenEmail)
	//	{
	//		// Arrange
	//		vector<TEACHER> teachers;
	//		teachers.push_back({ "Teacher1", "Familiq", {"Team1", "Team2"}, "TeacherEmail1@teacher.t" });
	//		teachers.push_back({ "Teacher2", "Familiq", {"Team1", "Team2"}, "TeacherEmail2@teacher.t" });
	//		teachers.push_back({ "Teacher3", "Familiq", {"Team1", "Team2"}, "TeacherEmail3@teacher.t" });
	//		teachers.push_back({ "Teacher4", "Familiq", {"Team1", "Team2"}, "TeacherEmail4@teacher.t" });
	//		
	//		string tEmail = "TeacherEmail5@teacher.t";


	//		// Act
	//		bool checker = checkForExistingEmailTeachers(teachers, tEmail);

	//		// Assert
	//		Assert::AreEqual(false, checker, L"There is NO teacher with that email");

	//	}

	//	TEST_METHOD(shouldReturnTrueIfGivenNameIsVALID)
	//	{
	//		// Arrange
	//		string firstname = "Ivan";

	//		// Act
	//		bool isValid = checkNameValidity(firstname);

	//		// Assert
	//		Assert::IsTrue(isValid);

	//	}

	//	TEST_METHOD(shouldReturnFalseIfGivenNameIsINVALID)
	//	{
	//		// Arrange
	//		string firstname = "Ivan Georgiev";

	//		// Act
	//		bool isValid = checkNameValidity(firstname);

	//		// Assert
	//		Assert::IsTrue(isValid);

	//	}
	//};
}
