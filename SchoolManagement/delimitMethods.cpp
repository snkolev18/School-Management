#include <iostream>
#include <vector>
#include "structures.h"

using namespace std;

string STUDENT::delimitInfo()
{
	string result = "";

	result += name;
	result += '|' + surname;
	result += '|' + grade;
	result += '|' + email + '|';

	return result;
}

string TEACHER::delimitInfo()
{
	string result = "";

	result += name;
	result += '|' + surname;
	result += '|' + email + '|';
	for (size_t i = 0; i < teams.size(); i++)
	{
		result += teams[i];
		if (i != teams.size() - 1)
		{
			result += ',';
		}
	}
	result += '|';
	return result;
}

string TEAM::delimitInfo()
{
	string result = "";
	result += teamName + '|';
	for (size_t i = 0; i < roles.size(); i++)
	{
		result += roles[i].role + ':';
		result += roles[i].student.delimitInfo();
		result += ',';
	}
	result += status + '|';
	result += description + '|';

	return result;
}