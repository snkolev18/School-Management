#pragma once

struct STUDENT {
	std::string name = "";
	std::string surname = "";
	std::string grade = "";
	std::string role = "";
	std::string email = "";

	std::string delimitInfo();
};

struct TEACHER {
	std::string name = "";
	std::string familyName = "";
	std::string teamOwnership = "";
	std::string email = "";
	std::string status = "";
};

// vector Students
// vector Teachers 
// students.txt and teachers.txt | 

struct CUSTOM_TEAM
{
	std::string teamName = "";
	std::string status = "";
	std::vector<STUDENT> students;
	TEACHER teachers;
};

