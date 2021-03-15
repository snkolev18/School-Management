#pragma once
#include "structures.h"

std::string toStatus(int inp_);

STUDENT findStudentByEmail(std::vector<STUDENT>& students, std::string& email);

TEACHER findTeacherByEmail(std::vector<TEACHER>& teachers, std::string& email);

int findIndexByEmailStudents(std::vector<STUDENT>& students, std::string& email);

int findIndexByEmailTeachers(std::vector<TEACHER>& teachers, std::string& email);

int findIndexOfProjectByTeam(std::vector<TEAM_PROJECT> projects, std::string name);

int findIndexOfTeamByName(std::vector<TEAM> teams, std::string name);

int findIndexOfTeacherByEmail(const std::vector<TEACHER>& teachers, const std::string email);

STUDENT inputStudent(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

TEACHER inputTeacher(std::vector<STUDENT>& students, std::vector<TEACHER>& teachers);

std::string getDate();

TEAM inputTeam(std::vector<std::string>& whiteListedRoles, std::vector<STUDENT>& students, std::vector<TEACHER>& teachers, std::vector<TEAM>& teams);

void addRole(std::vector<std::string>& whiteListedRoles);

TEAM_PROJECT addProject(std::vector<TEAM_PROJECT>& projects);

void removeRole(std::vector<std::string>& roles, int& id);

void writeRolesInTxt(std::vector<std::string>& roles);

void writeStudentsInTxt(std::vector<STUDENT>& students);

void writeTeachersInTxt(std::vector<TEACHER>& teachers);

void writeTeamsInTxt(std::vector<TEAM>& teams);

void writeSchoolInTxt(std::string name, std::string city, std::string address);

void writeProjectsInTxt(std::vector<TEAM_PROJECT>& project, std::string fileName);

STUDENT parsedStudentInfo(std::string info);

TEACHER parsedTeacherInfo(std::string info);

TEAM parsedTeamInfo(std::string info);

TEAM_PROJECT parsedProjectInfo(std::string info);

std::vector<std::string> readRolesFromTxt();

std::vector<STUDENT> readStudentsFromTxt();

std::vector<TEACHER> readTeachersFromTxt();

std::vector<TEAM> readTeamsFromTxt();

std::vector<TEAM_PROJECT> readProjectsFromTxt(std::string fileName);

SCHOOL readSchoolFromTxt();

void removeStudentFromTeam(std::vector<ROLE>& students, std::string& email);

void addStudentToTeam(std::vector<ROLE>& students, ROLE& student);

int maxSizeOfStrings(std::vector<std::string>& strings);

void removeStudent(std::vector<STUDENT>& students, std::string email);

void removeTeacher(std::vector<TEACHER>& teachers, std::string email);

void removeTeamFromTeachers(std::vector<TEACHER>& teachers, const std::string teamName);

void updateTeamStudentEmail(int id, TEAM& team, std::string email);

void updateStudentData(std::vector<STUDENT>& students, std::vector<TEAM>& teams, std::vector<TEACHER>& teachers);

void updateTeacherData(std::vector<TEACHER>& teachers, std::vector<TEAM>& team);

void deleteStudentData(std::vector<STUDENT>& students, std::vector<TEAM>& teams);

void deleteTeacherData(std::vector<TEACHER>& teachers, std::vector<TEAM>& teams);

void deleteTeamsData(std::vector<TEAM>& teams, std::vector<TEACHER>& teachers);

int findTeamByName(const std::vector<TEAM>& teams, const std::string name);

void displayTeamsUpdateMenu();

void updateTeamStatus(TEAM& team, std::string status);

void updateTeamDescription(TEAM& team, std::string& description);

void updateTeamName(TEAM& team, std::string& name);

void updateTeamTeacher(TEAM& team, TEACHER& teacher);

void updateTeamStudent(TEAM& team, STUDENT& student, std::string& studentForReplacement);

void updateTeamsData(std::vector<TEAM>& teams, std::vector<TEACHER>& teachers,std::vector<STUDENT>& students);

std::vector<STUDENT> findStudentsByClass(const std::vector<STUDENT>& students, const std::string& grade);

std::vector<STUDENT> findStudentsByName(const std::vector<STUDENT>& students, const std::string& name);

std::vector<STUDENT> findStudentsBySurname(const std::vector<STUDENT>& students, const std::string& surname);

std::vector<TEACHER> findTeachersByName(const std::vector<TEACHER>& teachers, const std::string& name);

std::vector<TEACHER> findTeachersBySurname(const std::vector<TEACHER>& teachers, const std::string& surname);

std::vector<TEACHER> findTeachersByNoTeams(const std::vector<TEACHER>& teachers);

std::vector<TEAM> findTeamsByTeacher(const std::vector<TEAM>& teams, const std::string& name);

std::vector<TEAM> findTeamsByStatus(const std::vector<TEAM>& teams, const std::string& status);

void assignProjectToTeam(std::vector<TEAM>& teams, std::string& nameOfTheTeam, TEAM_PROJECT& project);

