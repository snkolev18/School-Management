#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "structures.h"

using namespace std;

bool checkForExistingEmailTeachers(vector<TEACHER> teachers, string email)
{
	for (size_t i = 0; i < teachers.size(); i++)
	{
		if (teachers[i].email == email)
		{
			return true;
		}
	}
	return false;
}

bool checkForExistingEmailStudents(vector<STUDENT> students, string email)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i].email == email)
		{
			return true;
		}
	}
	return false;
}

bool checkForExistingEmail(vector<STUDENT> students, vector<TEACHER> teachers, string email)
{
	if (checkForExistingEmailTeachers(teachers, email) or checkForExistingEmailStudents(students, email))
	{
		return true;
	}

	return false;
}

bool checkIfRoleIsWhiteListed(vector<string> whiteListedRoles, string role)
{
	if (whiteListedRoles.size() == 0) 
	{
		return false;
	}
	for (size_t i = 0; i < whiteListedRoles.size(); i++)
	{
		if (whiteListedRoles[i] == role)
		{
			return true;
		}
	}

	return false;
}

bool checkEmailValidity(string email)
{
	size_t atPos = email.find('@');
	size_t dotPos;
	string username, domain;
	string invalid = "!#$%&'*+\"~\\/=?^`{|^/}[],;:";

	bool invalidCharsCheck = true;
	bool subdomainCheck = false;

	if (atPos != string::npos)
	{
		username = email.substr(0, atPos);
		domain = email.substr(atPos + 1);

		if (isalpha(username[0]))
		{
			for (int i = 1; i < username.size(); i++)
			{
				for (size_t j = 0; j < invalid.size(); j++)
				{
					if (username[i] == invalid[j])
					{
						invalidCharsCheck = false;
						break;
					}
				}
			}
			dotPos = email.find('.', atPos + 2);

			/*for (int i = 0; i < domain.size(); i++)
			{
				for (int j = 0; j < invalid.size(); j++)
				{
					if(domain[i] != invalid[j])
					{
						valid++;
					}
				}
			}*/

			if (dotPos != string::npos)
			{
				subdomainCheck = true;
			}
			else
			{
				subdomainCheck = false;
			}
		}
	}

	return invalidCharsCheck and subdomainCheck ? true : false;

	//size_t dotPos = email.find()
}

bool checkGrade(string grade)
{
	string gradeNum = "";
	int numGrade;
	bool gradeNumInRange = false, spaces = false;
	if (grade.size() == 2 or grade.size() == 3) {
		if (isdigit(grade[0]) or (isdigit(grade[0]) and isdigit(grade[1])))
		{
			if (grade.size() == 2)
			{
				gradeNum = grade.substr(0, 1);
			}
			if (grade.size() == 3)
			{
				gradeNum = grade.substr(0, 2);
			}

			numGrade = stoi(gradeNum);

			if (numGrade >= 1 and numGrade <= 12)
			{
				gradeNumInRange = true;
			}

			/*for (size_t i = 0; i < grade.size(); i++)
			{
				if (grade[i] == ' ')
				{
					spaces = true;
					break;
				}
			}*/

		}
	}
	if (isalpha(grade[grade.size() - 1]) and gradeNumInRange)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkIfNameIsValid(string name) 
{
	bool isValid = true;

	for (size_t i = 0; i < name.size(); i++)
	{
		if(!isalpha(name[i]))
		{
			isValid = false;
			break;
		}
	}

	return isValid;
}