#pragma once
#include "structures.h"

STUDENT inputStudent(std::vector<STUDENT> students, std::vector<TEACHER> teachers);

TEACHER inputTeacher(std::vector<STUDENT> students, std::vector<TEACHER> teachers);

std::string addRole(std::vector<std::string> whiteListedRoles);

void writeRolesInTxt(std::vector<std::string> roles);

void writeStudentsInTxt(std::vector<STUDENT> students);

void writeTeachersInTxt(std::vector<TEACHER> teachers);

void writeTeamsInTxt(std::vector<TEAM> teams);

std::vector<std::string> readRolesFromTxt();

STUDENT parsedStudentInfo(std::string info);

std::vector<STUDENT> readStudentsFromTxt();

TEACHER parsedTeacherInfo(std::string info);

TEAM parsedTeamInfo(std::string info);

std::vector<TEAM> readTeamsFromTxt();

std::vector<TEACHER> readTeachersFromTxt();

void removeRole(std::vector<std::string>& roles, int id);

STUDENT findStudentByEmail(std::vector<STUDENT> students, std::string email);

int findIndexByEmailTeachers(std::vector<TEACHER>& teachers, std::string email);

TEACHER findTeacherByEmail(std::vector<TEACHER> teachers, std::string email);

void removeStudentFromTeam(std::vector<ROLE>& students, std::string email);

void addStudentToTeam(std::vector<ROLE>& students, ROLE student);

TEAM inputTeam(std::vector<std::string>& whiteListedRoles, std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);