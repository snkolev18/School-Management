#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include "structures.h"
#include "userInterface.h"
#include "checkers.h"
#include "messages.h"
#include "utils.h"
#include "data.h"
using namespace std;

void writeRolesInTxt(vector<string>& whiteListedRoles)
{
	ofstream file;
	file.open("roles.txt", ios::out | ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < whiteListedRoles.size(); i++)
		{
			file << whiteListedRoles[i] << endl;
		}
		file.close();
		logger.writeLogMsg(SEVERITY::INFO, "Roles were successfully written into roles.txt");
	}
}

void writeStudentsInTxt(vector<STUDENT>& students)
{
	ofstream file;
	file.open("students.txt", ios::out | ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			file << students[i].delimitInfo() << endl;
		}
		file.close();
		logger.writeLogMsg(SEVERITY::INFO, "Students were successfully written into students.txt");
	}
}

void writeTeachersInTxt(vector<TEACHER>& teachers)
{
	ofstream file;
	file.open("teachers.txt", ios::out | ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < teachers.size(); i++)
		{
			file << teachers[i].delimitInfo() << endl;
		}
		file.close();
		logger.writeLogMsg(SEVERITY::INFO, "Teachers were successfully written into teachers.txt");
	}
}

void writeTeamsInTxt(vector<TEAM>& teams)
{
	ofstream file;
	file.open("teams.txt", ios::out | ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < teams.size(); i++)
		{
			file << teams[i].delimitInfo() << endl;
		}
		file.close();
		logger.writeLogMsg(SEVERITY::INFO, "Teams were successfully written into teams.txt");
	}
}

void writeProjectsInTxt(vector<TEAM_PROJECT>& project, string fileName)
{
	ofstream out;
	out.open(fileName, ios::out | ios::trunc);
	if (out.is_open())
	{
		for (size_t i = 0; i < project.size(); i++)
		{
			out << project[i].delimitInfo() << endl;
		}
		out.close();
		logger.writeLogMsg(SEVERITY::INFO, "Projects were successfully written into projects.txt");
	}
}

void writeSchoolInTxt(string name, string city, string address)
{
	ofstream file;
	file.open("school.txt", ios::trunc);
	if (file.is_open())
	{
		file << name << endl;
		file << city << endl;
		file << address << endl;
		file.close();
	}
}