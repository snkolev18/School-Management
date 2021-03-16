#pragma once
#include "structures.h"

void writeRolesInTxt(std::vector<std::string>& roles);

void writeStudentsInTxt(std::vector<STUDENT>& students);

void writeTeachersInTxt(std::vector<TEACHER>& teachers);

void writeTeamsInTxt(std::vector<TEAM>& teams);

void writeSchoolInTxt(std::string name, std::string city, std::string address);

void writeProjectsInTxt(std::vector<TEAM_PROJECT>& project, std::string fileName);