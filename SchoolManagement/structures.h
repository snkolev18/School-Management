#pragma once

struct STUDENT {
	std::string name = "";
	std::string surname = "";
	std::string team = "";
	std::string role = "";
	std::string email = "";
	std::string status = "";
	std::string username = "";
	std::string pass = "";
};

// vector Students
// vector Teachers 
// students.txt and teachers.txt | 

struct CUSTOM_TEAM
{
	std::string teamName;
	std::string status;
	vector<STUDENT> students;
	TEACHER teachers;
};

struct TEACHER {
	std::string name = "";
	std::string familyName = "";
	std::string teamOwnership = "";
	std::string email = "";
	std::string status = "";
};