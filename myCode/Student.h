/*
 * Student.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *      @brief - Class implementation for students of the student db application
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Enrollment.h"
#include "Address.h"

#include <iostream>
#include <vector>
#include <sstream>

#include <Poco/Data/Date.h>

class Student
{
private:
	static unsigned int nextMatrikelNummer;/**<stores the next matrikel number*/
	unsigned int matrikelNummer;/**<stores the student's matrikel number*/
	std::string firstName;/**<stores student's first name*/
	std::string lastName;/**<stores student's last name*/
	Poco::Data::Date dateOfBirth;/**<stores student's date of birth*/
	std::vector<Enrollment> enrollments;/**<stores student's enrollments*/
	Address address;
public:
	/**
	 * @brief Constructor to create a student object
	 */
	Student();
	/**
	 * @brief Constructor to create a student object based on first name, last name, date of birth and address object
	 */
	Student(std::string &fName, std::string &lName, Poco::Data::Date &dob,
			Address &address);
	/**
	 * @brief Constructor to create a student object based on first name, last name, date of birth and address inputs
	 */
	Student(std::string &fName, std::string &lName, Poco::Data::Date &dob,
			std::string &street, unsigned short postalCode,
			std::string &cityName, std::string &additionalInfo);
	/**
	 * @brief method to fetch user input for student details
	 */
	void enterStudentDetails();
	/**
	 * @brief getter method to get the DOB of student
	 */
	const Poco::Data::Date& getDateOfBirth() const;
	/**
	 * @brief setter method to set the DOB of student
	 */
	void setDateOfBirth(const Poco::Data::Date &dateOfBirthNew);
	/**
	 * @brief getter method to get the first name of the student
	 */
	const std::string& getFirstName() const;
	/**
	 * @brief setter method to set the first name of the student
	 */
	void setFirstName(const std::string &studFirstName);
	/**
	 * @brief setter method to get the last name of the student
	 */
	const std::string& getLastName() const;
	/**
	 * @brief setter method to set the last name of the student
	 */
	void setLastName(const std::string &studLastName);
	/**
	 * @brief getter method to get the matrikel number of the student
	 */
	unsigned int getMatrikelNummer() const;
	/**
	 * @brief setter method to set the matrikel number of the student
	 */
	void setMatrikelNummer();
	/**
	 * @brief setter method to get the matrikel number of the student with matNr as input
	 * @param matNr- set the matNr for the student
	 */
	void setMatrikelNummer(unsigned int &matNr);
	/**
	 * @brief getter method to get the address details of the student
	 */
	Address getAddress() const;
	/**
	 * @brief getter method to get the next matrikel number
	 */
	static unsigned int getNextMatrikelNummer();
	/**
	 * @brief method to add enrollments to the student vector enrollments
	 * @param enrollment - enrollment object
	 */
	void addEnrollments(Enrollment &enrollment);
	/**
	 * @brief getter method to get the enrollments for the student
	 */
	std::vector<Enrollment> getEnrollments() const;
	friend std::ostream& operator<<(std::ostream &out,
			const Poco::Data::Date &dateObj);
	/**
	 * @brief method to write student details to a csv file
	 */
	void write(std::ostream &out) const;
	/**
	 * @brief method to read student details from a csv file
	 */
	void read(std::istream &in);
	virtual ~Student();
	friend std::ostream& operator<<(std::ostream &out, const Student &student);

};

#endif /* STUDENT_H_ */
