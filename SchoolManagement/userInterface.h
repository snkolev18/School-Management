#pragma once
#include "structures.h"

void clearScreen();

void displayNSpaces(int n);

void displaySchoolTableHeader(int& sizeName, int& sizeCity, int& sizeAddress, int& sizeStudents, int& sizeTeachers, int& sizeTeams);

void displaySchoolTableBodyAndFooter(SCHOOL& school, int& sizeName, int& sizeCity, int& sizeAddress, int& sizeStudents, int& sizeTeachers, int& sizeTeams);

void displaySchoolInfoInTable(SCHOOL& school);

void displayHeaderTeamsTable(int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, std::vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus, std::vector<std::string>& whiteListedRoles);

void displayBodyTeamsTable(std::vector<TEAM>& teams, int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, std::vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus);

void displayFooterTeamsTable(int& maxSizeNames, int& maxSizeDescriptions, int& maxSizeDate, std::vector<int>& maxSizeStudents, int& maxSizeTeachers, int& maxSizeStatus);

void displayTeamsInTable(std::vector<TEAM>& teams, std::vector<std::string> whiteListedRoles);

void displayHeaderStudentsAndTeachersTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail, std::string object);

void displayBodyStudentsTable(std::vector<STUDENT>& students, int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail);

void displayBodyTeachersTable(std::vector<TEACHER>& teachers, int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail, std::vector<std::string> teams);

void displayFooterTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail);

void displayStudentsInTable(std::vector<STUDENT>& students);

void displayTeachersInTable(std::vector<TEACHER>& teachers);

void displayTeamsUpdateMenu();

void statusMenu();

bool filteringMenu(bool who, std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

void handleUpdateTeamInfo(int option, std::vector<TEAM>& teams, std::vector<TEACHER>& teachers, std::vector<STUDENT>& students, int& teamID);

bool menu(SCHOOL& school, std::vector<std::string>& whiteListedRoles, bool& inputSchoolInfo, std::vector<TEAM_PROJECT>& projects);