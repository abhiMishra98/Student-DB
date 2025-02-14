/*
 * WeeklyCourse.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *      @brief - Class implementation for weekly courses.
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <Poco/DateTime.h>
#include <sstream>
#include "Course.h"

class WeeklyCourse: public Course
{
private:
	Poco::DateTime::DaysOfWeek dayOfWeek;/**<Poco::DateTime object storing day of the week*/
	Poco::Data::Time startTime;/**<Poco::Data object storing day start time*/
	Poco::Data::Time endTime;/**<Poco::Data object storing day end time*/
public:
	/**
	 * @brief Constructor to create a weekly course object
	 *
	 */
	WeeklyCourse();
	/**
	 * @brief Constructor to create a weekly course object with inputs day of the week, start time, end time, courseID, title of the subject, major name, credit points
	 * @param dayOfWeek - Poco::DateTime object of type daysOfWeek
	 * @param startTime - Poco::Data time object of type time
	 * @param endTime - Poco::Data time object of type time
	 * @param course - course ID of type unsigned int
	 * @param title - string of the course name
	 * @param major - string of the major name
	 * @param creditPoints - credit points of type float
	 *
	 */
	WeeklyCourse(Poco::DateTime::DaysOfWeek &dayOfWeek,
			Poco::Data::Time &startTime, Poco::Data::Time &endTime,
			unsigned int &course, std::string &title, std::string major,
			float &creditPoints);
	/**
	 * @brief method to get the day of the week
	 */
	Poco::DateTime::DaysOfWeek getDayOfWeek() const;
	/**
	 * @brief method to get start time
	 */
	std::string getStartTime() const;
	/**
	 * @brief method to get end time
	 */
	std::string getEndTime() const;
	/**
	 * @brief setter method to set the day of the week when this course is taught
	 */
	void setDayOfWeek(Poco::DateTime::DaysOfWeek dayWeek);
	/**
	 * @brief setter method to set the start time of the course
	 */
	void setStartTime(int hour, int minute, int seconds);
	/**
	 * @brief setter method to set the end time of the course
	 */
	void setEndTime(int hour, int minute, int seconds);
	/**
	 * @brief method to print all the courses
	 */
	void printCourse() const override;
	/**
	 * @brief method to write ostream contents of the weeklycourse to csv file
	 */
	virtual void write(std::ostream &out) const override;
	/**
	 * @brief method to read ostream contents from the file to the student db
	 */
	virtual void read(std::istream &in) override;
	virtual ~WeeklyCourse();
	friend std::ostream& operator<<(std::ostream &cout,
			const WeeklyCourse &wCourse);
};

#endif /* WEEKLYCOURSE_H_ */
