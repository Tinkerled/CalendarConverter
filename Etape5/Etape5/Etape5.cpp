#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <ctime>
#include <locale>
#include <iomanip>


#include "Event.h"

using namespace std;


int main()
{
	string line;
	int year = 2019;
	static int increment = 10000000;

	ifstream inFile;
	inFile.open("C:\\C++\\Horaire\\Horaire5.csv");

	ofstream outfile;
	outfile.open("C:\\C++\\Horaire\\OutputHoraire5.ics");
	if (outfile.is_open()) {
		outfile << "BEGIN:VCALENDAR\n";
		outfile << "PRODID : -//Google Inc//Google Calendar 70.9054//EN\n";
		outfile << "VERSION : 2.0\n";
		outfile << "CALSCALE : GREGORIAN\n";
		outfile << "METHOD : PUBLISH\n";
		outfile << "X - WR - CALNAME : Etape 4\n";
		outfile << "X - WR - TIMEZONE : America / Toronto\n";
		outfile << "X - WR - CALDESC : Groupe 286 LEA.3N\n";
			
			
			
	}
	
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	while (getline(inFile, line)) {
		
		stringstream ssin(line);
		string cours[6];
		//cout << "line";
		int i = 0;
		while (ssin.good() && i < 6 && cours[0] != "Date" ) {
			getline(ssin, cours[i], ',');
			increment++;

			if (i == 1 && cours[0] == "Date" || cours[0] == "") {

				//cout << "empty line" << endl;
				exit;
			}
			i++;
			//cout << i;
		}
		if (cours[0] != "Date" && cours[0] != "") {
			Event event;
			event.date = cours[0];
			event.start = stoi(cours[1])+4;
			event.end = stoi(cours[2])+4;
			event.title = cours[3];
			event.prof = cours[4];
			event.desc = cours[5];
			event.uid = to_string(increment);

			event.startTime = event.setDate(event.start);
			event.endTime = event.setDate(event.end);

			cout << event.toString();
			if (outfile.is_open()) {
				outfile << event.toString();
			}
		}
	}
	if (outfile.is_open()) {
		outfile << "END:VCALENDAR\n";
	}

	inFile.close();
	outfile.close();
}
