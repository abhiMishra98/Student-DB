/*
 * BlockCourse.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "BlockCourse.h"
using namespace std;
BlockCourse::BlockCourse()
{
	// TODO Auto-generated constructor stub

}

BlockCourse::BlockCourse(Poco::Data::Date &startDate, Poco::Data::Date &endDate,
		Poco::Data::Time &startTime, Poco::Data::Time &endTime,
		unsigned int &course, std::string &title, std::string major,
		float &creditPoints) :
		startDate
		{ startDate }, endDate
		{ endDate }, startTime
		{ startTime }, endTime
		{ endTime }, Course
		{ course, title, major, creditPoints }
{
}
void BlockCourse::setStartDate(int year, int month, int day)
{
	startDate.assign(year, month, day);
}

void BlockCourse::setEnddate(int year, int month, int day)
{
	endDate.assign(year, month, day);
}

void BlockCourse::setStartTime(int hour, int minute, int second)
{
	startTime.assign(hour, minute, second);
}

void BlockCourse::setEndTime(int hour, int minute, int second)
{
	endTime.assign(hour, minute, second);
}

std::string BlockCourse::getStartDate() const
{
	string strStartDate;
	strStartDate = to_string(startDate.year()) + "."
			+ to_string(startDate.month()) + "." + to_string(startDate.day());
	return strStartDate;
}

std::string BlockCourse::getEndDate() const
{
	string strEndDate;
	strEndDate = to_string(endDate.year()) + "." + to_string(endDate.month())
			+ "." + to_string(endDate.day());
	return strEndDate;
}

std::string BlockCourse::getStartTime() const
{
	string strStartTime;
	strStartTime = to_string(startTime.hour()) + ":"
			+ to_string(startTime.minute());
	return strStartTime;
}

std::string BlockCourse::getEndTime() const
{
	string strEndTime;
	strEndTime = to_string(endTime.hour()) + ":" + to_string(endTime.minute());
	return strEndTime;
}

void BlockCourse::printCourse() const
{
	Course::printCourse();
	cout << "Start Date:" << getStartDate() << endl << "End Date:"
			<< getEndDate() << endl << "Start Time:" << getStartTime() << endl
			<< "End Time:" << getEndTime() << endl;
}

void BlockCourse::write(std::ostream &out) const
{
	out << "B;";
	Course::write(out);
	out << ";" << getStartDate() << ";" << getEndDate() << ";" << getStartTime()
			<< ";" << getEndTime();
}

void BlockCourse::read(std::istream &in)
{
	string token;
	vector<string> fields;
	while (getline(in, token, ';'))
	{
		fields.push_back(token);
	}
	setTitle(fields[2]);
	float creditPointsValue = static_cast<float>(atof(fields[4].c_str()));
	setCreditPoints(creditPointsValue);
	unsigned char newMajor = static_cast<unsigned char>((fields[3])[0]);
	setMajor(newMajor);
	unsigned int courseKey = static_cast<unsigned int>(stoi(fields[1]));
	setCourseKey(courseKey);
	setMajorById(newMajor, fields[3]);

	int date, month, year, hours, minutes;
	string sStartDate, sEndDate, sStartTime, sEndTime;
	Poco::Data::Date startDate, endDate;
	Poco::Data::Time startTime, endTime;
	char delimiter; // To handle the '/' character
	std::istringstream sdateStream(fields[5]);
	sdateStream >> date >> delimiter >> month >> delimiter >> year;
	setStartDate(year, month, date);
	date = month = year = hours = minutes = 0;

	char edDelimiter; // To handle the '/' character
	std::istringstream edateStream(fields[6]);
	edateStream >> date >> edDelimiter >> month >> edDelimiter >> year;
	setEnddate(year, month, date);

	char sdelimiter;
	std::istringstream stimeStream(fields[7]);
	if (stimeStream >> hours >> sdelimiter >> minutes && sdelimiter == ':'
			&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
	{
		setStartTime(hours, minutes, 0);
	}
	else
	{
		std::cerr
				<< "Invalid time format. Please enter the time in hh:mm format."
				<< std::endl;
	}
	char edelimiter;
	std::istringstream etimeStream(fields[8]);
	if (etimeStream >> hours >> edelimiter >> minutes && edelimiter == ':'
			&& hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60)
	{
		setEndTime(hours, minutes, 0);
	}
	else
	{
		std::cerr
				<< "Invalid time format. Please enter the time in hh:mm format."
				<< std::endl;
	}

}

BlockCourse::~BlockCourse()
{
	// TODO Auto-generated destructor stub
}

