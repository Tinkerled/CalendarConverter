#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <ctime>
#include <locale>
#include <iomanip>
using namespace std;

class Event
{
public:
	Event();
	~Event();

	string toString();
	string setDate(int);

	string date;
	int start;
	int end;
	string title;
	string prof;
	string desc;
	string uid;
	string startTime;
	string endTime;
};

