#pragma once
#include "structures.h"

STUDENT inputStudent();

std::string addRole();

void writeRolesInTxt(std::vector<std::string> roles);

std::vector<std::string> readRolesFromTxt();

void removeRole(std::vector<std::string>& roles, int id);