#pragma once

struct STUDENT 
{
	std::string name = "";
	std::string surname = "";
	std::string grade = "";
	std::string email = "";

	std::string delimitInfo();
};

struct TEACHER 
{
	std::string name = "";
	std::string surname = "";
	std::vector<std::string> teams;
	std::string email = "";
};

// vector Students
// vector Teachers 
// students.txt and teachers.txt | 
struct ROLES
{
	std::string role;
	std::string student;
};
struct CUSTOM_TEAM
{
	// .reserve() might fix it
	std::vector<ROLES> roles;
	std::string teamName = "";
	std::string status = "";
	std::vector<STUDENT> students;
	TEACHER teacher;
};

