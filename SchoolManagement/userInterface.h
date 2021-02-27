#pragma once
#include "structures.h"

bool menu(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers, std::vector<std::string>& whiteListedRoles, std::vector<TEAM>& teams);

void displayHeaderStudentsTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail);

void displayBodyStudentsTable(std::vector<STUDENT>& students, int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail);

void displayFooterStudentsTable(int& maxSize, int& maxSizeNames, int& maxSizeSurnames, int& maxSizeClass, int& maxSizeEmail);

void displayStudentsInTable(std::vector<STUDENT>& students);
