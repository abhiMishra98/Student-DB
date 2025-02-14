/*
 * Enrollment.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "Enrollment.h"

Enrollment::Enrollment()
{
	// TODO Auto-generated constructor stub

}

void Enrollment::addEnrollment()
{
}

Enrollment::Enrollment(float grade, std::string semester, const Course *course) :
		grade
		{ grade }, semester
		{ semester }, course
		{ course }
{
}

void Enrollment::write(std::ostream &out) const
{
	out << getCourse()->getCourseKey() << ";" << getSemester() << ";"
			<< getGrade();
}

float Enrollment::getGrade() const
{
	return grade;
}

std::string Enrollment::getSemester() const
{
	return semester;
}

const Course* Enrollment::getCourse() const
{
	return course;
}

void Enrollment::read(std::istream &in)
{
}
std::ostream& operator<<(std::ostream &out, const Enrollment &enrollment)
{
	const Course *cPtr = enrollment.getCourse();
	out << "Semester:" << enrollment.getSemester() << std::endl << "Course:"
			<< cPtr->getCourseKey() << std::endl << "Grade:"
			<< enrollment.getGrade();
	return out;
}
Enrollment::~Enrollment()
{
	// TODO Auto-generated destructor stub
}

