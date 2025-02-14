/*
 * Address.h
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 *       @brief - Class implementation to manage address of students.
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>
#include <iostream>
/**
 * @brief Represents address of students.
 *
 * This class stores the address details of students.
 */

class Address
{
private:
	std::string street;/**<Street name*/
	unsigned short postalCode;/**<Postal code */
	std::string cityName;/**<City name*/
	std::string additionalInfo;/**<Additional information*/
public:
	/**
	 * @brief Constructor to create address object and set the initial state.
	 *
	 */
	Address();
	/**
	 * @brief Constructor to create address with streetname,postal code, city name and additional info as inputs
	 * @param streetname - street name of type string
	 * @param pCode - postal code of type unsigned short
	 * @param cName - city name of type string
	 * @param addInfo - additional information on the address of type string
	 */
	Address(std::string &streetName, unsigned short &pCode, std::string &cName,
			std::string &addInfo);

	/**
	 * @brief getter function to get the additional information from address object
	 */
	const std::string& getAdditionalInfo() const;
	/**
	 * @brief setter function to set the additional information to address object
	 * @param additionalInfo - reference to the additionalInfo passed as input
	 */
	void setAdditionalInfo(const std::string &additionalInfo);
	/**
	 * @brief getter function to get the city name to address object
	 */
	const std::string& getCityName() const;
	/**
	 * @brief setter function to set city to address object
	 * @param cityName - reference to the additionalInfo passed as input
	 */
	void setCityName(const std::string &cityName);
	/**
	 * @brief getter function to get the postal code
	 */
	unsigned short getPostalCode() const;
	/**
	 * @brief setter function to set the postal code to address object
	 * @param postalCode - postal code of type unsigned short
	 */
	void setPostalCode(unsigned short postalCode);
	/**
	 * @brief getter function to get the street name
	 */
	const std::string& getStreet() const;
	/**
	 * @brief setter function to set street name to address object
	 * @param additionalInfo - reference to the street name of type string
	 */
	void setStreet(const std::string &street);
	/**
	 * @brief function to get inputs from user for address information
	 */
	void enterAddressDetails();
	virtual ~Address();
	friend std::ostream& operator<<(std::ostream &out, const Address &address);
};

#endif /* ADDRESS_H_ */
