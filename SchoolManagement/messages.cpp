#include <iostream>
#include "structures.h"
#include "messages.h"
using namespace std;

void badGrade() 
{
	cout << ERROR_MSG_CR << "This is cringe grade" << endl;
	cout << "Please enter a valid one: " << CLOSE_ERR_MSG;
}

void badEmail()
{
	cout << ERROR_MSG_CR << "This email is not valid " << endl;
	cout << "Please try again: " << CLOSE_ERR_MSG;
}

void badName(std::string ns) 
{
	cout << ERROR_MSG_CR << ns + " is incorrect" << endl;
	cout << "Re-Enter a correct " + ns + ": " << CLOSE_ERR_MSG;
}

void updateMsgs(string email, string who, string what) 
{
	cout << endl;
	cout << INFO_MSG_CR << "Enter new " + what + " of a " + who + " with email [ "
		<< RESET_COLOR << email << CLOSE_RESET_COLOR
		<< INFO_MSG_CR << " ]" << " : " << CLOSE_INFO_MSG;
}

void badTeam() 
{
	cout << ERROR_MSG_CR << "This team name is invalid or doesn't exist " << CLOSE_ERR_MSG << endl;
	cout << ERROR_MSG_CR << "Please enter a correct name of a team: " << CLOSE_ERR_MSG;
}

void incorrectEmail(std::string ts)
{
	cout << ERROR_MSG_CR << "There is no " + ts + " with this email or it's incorrectly inputted" << endl;
	cout << "Please enter an email of a " + ts + ": " << CLOSE_ERR_MSG;
}