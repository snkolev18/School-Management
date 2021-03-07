#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"
#include "data.h"
#include "userInterface.h"
using namespace std;

int main()
{
	SCHOOL school = readSchoolFromTxt();

	bool flag;
	logger.open("logs.txt");
	logger.writeLogMsg(SEVERITY::INFO, "Program was executed successfully");

	vector<string> whiteListedRoles = readRolesFromTxt();

	bool inputSchoolInfo;

	if (school.name.empty())
		inputSchoolInfo = 1;
	else
		inputSchoolInfo = 0;

	do {
		flag = menu(school, whiteListedRoles, inputSchoolInfo);
	} while (flag);

	logger.writeLogMsg(SEVERITY::INFO, "Program was terminated successfully");
}