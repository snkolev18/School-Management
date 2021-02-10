#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"

using namespace std;

STUDENT inputStudent()
{
	STUDENT student;
	cout << "First name: ";
	cin >> student.name;
	cout << "Surname: ";
	cin >> student.surname;
	cout << "Class: ";
	cin >> student.grade;
	cout << "Role: ";
	cin >> student.role;
	cout << "Email: ";
	cin >> student.email;
	return student;
}

string addRole()
{
	string role;
	cout << "Enter a name for the role: ";
	cin >> role;
	return role;
}

void writeRolesInTxt(vector<string> roles)
{
	ofstream file;
	file.open("roles.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < roles.size(); i++)
		{
			file << roles[i] << endl;
		}
		file.close();
	}
}

vector<string> readRolesFromTxt()
{
	vector<string> roles;
	string line;
	ifstream file("roles.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			roles.push_back(line);
		}
		file.close();
	}
	return roles;
}

void removeRole(vector<string>& roles, int id)
{
	roles.erase(roles.begin() + id);
}
