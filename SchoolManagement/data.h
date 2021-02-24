#pragma once
#include "structures.h"


STUDENT findStudentByEmail(std::vector<STUDENT>& students, std::string& email);

TEACHER findTeacherByEmail(std::vector<TEACHER>& teachers, std::string& email);

int findIndexByEmailStudents(std::vector<STUDENT>& students, std::string& email);

int findIndexByEmailTeachers(std::vector<TEACHER>& teachers, std::string& email);

STUDENT inputStudent(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

TEACHER inputTeacher(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

TEAM inputTeam(std::vector<std::string>& whiteListedRoles, std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

std::string addRole(std::vector<std::string>& whiteListedRoles);

void removeRole(std::vector<std::string>& roles, int& id);

void writeRolesInTxt(std::vector<std::string>& roles);

void writeStudentsInTxt(std::vector<STUDENT>& students);

void writeTeachersInTxt(std::vector<TEACHER>& teachers);

void writeTeamsInTxt(std::vector<TEAM>& teams);

STUDENT parsedStudentInfo(std::string info);

TEACHER parsedTeacherInfo(std::string info);

TEAM parsedTeamInfo(std::string info);

std::vector<std::string> readRolesFromTxt();

std::vector<STUDENT> readStudentsFromTxt();

std::vector<TEACHER> readTeachersFromTxt();

std::vector<TEAM> readTeamsFromTxt();

void removeStudentFromTeam(std::vector<ROLE>& students, std::string& email);

void addStudentToTeam(std::vector<ROLE>& students, ROLE& student);