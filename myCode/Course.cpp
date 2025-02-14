/*
 * Course.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "Course.h"
using namespace std;

Course::Course()
{
	// TODO Auto-generated constructor stub

}

Course::Course(unsigned int courseKey, std::string title, std::string majorName,
		float creditPoints) :
		courseKey
		{ courseKey }, title
		{ title }, creditPoints
		{ creditPoints }
{
	major = static_cast<unsigned char>(majorName[0]);
	majorById.insert(
	{ major, majorName });
}

unsigned int Course::getCourseKey() const
{
	return courseKey;
}

void Course::setCourseKey(unsigned int &newCourseKey)
{
	courseKey = newCourseKey;
}

std::string Course::getTitle() const
{
	return title;
}

void Course::setTitle(std::string &newTitleName)
{
	title = newTitleName;
}

void Course::setCreditPoints(float &newCreditPoints)
{
	creditPoints = newCreditPoints;
}

float Course::getCreditPoints() const
{
	return creditPoints;
}

void Course::setMajorById(unsigned char &majorKey,
		std::string &majorStringValue)
{
	majorById.insert(
	{ majorKey, majorStringValue });
}

void Course::setMajor(unsigned char &newMajorChar)
{
	major = newMajorChar;
}

void Course::printCourse() const
{
	cout << "\n" << "Course Key: " << getCourseKey() << "\n" << "Title: "
			<< getTitle() << "\n" << "Credit Points: " << getCreditPoints()
			<< "\n" << "Major: " << getMajor() << "\n";
}

void Course::write(std::ostream &out) const
{
	out << getCourseKey() << ";" << getTitle() << ";" << getMajor() << ";"
			<< getCreditPoints();
}

// Overload the << operator to print Course details
std::ostream& operator<<(std::ostream &out, const Course &course)
{
	out << "Course Key: " << course.getCourseKey() << "\n" << "Title: "
			<< course.getTitle() << "\n" << "Credit Points: "
			<< course.getCreditPoints() << "\n" << "Major: "
			<< course.getMajor() << "\n";
	return out;
}

Course& Course::operator=(Course &&source)
{
	if (this == &source)
	{
		return *this;
	}

	majorById = std::move(source.majorById);
	courseKey = std::move(source.courseKey);
	title = std::move(source.title);
	major = std::move(source.major);
	creditPoints = std::move(source.creditPoints);
	return *this;
}

Course::~Course()
{
	// TODO Auto-generated destructor stub
}

std::string Course::getMajor() const
{
	return majorById.find(major)->second;
}


Course::Course(const Course &other) :
		majorById(other.majorById),
		courseKey(other.courseKey),
		title(other.title),
		major(other.major),
		creditPoints(other.creditPoints)
{

}

Course& Course::operator=(const Course &orig)
{
	if (this == &orig)
	{
		return *this;
	}
	majorById = orig.majorById;
	courseKey = orig.courseKey;
	title = orig.title;
	major = orig.major;
	creditPoints = orig.creditPoints;

	return *this;
}

Course::Course(Course &&source) :
		majorById(std::move(source.majorById)),
		courseKey(std::move(source.courseKey)),
		title(std::move(source.title)),
		major(std::move(source.major)),
		creditPoints(std::move(source.creditPoints))
{

}

void Course::read(std::istream &in)
{
	string token;
	vector<string> fields;
	while (getline(in, token, ';'))
	{
		fields.push_back(token);
	}
}
