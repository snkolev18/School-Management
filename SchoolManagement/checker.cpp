#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <climits>
#include <regex>
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

bool checkIfTeamNameIsUsed(const vector<TEAM> teams, const string name) 
{
	if (teams.empty()) 
	{
		return false;
	}

	for (size_t i = 0; i < teams.size(); i++)
	{
		if (name == teams[i].teamName) 
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

	return invalidCharsCheck and subdomainCheck and email.length() < MAX_EMAIL_SIZE ? true : false;

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
	if (toupper(isalpha(grade[grade.size() - 1])) and gradeNumInRange)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkNameValidity(string name)
{

	bool isValid = true;

	if (name.length() > MAX_NAME_SIZE or name.length() < MIN_NAME_SIZE) 
	{
		return false;
	}


	for (size_t i = 0; i < name.size(); i++)
	{
		if (!isalpha(name[i]))
		{
			isValid = false;
			break;
		}
	}

	return isValid;
}

bool checkStrInput(const string inp_)
{
	for (char ch : inp_)
	{
		if (!isalpha(ch)) 
		{
			return false;
		}
	}

	return true;
}

//void repeaterEmail(string inp_) 
//{
//	while (!checkEmailValidity(inp_))
//	{
//		cout << "Invalid, re-enter: "; cin >> inp_;
//	}
//}

bool checkTeamNameLength(string name) 
{
	return name.length() > MAX_TEAMNAME_SIZE ? false : true;
}

bool checkTeamDescriptionLength(string description) 
{
	return description.length() > MAX_TEAM_DESCRIPTION ? false : true;
}

bool checkProjectDescription(string description) 
{
	return description.length() > MAX_PROJECT_DESCRIPTION_SIZE or description.length() < MIN_PROJECT_DESCRIPTION_SIZE ? false : true;
}

bool checkDateStandart(const string date) 
{
	regex pattern("\\b\\d{4}[-]\\d{2}[-]\\d{2}\\b");
	return regex_match(date, pattern);
}

void badChoice(int& option) 
{

	while (!(cin >> option))
	{
		cout << ERROR_MSG_CR << "That's not a valid input!" << CLOSE_ERR_MSG << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << ERROR_MSG_CR << "Re-enter your choice: " << CLOSE_ERR_MSG;
	}

}

void badChoiceFiltering(int& option)
{

	while (!(cin >> option).good() or option < 1 or option > 4)
	{
		cout << ERROR_MSG_CR << "That's not a valid input!" << CLOSE_ERR_MSG << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << ERROR_MSG_CR << "Re-enter your choice: " << CLOSE_ERR_MSG;
	}

}

bool isDataEmpty(SCHOOL school) 
{
	return school.teachers.empty() or school.teams.empty() or school.students.empty() ? true : false;
}

bool checkProjectNameLength(const string name) 
{
	return name.length() < MIN_PROJECT_NAME_SIZE or name.length() > MAX_PROJECT_NAME_SIZE ? false : true;
}

//template <typename T>
//void teachersEmpty(T object, const std::string type) 
//{
//	if (object.empty()) {
//		throw std::runtime_error("Currently there are no " + type + ", Try adding some");
//	}
//	
//}
void teachersEmpty(vector<TEACHER> teachers, vector<STUDENT> students)
{
	if (teachers.empty()) {
		throw std::runtime_error("Currently there are no teachers, Try adding some");
	}
	if (students.empty()) {
		throw std::runtime_error("Currently there are no teachers, Try adding some");
	}
}

