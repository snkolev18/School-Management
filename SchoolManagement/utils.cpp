#pragma warning(disable : 4996)
#define _POSIX_THREAD_SAFE_FUNCTIONS
#include <iostream>
#include <time.h>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <vector>
#include "structures.h"
#include "utils.h"
#include "file_io.h"
using namespace std;

string getDate()
{
	int day, month, year, hour, minute, second;
	string days, months, years, hours, minutes, seconds;

	time_t timer = time(NULL);
	tm timerPtr{ 0 };
	char* err = asctime(localtime(&timer));

	if (err == NULL)
	{
		return "Couldn't convert time";
	}

	timerPtr = *localtime(&timer);


	day = timerPtr.tm_mday;
	month = timerPtr.tm_mon + 1;
	year = timerPtr.tm_year + 1900;
	hour = timerPtr.tm_hour;
	minute = timerPtr.tm_min;
	second = timerPtr.tm_sec;

	seconds = to_string(second);
	minutes = to_string(minute);
	hours = to_string(hour);
	days = to_string(day);
	months = to_string(month);
	if (months.length() < 2)
	{
		months = "0" + months;
	}
	if (days.length() < 2)
	{
		days = "0" + days;
	}
	if (hours.length() < 2)
	{
		hours = "0" + hours;
	}
	if (minutes.length() < 2)
	{
		minutes = "0" + minutes;
	}
	if (seconds.length() < 2)
	{
		seconds = "0" + seconds;
	}

	years = to_string(year);

	return years + '-' + months + '-' + days + " " + hours + ":" + minutes + ":" + seconds;

}

// Checks if a status is valid and returns converted string version of it
string toStatus(int inp_)
{
	vector<int> valid = { 0, 1, 2, 3 };
	if (find(valid.begin(), valid.end(), inp_) == valid.end())
	{
		return "Vania";
	}
	if (inp_ == 3)
	{
		return "Vania";
	}
	return TEAM::statusToString((TEAM::STATUS)inp_);
}

void clearScreen()
{

#ifdef __linux__
	system("clear");
#else WIN32
	system("cls");
#endif

}

void switchEncoding(int what)
{
#ifdef __linux__
	system("echo \"Encoding is not ok, we know it, but luit didn't work\"");
#else WIN32
	switch (what)
	{
	case 1:
		system("chcp 65001 > NUL");
		break;
	case 2:
		system("chcp 437 > NUL");
		break;
	}
#endif // __linux__

}

// Converts enumeration code to string representation
string TEAM::statusToString(STATUS stat)
{
	switch (stat)
	{
	case IN_USE:
		return "In use";
	case NOT_ACTIVE:
		return "Not active";
	case ARCHIVED:
		return "Archived";
	default:
		return "Unknown Status";
	}
}