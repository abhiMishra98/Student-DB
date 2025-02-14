/*
 * StudentDB.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *       @brief - Class implementation for students db of the student db application
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include "Student.h"
#include "Course.h"
#include <map>
#include <memory>
#include <iostream>

class StudentDB
{
private:
	std::map<int, Student> students;/**<map containing matNr and student object*/
	std::map<int, std::unique_ptr<const Course>> courses; /**<map containing course id and course pointer*/
public:
	/**
	 * @brief Constructor to create a studentdb object
	 */
	StudentDB();
	/**
	 * @brief method to invoke class methods from different classes
	 */
	void invokeClassMethod();
	/**
	 * @brief copy constructor of studentdb object
	 * @param other - object of type studentdb
	 */
	StudentDB(const StudentDB &other);
	/**
	 * @brief copy assignment of studentdb object
	 * @param orig - object of type studentdb
	 */
	StudentDB& operator=(const StudentDB &orig);
	/**
	 * @brief move constructor of studentdb object
	 * @param source - object of type studentdb
	 */
	StudentDB(StudentDB &&source);
	/**
	 * @brief method to print courses stored in student db
	 */
	void printCourses() const;
	/**
	 * @brief move assignment of studentdb object
	 * @param source - object of type studentdb
	 */
	StudentDB& operator=(StudentDB &&source);
	/**
	 * @brief method to get the students map
	 */
	std::map<int, Student>& getStudents();
	/**
	 * @brief method to update the students map
	 */
	std::map<int, Student>& updateStudentMap();
	/**
	 * @brief getter method to get the courses map
	 */
	const std::map<int, std::unique_ptr<const Course>>& getCourses() const;
	/**
	 * @brief method to update the courses map
	 */
	std::map<int, std::unique_ptr<const Course>>& getCourses();
	/**
	 * @brief method to add students to the students map
	 */
	void addStudents(unsigned int &matrikelNummer, Student &stud);
	/**
	 * @brief method to add courses to the courses map
	 */
	void addCourses(unsigned int &courseId,
			std::unique_ptr<const Course> course);
	virtual ~StudentDB();
};

#endif /* STUDENTDB_H_ */
