#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "structures.h"
#include "utils.h"

using namespace std;

LOG logger;

bool LOG::open(string filename)
{
	logFile.open(filename, ios::out | ios::app);
	return logFile.is_open();
}

void LOG::close()
{
	logFile.close();
}

string severityToString(SEVERITY severity)
{
	switch (severity)
	{
	case CRITICAL:
		return "CRITICAL";
	case ERROR:
		return "ERROR";
	case WARNING:
		return "WARNING";
	case INFO:
		return "INFO";
	default:
		return "UNKOWN";

	}
}

SEVERITY severityToENUM(string severity) 
{
	if (severity == "CRITICAL") 
	{
		return SEVERITY::CRITICAL;
	}
	if (severity == "ERROR")
	{
		return SEVERITY::ERROR;
	}
	if (severity == "WARNING")
	{
		return SEVERITY::WARNING;
	}
	if (severity == "INFO")
	{
		return SEVERITY::INFO;
	}
}

string LOG::putLogMsg() 
{
	return "[" + date + " " + time + "]" + " " + severityToString(severity) + " " + information ;
}

void LOG::writeLogMsg(SEVERITY severity, string information)
{

	LOG logEntry = { getDate().substr(0, getDate().find(' ')), getDate().substr(getDate().find(' ')), severity, information };
	logFile << logEntry.putLogMsg() << endl;

}

void LOG::putLogMsg(SEVERITY severity, string information)
{
	ofstream logs;
	logs.open("logs.txt", ios::out | ios::app);
	
	logs << "[" + getDate().substr(0, getDate().find(' ')) + " " + getDate().substr(getDate().find(' ')) + "]" + " " + severityToString(severity) + " " + information + '\n';
	logs.close();
}

void LOG::parseLogs(string currLine) 
{
	LOG logger;

	logger.date = currLine.substr(1, currLine.find(' '));
	currLine.erase(0, currLine.find(' ') + 1);
	logger.time = currLine.substr(0, currLine.find(']'));
	currLine.erase(0, currLine.find(']') + 1);
	logger.severity = severityToENUM(currLine.substr(0, currLine.find(' ')));
	currLine.erase(0, currLine.find(' ') + 1);
	logger.information = currLine.substr(0);

	//return logger;
}

vector<LOG> LOG::readLogs() 
{
	vector<LOG> audits;
	string currLog;
	if (open("logs.txt")) 
	{
		while (getline(logFile, currLog)) 
		{
			//audits.push_back(parseLogs(currLog));
		}
	}

	return audits;

}
