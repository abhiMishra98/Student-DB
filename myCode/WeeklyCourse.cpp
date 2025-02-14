/*
 * WeeklyCourse.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "WeeklyCourse.h"
using namespace std;

WeeklyCourse::WeeklyCourse()
{
	// TODO Auto-generated constructor stub

}

WeeklyCourse::WeeklyCourse(Poco::DateTime::DaysOfWeek &dayOfWeek,
		Poco::Data::Time &startTime, Poco::Data::Time &endTime,
		unsigned int &course, std::string &title, std::string major,
		float &creditPoints) :
		dayOfWeek
		{ dayOfWeek }, startTime
		{ startTime }, endTime
		{ endTime }, Course
		{ course, title, major, creditPoints }
{
}

Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return dayOfWeek;
}

std::string WeeklyCourse::getStartTime() const
{
	string strStartTime;
	strStartTime = to_string(startTime.hour()) + ":"
			+ to_string(startTime.minute());
	return strStartTime;
}

std::string WeeklyCourse::getEndTime() const
{
	string strEndTime;
	strEndTime = to_string(endTime.hour()) + ":" + to_string(endTime.minute());
	return strEndTime;
}

void WeeklyCourse::setDayOfWeek(Poco::DateTime::DaysOfWeek dayWeek)
{
	dayOfWeek = dayWeek;
}

void WeeklyCourse::setStartTime(int hour, int minute, int seconds)
{
	startTime.assign(hour, minute, seconds);
}

void WeeklyCourse::setEndTime(int hour, int minute, int seconds)
{
	endTime.assign(hour, minute, seconds);
}

void WeeklyCourse::printCourse() const
{
	string dayOfWeek;
	switch (getDayOfWeek())
	{
	case 0:
	{
		dayOfWeek = "SUNDAY";
		break;
	}
	case 1:
	{
		dayOfWeek = "MONDAY";
		break;
	}
	case 2:
	{
		dayOfWeek = "TUESDAY";
		break;
	}
	case 3:
	{
		dayOfWeek = "WEDNESDAY";
		break;
	}
	case 4:
	{
		dayOfWeek = "THURSDAY";
		break;
	}
	case 5:
	{
		dayOfWeek = "FRIDAY";
		break;
	}
	case 6:
	{
		dayOfWeek = "SATURDAY";
		break;
	}
	default:
		break;
	}
	Course::printCourse();
	std::cout << "Day of week: " << dayOfWeek << std::endl << "Start time: "
			<< getStartTime() << std::endl << "End time: " << getEndTime()
			<< std::endl;
}

void WeeklyCourse::write(std::ostream &out) const
{
	out << "W;";
	Course::write(out);
	out << ";" << getDayOfWeek() << ";" << getStartTime() << ";"
			<< getEndTime();
}

void WeeklyCourse::read(std::istream &in)
{
	string token;
	vector<string> fields;
	while (getline(in, token, ';'))
	{
		fields.push_back(token);
	}
	setDayOfWeek(static_cast<Poco::DateTime::DaysOfWeek>(stoi(fields[5])));
	Poco::Data::Time startTime, endTime;
	std::istringstream stimeStream(fields[6]);
	std::istringstream etimeStream(fields[7]);
	int hours, minutes;
	char sdelimiter;
	if (stimeStream >> hours >> sdelimiter >> minutes && sdelimiter == ':'
			&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
	{
		setStartTime(hours, minutes, 0);
	}
	hours = minutes = 0;
	if (etimeStream >> hours >> sdelimiter >> minutes && sdelimiter == ':'
			&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
	{
		setEndTime(hours, minutes, 0);
	}
	setTitle(fields[2]);
	float creditPointsValue = static_cast<float>(atof(fields[4].c_str()));
	setCreditPoints(creditPointsValue);
	unsigned char newMajor = static_cast<unsigned char>((fields[3])[0]);
	setMajor(newMajor);
	unsigned int courseKey = static_cast<unsigned int>(stoi(fields[1]));
	setCourseKey(courseKey);
	setMajorById(newMajor, fields[3]);
}

std::ostream& operator<<(std::ostream &cout, const WeeklyCourse &wCourse)
{
	string dayOfWeek;
	switch (wCourse.getDayOfWeek())
	{
	case 0:
	{
		dayOfWeek = "SUNDAY";
		break;
	}
	case 1:
	{
		dayOfWeek = "MONDAY";
		break;
	}
	case 2:
	{
		dayOfWeek = "TUESDAY";
		break;
	}
	case 3:
	{
		dayOfWeek = "WEDNESDAY";
		break;
	}
	case 4:
	{
		dayOfWeek = "THURSDAY";
		break;
	}
	case 5:
	{
		dayOfWeek = "FRIDAY";
		break;
	}
	case 6:
	{
		dayOfWeek = "SATURDAY";
		break;
	}
	default:
		break;
	}
	cout << "Day of week:" << dayOfWeek << std::endl << "Start time:"
			<< wCourse.getStartTime() << std::endl << "End time:"
			<< wCourse.getEndTime();
	return cout;
}

WeeklyCourse::~WeeklyCourse()
{
// TODO Auto-generated destructor stub
}

