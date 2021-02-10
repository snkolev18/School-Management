#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "structures.h"
#include "functions.h"
#include "data.h"
#include "userInterface.h"
using namespace std;

string STUDENT::delimitInfo() {
	string result = "";

	result += name;
	result += "|" + surname;
	result += "|" + grade;
	result += "|" + role;
	result += "|" + email + "|";

	return result;
}


int main()
{
	ofstream file;

	file.open("students.txt", ios::app);


	vector<STUDENT> students;
	students.push_back({ "Stoyan", "Kolev", "10A", "QA", "SNKolev18@codingburgas.bg" });
	students.push_back({ "Jekata", "Velikov", "10A", "Backend", "DMKalchev18@codingburgas.bg" });
	students.push_back({ "Ili qm", "Ili ne", "10A", "Backend", "ILIQM18@codingburgas.bg" });
	students.push_back({ "Life", "Georgiev", "Turkey", "Frontend", "GKGeorgiev@codingburgas.bg" });


	if (file.is_open())
	{
		for (size_t i = 0; i < 4; i++)
		{
			file << students[i].delimitInfo();
			file << endl;
		}
		file.close();
	}
}