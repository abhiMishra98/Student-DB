/*
 * Course.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *      @brief - Class implementation for the abstract class course.
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>

class Course
{
private:
	std::map<unsigned char, std::string> majorById;/**<map storing major name by id*/
	unsigned int courseKey;/**<course key ID*/
	std::string title;/**<Title of the course*/
	unsigned char major;/**<Major name of the course*/
	float creditPoints;/**<credit points of the course*/
public:
	/**
	 * @brief Constructor to create a course object
	 *
	 */
	Course();
	/**
	 * @brief Constructor to create a course object
	 * @param coursekey - course id of type unsigned int
	 * @param title - title of the course of type string
	 * @param majorName - Course's major of type string
	 * @param creditPoints - credits of the course
	 */
	Course(unsigned int courseKey, std::string title, std::string majorName,
			float creditPoints);
	/**
	 * @brief getter function to get the course key
	 */
	unsigned int getCourseKey() const;
	/**
	 * @brief setter function to get the course key
	 * @param newCourseKey - coursekey passed as param of type unsigned int
	 */
	void setCourseKey(unsigned int &newCourseKey);
	/**
	 * @brief getter function to get title of the course
	 */
	std::string getTitle() const;
	/**
	 * @brief setter function to set title of the course
	 * @param newTitleName - newTitleName passed as param of type string
	 */
	void setTitle(std::string &newTitleName);
	/**
	 * @brief setter function to set title of the course
	 * @param newTitleName - newTitleName passed as param of type string
	 */
	void setCreditPoints(float &newCreditPoints);
	/**
	 * @brief getter function to get credit points
	 */
	float getCreditPoints() const;
	/**
	 * @brief getter function to get major name
	 */
	std::string getMajor() const;
	/**
	 * @brief setter function to set major id
	 * @param newMajorChar - major id of type unsigned char
	 */
	void setMajor(unsigned char &newMajorChar);
	/**
	 * @brief setter function to set major name
	 * @param majorKey - major id of type unsigned char
	 * @param majorStringValue - major name of type string
	 */
	void setMajorById(unsigned char &majorKey, std::string &majorStringValue);
	/**
	 * @brief copy constructor of course object
	 * @param other - object of type course
	 */
	Course(const Course &other);
	/**
	 * @brief copy assignment of course object
	 * @param orig - object of type course
	 */
	Course& operator=(const Course &orig);
	/**
	 * @brief move constructor of course object
	 * @param source - object of type course
	 */
	Course(Course &&source);
	/**
	 * @brief move assignment of course object
	 * @param source - object of type course
	 */
	Course& operator=(Course &&source);
	/**
	 * @brief virtual function to print the course details
	 */
	virtual void printCourse() const;
	/**
	 * @brief virtual function to write ostream contents to file
	 * @param out - out of type ostream
	 */
	virtual void write(std::ostream &out) const;
	/**
	 * @brief virtual function to read ostream contents from file
	 * @param in - in of type ostream
	 */
	virtual void read(std::istream &in);
	virtual ~Course();

	friend std::ostream& operator<<(std::ostream &out, const Course &course);
};

#endif /* COURSE_H_ */
