#include "pch.h"
#include "CppUnitTest.h"
#include "../SchoolManagement/checkers.h"
#include "../SchoolManagement/userInterface.h"
#include "../SchoolManagement/data.h"
#include <vector>
#include <string>

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

		TEST_METHOD(checkEmailValidityShouldReturnFalseWhenEmailIsNotValidForNInvalidCharacters)
		{
			// Arrange
			string email = "SNKolev18@codingburgas.bg";
			string invalid = "!#$%&'*+\"~\\/=?^`{|/}[],;:";
			//string invalid[26] = { "!", "#", "$", "%", "&", "\"", "*", "+","\"", "~", "\\", "/", "=", "?", "^", "`", "{", "|", "/", "}", "[", "]", ",", ";", ":","\"" };
			vector<string> combs;
			for (size_t i = 0; i < combs.size(); i++)
			{
				/*string hold;
				hold += invalid[i];*/
				email[5] = invalid[i];
				combs.push_back(email);
			}
			// Act
			vector<bool> checks;
			for (size_t i = 0; i < combs.size(); i++)
			{
				checks.push_back(checkEmailValidity(combs[i]));
			}
			

			// Assert
			for (int i = 0; i < checks.size(); i++)
			{
				Assert::IsFalse(checks[i]);

			}

		}

		TEST_METHOD(checkIfRoleIsWhiteListedShouldReturnTrueIfTheRoleExistInWhitelistingVector)
		{
			// Arrange
			string role = "Scrum Master";
			vector<string> whiteList = {  };

			// Act
			bool res = checkIfRoleIsWhiteListed(whiteList, role);

			// Assert
			Assert::AreEqual(true, res);

		}
	};
}
