#pragma once
#include <fstream>
#include <vector>
#include <string>

// ######### Restrictions ##########
#define MAX_NAME_SIZE 15
#define MAX_TEAM_DESCRIPTION 25
#define MAX_EMAIL_SIZE 40
#define MAX_TEAMNAME_SIZE 25
#define MIN_NAME_SIZE 3
// #################################

// ######### MESSAGE COLORS ########
#define ERROR_MSG_CR "\033[31;31m"
#define CLOSE_ERR_MSG "\033[31;0m"
#define EXCEPTION_MSG_CR "\033[33;33m"
#define CLOSE_EXC_MSG "\033[33;0m"
#define INFO_MSG_CR "\033[92;92m"
#define CLOSE_INFO_MSG "\033[92;0m"
#define RESET_COLOR "\033[97;97m"
#define CLOSE_RESET_COLOR "\033[97;0m"
// #################################


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
	void parseLogs(std::string currLine);
};

// Compilator and linker should know about this variable whenever
// is structures.h included
extern LOG logger;
