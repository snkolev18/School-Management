#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"
#include "functions.h"
#include "data.h"
#include "userInterface.h"
using namespace std;

bool showMainMenu = true;

bool administratorMenu(vector<STUDENT>& students, vector<TEACHER>& teachers, vector<string>& whiteListedRoles, vector<TEAM>& teams)
{
    cout << endl;
    cout << "/-----------------------------------\\" << endl;
    cout << "Welcome to Administrator Menu!" << endl;
    cout << "(1) |Add Students|" << endl;
    cout << "(2) |Add Teachers|" << endl;
    cout << "(3) |Add Roles|" << endl;
    cout << "\\-----------------------------------/" << endl;

    int option, amount, counter = 0;
    cout << "->: "; cin >> option;


    switch (option)
    {
    case 1:
        cout << "Enter the amount of students: "; cin >> amount;
        while (counter < amount)
        {
            cin.ignore();
            students.push_back(inputStudent(students, teachers));
            writeStudentsInTxt(students);
            counter++;
        }
        counter = 0;
        break;

    case 2:
        cout << "Enter the amount of teachers: "; cin >> amount;
        while (counter < amount)
        {
            cin.ignore();
            teachers.push_back(inputTeacher(students, teachers));
            writeTeachersInTxt(teachers);
            counter++;
        }
        counter = 0;
        break;

    case 3:
        cout << "Enter the amount of teams: "; cin >> amount;
        while (counter < amount)
        {
            cin.ignore();
            teams.push_back(inputTeam(whiteListedRoles, students, teachers));
            writeRolesInTxt(whiteListedRoles);
            writeTeamsInTxt(teams);

            counter++;
        }
        counter = 0;
        break;

    default:
        cout << endl;
        cout << "|--------------------------|" << endl;
        cout << "Incorrect input, try again!" << endl;
        cout << "|--------------------------|" << endl;
        return false;
    }
    return true;
}

void mainMenu(string adminEmail, string adminPass, vector<STUDENT> students, vector<TEACHER> teachers, vector<string> whiteListedRoles, vector<TEAM> teams)
{
    bool flag = false;
    string em, pass;
    
    while (flag == false)
    {
        system("cls");
        cout << endl << u8R"( 
    ████████╗███████╗ █████╗ ███╗   ███╗███████╗ ██████╗ ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ███████╗████████╗
    ╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██╔════╝██╔═══██╗████╗  ██║██╔══██╗██║   ██║██╔══██╗██╔════╝ ██╔════╝╚══██╔══╝
       ██║   █████╗  ███████║██╔████╔██║███████╗██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║  ██║██║  ███╗█████╗     ██║   
       ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║╚════██║██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║  ██║██║   ██║██╔══╝     ██║   
       ██║   ███████╗██║  ██║██║ ╚═╝ ██║███████║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗   ██║   
       ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝   
                                                                                                                  
        )";

        cout << u8R"(

                                            ╔═════════════════════════════╗
                                            ║                             ║               
                                            ║  EMAIL:                     ║
                                            ║                             ║ 
                                            ║  PASSW:                     ║
                                            ║                             ║ 
                                            ╚═════════════════════════════╝
        )";

        getline(cin, em);
        getline(cin, pass);

        if (em == adminEmail and pass == adminPass)
        {
            do {
                showMainMenu = administratorMenu(students, teachers, whiteListedRoles, teams);
            } while (showMainMenu != false);
        }
        else
        {
            flag = false;
        }
    }
}