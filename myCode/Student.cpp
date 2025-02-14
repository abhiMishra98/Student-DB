/*
 * Student.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "Student.h"
using namespace std;

unsigned int Student::nextMatrikelNummer = 1000000;

Student::Student()
{
	// TODO Auto-generated constructor stub
}

Student::Student(std::string &fName, std::string &lName, Poco::Data::Date &dob,
		Address &address) :
		firstName
		{ fName }, lastName
		{ lName }, dateOfBirth
		{ dob }, address
		{ address }
{
	setMatrikelNummer(); //sets matrikelnummer and increments as well
}

Student::Student(std::string &fName, std::string &lName, Poco::Data::Date &dob,
		std::string &street, unsigned short postalCode, std::string &cityName,
		std::string &additionalInfo) :
		firstName
		{ fName }, lastName
		{ lName }, dateOfBirth
		{ dob }, address
		{ street, postalCode, cityName, additionalInfo }
{
	setMatrikelNummer();
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

void Student::enterStudentDetails()
{
	string firstName, lastName;
	Poco::Data::Date dOfBirth;
	cout << "Enter student details:" << endl;
	cout << "First Name:" << endl;
	getline(cin, firstName);

	cout << "Last name" << endl;
	getline(cin, lastName);
	setLastName(lastName);
	setFirstName(firstName);

	Address enteredAddress;
	enteredAddress.enterAddressDetails();
	address = enteredAddress;
}

const Poco::Data::Date& Student::getDateOfBirth() const
{
	return dateOfBirth;
}

void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirthNew)
{
	Poco::Data::Date dateOfBirth = dateOfBirthNew;
	this->dateOfBirth = dateOfBirthNew;
}

const std::string& Student::getFirstName() const
{
	return firstName;
}

void Student::setFirstName(const std::string &studFirstName)
{
	this->firstName = studFirstName;
}

const std::string& Student::getLastName() const
{
	return lastName;
}

void Student::setLastName(const std::string &studLastName)
{
	this->lastName = studLastName;
}

unsigned int Student::getMatrikelNummer() const
{
	return matrikelNummer;
}

void Student::setMatrikelNummer()
{
	matrikelNummer = nextMatrikelNummer;
	nextMatrikelNummer++;
}

unsigned int Student::getNextMatrikelNummer()
{
	return nextMatrikelNummer;
}

std::ostream& operator<<(std::ostream &out, const Poco::Data::Date &dateObj)
{
	out << dateObj.year() << "/" << dateObj.month() << "/" << dateObj.day();
	return out;
}

void Student::addEnrollments(Enrollment &enrollment)
{
	enrollments.push_back(enrollment);
}

void Student::write(std::ostream &out) const
{
	out << getMatrikelNummer() << ";" << getFirstName() << ";" << getLastName()
			<< ";" << getDateOfBirth() << ";" << address.getStreet() << ";"
			<< address.getPostalCode() << ";" << address.getCityName();
}

void Student::read(std::istream &in)
{
	string token;
	vector<string> fields;
	while (getline(in, token, ';'))
	{
		fields.push_back(token);
	}
	setFirstName(fields[1]);
	setLastName(fields[2]);
	int day, month, year;
	Poco::Data::Date dob;
	char delimiter; // To handle the '/' character
	std::istringstream dateStream(fields[3]);
	dateStream >> year >> delimiter >> month >> delimiter >> day;
	dob.assign(year, month, day);
	setDateOfBirth(dob);
	unsigned int matNr = static_cast<unsigned int>(stoi(fields[0]));
	setMatrikelNummer(matNr);
	address.setStreet(fields[4]);
	address.setCityName(fields[6]);
	unsigned short pCode = static_cast<unsigned short>(std::stoi(fields[5]));
	address.setPostalCode(pCode);
}

void Student::setMatrikelNummer(unsigned int &matNr)
{
	matrikelNummer = matNr;
	nextMatrikelNummer = matNr + 1;
}

std::ostream& operator<<(std::ostream &out, const Student &student)
{
	out << "First name: " << student.getFirstName() << endl << "Last name: "
			<< student.getLastName() << endl << "Matrikel number:"
			<< student.getMatrikelNummer() << endl << "DOB: "
			<< student.getDateOfBirth() << endl << "Address"
			<< student.getAddress() << endl;

	const auto &enrollments = student.getEnrollments();
	if (!enrollments.empty())
	{
		out << "Enrollment data:" << endl;
		for (const auto &enrollment : enrollments)
		{
			out << enrollment;
		}
	}
	return out;
}

Address Student::getAddress() const
{
	return address;
}

std::vector<Enrollment> Student::getEnrollments() const
{
	return enrollments;
}
