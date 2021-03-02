#pragma once
#include "structures.h"

void displayNSpaces(int n);

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

bool menu(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers, std::vector<std::string>& whiteListedRoles, std::vector<TEAM>& teams);