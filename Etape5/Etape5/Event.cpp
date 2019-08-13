#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

string Event::setDate(int time)
{
	stringstream ss(this->date);
	tm t = {};
	ss.imbue(locale("en_US.UTF8"));
	ss >> get_time(&t, "%b %d");
	t.tm_hour = time;
	stringstream out;
	out << put_time(&t, "2019%m%dT%H%M%SZ");

	return out.str();
}

string Event::toString()
{
	string output;

	output =
		"BEGIN:VEVENT\n" 
		"DTSTART:" + startTime + "\n"
		"DTEND:" + endTime + "\n"
		"UID:" + uid + "@lucas\n"
		"STATUS:CONFIRMED\n"
		"SUMMARY:" +title +" - " + prof +"\n"
		"DESCRIPTION:" +desc +"\n"
		"END:VEVENT\n\n";

	return output;
}

