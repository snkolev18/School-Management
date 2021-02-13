#pragma once
#include "structures.h"

bool checkForExistingEmail(std::vector<STUDENT> students, std::vector<TEACHER> teachers, std::string email);

bool checkForExistingEmailStudents(std::vector<STUDENT> students, std::string email);

bool checkForExistingEmailTeachers(std::vector<TEACHER> teachers, std::string email);

bool checkIfRoleIsWhiteListed(std::vector<std::string> whiteListedRoles, std::string role);

bool checkEmailValidity(std::string email);