/*
 * Enrollment.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *       @brief - Class implementation for the enrollments made by the students to a course
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <string>
#include "Course.h"

class Enrollment
{
private:
	float grade;/**<grade obtained by the student for that enrollment*/
	std::string semester;/**<semester in which the enrollment was made*/
	const Course *course;/**<pointer of type course pointing to the course enrolled in*/
public:
	/**
	 * @brief Constructor to create an enrollment
	 */
	Enrollment();
	/**
	 * @brief Constructor to create an enrollment object with inputs grade, semester as a string and course pointer
	 * @param grade - grade obtained in the course
	 * @param semester - semester enrolled in
	 * @param course - enrollment pointing to a course
	 */
	Enrollment(float grade, std::string semester, const Course *course);
	/**
	 * @brief Function to add an enrollment
	 */
	void addEnrollment();
	/**
	 * @brief getter function to get grades for the enrolled course
	 */
	float getGrade() const;
	/**
	 * @brief getter function to get the semester for the enrolled course
	 */
	std::string getSemester() const;
	/**
	 * @brief getter function to get pointer to the course object
	 */
	const Course* getCourse() const;
	/**
	 * @brief function to write the contents to a csv file
	 * @param out - ostream object
	 */
	void write(std::ostream &out) const;
	/**
	 * @brief Function to read the contents from a file
	 * @param in - istream object
	 */
	void read(std::istream &in);
	friend std::ostream& operator<<(std::ostream &out,
			const Enrollment &enrollment);
	virtual ~Enrollment();
};

#endif /* ENROLLMENT_H_ */
