/*
 * BlockCourse.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *      @brief - Class implementation to add block course.
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Course.h"

class BlockCourse: public Course
{
private:
	Poco::Data::Date startDate;/**<Start date of the course*/
	Poco::Data::Date endDate;/**<End date of the course*/
	Poco::Data::Time startTime;/**<Start time of the course*/
	Poco::Data::Time endTime;/**<End time of the course*/
public:
	/**
	 * @brief Constructor to create a block address object
	 *
	 */
	BlockCourse();
	/**
	 * @brief Constructor to create block address objects with start date, end date, start time, end time, course ID, title, major and credit points
	 * @param startDate - start date of the course of type Poco::Data date
	 * @param endDate - end date of the course of type Poco::Data date
	 * @param startTime - start time of the course of type Poco::Data time
	 * @param endTime - end time of the course of type Poco::Data time
	 * @param course - course ID of type unsigned int
	 * @param title - title of the course of type string
	 * @param major - major of the course of type string
	 * @param creditPoints - credits of the course of type float
	 */
	BlockCourse(Poco::Data::Date &startDate, Poco::Data::Date &endDate,
			Poco::Data::Time &startTime, Poco::Data::Time &endTime,
			unsigned int &course, std::string &title, std::string major,
			float &creditPoints);
	/**
	 * @brief Function to set the start Date
	 * @param year - year of start of the course of type int
	 * @param month - month of start of the course of type int
	 * @param day - date of start of the course of type int
	 */
	void setStartDate(int year, int month, int day);
	/**
	 * @brief Function to set the end Date
	 * @param year - year of end of the course of type int
	 * @param month - month of end of the course of type int
	 * @param day - date of end of the course of type int
	 */
	void setEnddate(int year, int month, int day);
	/**
	 * @brief Function to set the start time
	 * @param hour - hours in 24hr format when the course starts
	 * @param minute - minutes of type int when the course starts
	 */
	void setStartTime(int hour, int minute, int second);
	/**
	 * @brief Function to set the end time
	 * @param hour - hours in 24hr format when the course end
	 * @param minute - minutes of type int when the course ends
	 */
	void setEndTime(int hour, int minute, int second);
	/**
	 * @brief Virtual Function to print the block course details
	 */
	void printCourse() const override;
	/**
	 * @brief Virtual Function to write the contents of block course object to csv file
	 */
	virtual void write(std::ostream &out) const override;
	/**
	 * @brief Virtual Function to write the contents to block course object from csv file
	 */
	virtual void read(std::istream &in) override;
	/**
	 * @brief getter function to get the start date
	 */
	std::string getStartDate() const;
	/**
	 * @brief getter function to get the end date
	 */
	std::string getEndDate() const;
	/**
	 * @brief getter function to get the start time
	 */
	std::string getStartTime() const;
	/**
	 * @brief getter function to get the end time
	 */
	std::string getEndTime() const;
	virtual ~BlockCourse();
};

#endif /* BLOCKCOURSE_H_ */
