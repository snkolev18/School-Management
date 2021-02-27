#include "pch.h"
#include "CppUnitTest.h"
#include "../SchoolManagement/checkers.h"
#include "../SchoolManagement/userInterface.h"
#include "../SchoolManagement/data.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTestingQA
{
	TEST_CLASS(checkersUnitTests)
	{
	public:
		
		TEST_METHOD(checkEmailValidityShouldReturnTrueWhenEmailIsValid)
		{
			// Arrange
			string email = "SNKolev18@codingburgas.bg";

			// Act

			bool res = checkEmailValidity(email);

			// Assert

			Assert::AreEqual(true, res);

		}

		TEST_METHOD(checkEmailValidityShouldReturnFalseWhenEmailIsNotValid)
		{
			// Arrange
			string email = "SNKol\"ev18@codingburgas.bg";

			// Act

			bool res = checkEmailValidity(email);

			// Assert

			Assert::AreEqual(false, res);

		}

		TEST_METHOD(checkIfRoleIsWhiteListedShouldReturnTrueIfTheRoleExistInWhitelistingVector)
		{
			// Arrange
			string role = "Scrum Master";
			vector<string> whiteList = { "Dev", "QA", "Scrum Master" };


			// Act

			bool res = checkIfRoleIsWhiteListed(whiteList, role);

			// Assert

			Assert::AreEqual(true, res);

		}
	};
}
