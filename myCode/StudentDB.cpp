/*
 * StudentDB.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "StudentDB.h"

StudentDB::StudentDB()
{
	// TODO Auto-generated constructor stub

}

StudentDB::~StudentDB()
{
	// TODO Auto-generated destructor stub
}

void StudentDB::invokeClassMethod()
{
}

std::map<int, Student>& StudentDB::getStudents()
{
	return students;
}
const std::map<int, std::unique_ptr<const Course>>& StudentDB::getCourses() const
{
	return courses;
}

StudentDB::StudentDB(StudentDB &&source) :
		students(std::move(source.students)), courses(std::move(source.courses))
{
	source.students.clear();
	source.courses.clear();
}

StudentDB& StudentDB::operator =(StudentDB &&source)
{
	students.clear();
	courses.clear();

	students = std::move(source.students);
	courses = std::move(source.courses);

	source.students.clear();
	source.courses.clear();

	return *this;
}

StudentDB::StudentDB(const StudentDB &other) :
		students(other.students) // Copy the students map directly
{
	// Deep copy the courses map
	for (const auto &pair : other.courses)
	{
		courses[pair.first] = std::make_unique<const Course>(*pair.second);
	}
}

StudentDB& StudentDB::operator=(const StudentDB &orig)
{
	if (this == &orig)
	{
		// Self-assignment check
		return *this;
	}

	// Copy the students map
	students = orig.students;

	// Deep copy the courses map
	courses.clear(); // Clear existing data
	for (const auto &pair : orig.courses)
	{
		courses[pair.first] = std::make_unique<const Course>(*pair.second);
	}

	return *this;
}

std::map<int, Student>& StudentDB::updateStudentMap()
{
	return students;
}

void StudentDB::addStudents(unsigned int &matrikelNummer, Student &stud)
{
	students.insert(
	{ matrikelNummer, stud });
}

std::map<int, std::unique_ptr<const Course> >& StudentDB::getCourses()
{
	return courses;
}

void StudentDB::addCourses(unsigned int &courseId,
		std::unique_ptr<const Course> course)
{
	courses[courseId] = std::move(course);
}

void StudentDB::printCourses() const
{
	for (auto itr = courses.begin(); itr != courses.end(); ++itr)
	{
		if (itr->second) // Ensure the unique_ptr is not null
		{
			std::cout << "Course ID: " << itr->first << "\n";
			std::cout << "Course Title: " << itr->second->getTitle() << "\n";
			std::cout << "Course Major: " << itr->second->getMajor() << "\n";
			std::cout << "Credit Points: " << itr->second->getCreditPoints()
					<< "\n";
//			itr->second->
		}
	}
}

