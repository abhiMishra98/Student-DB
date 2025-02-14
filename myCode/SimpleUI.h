/*
 * SimpleUI.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *      @brief - Class implementation for the view of the student db application
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include "StudentDB.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"
#include <sstream>
#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class SimpleUI
{
private:
	StudentDB dataBase;/**<object of type student db*/
	boost::asio::ip::tcp::iostream stream;/**<object of type boost::tcp::iostream*/
public:
	/**
	 * @brief Constructor to create a simple ui object
	 */
	SimpleUI();
	/**
	 * @brief Constructor to create a simple UI object with student DB object as the input
	 */
	SimpleUI(StudentDB &db);
	/**
	 * @brief method to show options to the user
	 */
	int run();
	/**
	 * @brief method to invoke class methods based on choices
	 */
	void invokeClassMethod(unsigned int &choice);
	/**
	 * @brief method to add course in student db
	 */
	void addCourse();
	/**
	 * @brief method to print courses from the student db
	 */
	void printCourses();
	/**
	 * @brief method to add students to student db
	 */
	void addStudent();
	/**
	 * @brief method to add enrollments to student db
	 */
	void addEnrollment();
	/**
	 * @brief method to print students from student db
	 */
	void printStudents();
	/**
	 * @brief method to search students on student db
	 */
	void searchStudents();
	/**
	 * @brief method to update student details on student db
	 */
	void updateStudentDetails();
	/**
	 * @brief method to add write contents of student db to file
	 */
	void writeToFile();
	/**
	 * @brief method to read contents from file to student db
	 */
	void readFromFile();
	/**
	 * @brief method to fetch response from server
	 */
	void fetchAndParseData();
	virtual ~SimpleUI();
};

#endif /* SIMPLEUI_H_ */
