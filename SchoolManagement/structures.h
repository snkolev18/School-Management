#pragma once
#include <fstream>
#include <vector>
#include <string>

#define MAX_NAME_SIZE 15
#define MAX_TEAM_DESCRIPTION 25
#define MAX_EMAIL_SIZE 40
#define MAX_TEAMNAME_SIZE 40

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

struct ROLE
{
	std::string role = "";
	STUDENT student;
};


struct TEAM
{
	enum STATUS
	{
		IN_USE,
		NOT_ACTIVE,
		ARCHIVED
	};

	std::vector<ROLE> roles;
	std::string teamName = "";
	TEACHER teacher;
	std::string description = "";
	std::string dateCreation = "";
	
	std::string status = "";


	static std::string statusToString(STATUS stat);
	std::string delimitInfo();
};

struct SCHOOL
{
	std::string name;
	std::string city;
	std::string address;
	std::vector<TEACHER> teachers;
	std::vector<TEAM> teams;
	std::vector<STUDENT> students;
};

enum SEVERITY
{
	CRITICAL,
	ERROR,
	WARNING,
	INFO
};

struct LOG
{
	std::string date;
	std::string time;
	SEVERITY severity;
	std::string information;


	bool open(std::string filename);
	void close();
	std::string putLogMsg();
	static void putLogMsg(SEVERITY severity, std::string msg);
	void writeLogMsg(SEVERITY severity, std::string information);
	std::fstream logFile;

	std::vector<LOG> readLogs();
	static LOG parseLogs(std::string currLine);
};

extern LOG logger;
