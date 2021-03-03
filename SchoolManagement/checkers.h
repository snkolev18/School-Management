#pragma once
#include "structures.h"
#include <vector>
#include <string>

bool checkForExistingEmail(std::vector<STUDENT> students, std::vector<TEACHER> teachers, std::string email);

bool checkForExistingEmailStudents(std::vector<STUDENT> students, std::string email);

bool checkForExistingEmailTeachers(std::vector<TEACHER> teachers, std::string email);

bool checkIfRoleIsWhiteListed(std::vector<std::string> whiteListedRoles, std::string role);

bool checkEmailValidity(std::string email);

bool checkGrade(std::string grade);

bool checkNameValidity(std::string name);

bool checkTeamNameLength(std::string name);

bool checkTeamDescriptionLength(std::string description);