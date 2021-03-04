#pragma once
#include "structures.h"


STUDENT findStudentByEmail(std::vector<STUDENT>& students, std::string& email);

TEACHER findTeacherByEmail(std::vector<TEACHER>& teachers, std::string& email);

int findIndexByEmailStudents(std::vector<STUDENT>& students, std::string& email);

int findIndexByEmailTeachers(std::vector<TEACHER>& teachers, std::string& email);

STUDENT inputStudent(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

TEACHER inputTeacher(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

std::string getDate();

TEAM inputTeam(std::vector<std::string>& whiteListedRoles, std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

void addRole(std::vector<std::string>& whiteListedRoles);

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

int maxSizeOfStrings(std::vector<std::string>& strings);

void removeStudent(std::vector<STUDENT>& students, std::string email);

void removeTeacher(std::vector<TEACHER>& teachers, std::string email);

void updateStudentData(std::vector<STUDENT>& students);

void updateTeacherData(std::vector<TEACHER>& teachers);

void deleteStudentData(std::vector<STUDENT>& students);

void deleteTeacherData(std::vector<TEACHER>& teachers);

void deleteTeamsData(std::vector<TEAM>& teams);

int findTeamByName(const std::vector<TEAM>& teams, const std::string name);

void updateTeamsData(std::vector<TEAM>& teams);

std::vector<STUDENT> findStudentsByClass(const std::vector<STUDENT>& students, const std::string& grade);

std::vector<STUDENT> findStudentsByName(const std::vector<STUDENT>& students, const std::string& name);

std::vector<STUDENT> findStudentsBySurname(const std::vector<STUDENT>& students, const std::string& surname);

std::vector<TEACHER> findTeachersByName(const std::vector<TEACHER>& teachers, const std::string& name);

std::vector<TEACHER> findTeachersBySurname(const std::vector<TEACHER>& teachers, const std::string& surname);

std::vector<TEACHER> findTeachersByNoTeams(const std::vector<TEACHER>& teachers);

std::vector<TEAM> findTeamsByTeacher(const std::vector<TEAM>& teams, const std::string& name);

std::vector<TEAM> findTeamsByStatus(const std::vector<TEAM>& teams, const std::string& status);