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

	std::string delimitInfo();
};

// vector Students
// vector Teachers 
// students.txt and teachers.txt | 
struct ROLE
{
	std::string role = "";
	STUDENT student;
};
struct TEAM
{
	// .reserve() might fix it
	std::vector<ROLE> roles;
	std::string teamName = "";
	TEACHER teacher;
	std::string description = "";
	std::string dateCreation = "";
	std::string status = "";

	std::string delimitInfo();
};

