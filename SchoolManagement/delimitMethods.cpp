#include <iostream>
#include <vector>
#include "structures.h"
#include "file_io.h"

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
	result += '|' + surname + '|';
	for (size_t i = 0; i < teams.size(); i++)
	{
		result += teams[i];
			result += '=';
	}
	result += email + "|;";
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
	result += teacher.delimitInfo();
	result += '|'+ dateCreation + '|';
	result += status + '|';
	result += description + '|';

	return result;
}

string TEAM_PROJECT::delimitInfo()
{
	string res;

	res += name + "|" + description + "|" + dueDate + "|";
	
	return res;

}