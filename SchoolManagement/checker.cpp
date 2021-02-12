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
	for (size_t i = 0; i < whiteListedRoles.size(); i++)
	{
		if (whiteListedRoles[i] == role)
		{
			return true;
		}
	}
	return false;
}