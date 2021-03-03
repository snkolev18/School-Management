#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "structures.h"
#include "data.h"

using namespace std;

bool LOGS::open(string filename)
{
	logFile.open(filename, ios::out | ios::app);
	return logFile.is_open();
}

void LOGS::close()
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

string LOGS::putLogMsg() 
{
	return "[" + date + " " + time + "]" + " " + severityToString(severity) + " " + information + '\n';
}

void LOGS::writeLogMsg(SEVERITY severity, string information)
{

	LOGS logEntry = { getDate().substr(0, getDate().find(' ')), getDate().substr(getDate().find(' ')), severity, information };
	logFile << logEntry.putLogMsg();

}

void LOGS::putLogMsg(SEVERITY severity, string information)
{
	ofstream logs;
	logs.open("logs.log", ios::app);
	logs << "[" + getDate().substr(0, getDate().find(' ')) + " " + getDate().substr(getDate().find(' ')) + "]" + " " + severityToString(severity) + " " + information + '\n';
	logs.close();
}

LOGS LOGS::parseLogs(string currLine) 
{
	LOGS audits;

	audits.date = currLine.substr(1, currLine.find(' '));
	currLine.erase(0, currLine.find(' ') + 1);
	audits.time = currLine.substr(0, currLine.find(']'));
	currLine.erase(0, currLine.find(']') + 1);
	audits.severity = severityToENUM(currLine.substr(0, currLine.find(' ')));
	currLine.erase(0, currLine.find(' ') + 1);
	audits.information = currLine.substr(0);

	return audits;
}

vector<LOGS> LOGS::readLogs() 
{
	vector<LOGS> audits;
	string currLog;
	if (open("logs.log")) 
	{
		while (getline(logFile, currLog)) 
		{
			audits.push_back(parseLogs(currLog));
		}
	}

	return audits;

}
