#pragma once
#include "structures.h"
#include <vector>
#include <string>

bool checkForExistingEmail(std::vector<STUDENT> students, std::vector<TEACHER> teachers, std::string email);

bool checkForExistingEmailStudents(std::vector<STUDENT> students, std::string email);

bool checkForExistingEmailTeachers(std::vector<TEACHER> teachers, std::string email);

bool checkIfRoleIsWhiteListed(std::vector<std::string> whiteListedRoles, std::string role);

bool checkIfTeamNameIsUsed(const std::vector<TEAM> teams, const std::string name);

bool checkEmailValidity(std::string email);

bool checkGrade(std::string grade);

bool checkNameValidity(std::string name);

bool checkStrInput(const std::string inp_);

bool checkTeamNameLength(std::string name);

bool checkTeamDescriptionLength(std::string description);

bool checkProjectDescription(std::string description);

bool checkDateStandart(std::string date);

void badChoice(int& option);

void teachersEmpty(std::vector<TEACHER> teachers, std::vector<STUDENT> students);

void badChoiceFiltering(int& option);

bool isDataEmpty(SCHOOL school);

bool checkProjectNameLength(const std::string name);