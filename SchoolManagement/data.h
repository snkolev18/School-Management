#pragma once
#include "structures.h"

STUDENT inputStudent(std::vector<STUDENT> students, std::vector<TEACHER> teachers);

bool checkForExistingEmail(std::vector<STUDENT> students, std::vector<TEACHER> teachers, std::string email);

TEACHER inputTeacher();

std::string addRole(std::vector<std::string> whiteListedRoles);

void writeRolesInTxt(std::vector<std::string> roles);

std::vector<std::string> readRolesFromTxt();

void removeRole(std::vector<std::string>& roles, int id);

bool checkForExistingEmailStudents(std::vector<STUDENT> students, std::string email);

bool checkForExistingEmailTeachers(std::vector<TEACHER> teachers, std::string email);

bool checkIfRoleIsWhiteListed(std::vector<std::string> whiteListedRoles, std::string role);

STUDENT findStudentByEmail(std::vector<STUDENT> students, std::string email);

int findIndexByEmailTeachers(std::vector<TEACHER> teachers, std::string email);

TEACHER findTeacherByEmail(std::vector<TEACHER> teachers, std::string email);

CUSTOM_TEAM inputTeam(std::vector<std::string> whiteListedRoles, std::vector<STUDENT> students, std::vector<TEACHER>& teachers);