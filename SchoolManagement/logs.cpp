#include <iostream>
#include <vector>
#include <fstream>
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

string LOGS::putLogMsg() 
{
	return "[" + date + " " + time + "]" + " " + severityToString(severity) + " " + information;
}

void LOGS::writeLogMsg(SEVERITY severity, string information)
{

	LOGS logEntry = { getDate().substr(0, getDate().find(' ')), getDate().substr(getDate().find(' ')), severity, information };
	logFile << logEntry.putLogMsg();

}