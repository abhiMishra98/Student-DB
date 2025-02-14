/*
 * Address.cpp
 *
 *  Created on: 13-Jan-2025
 *      Author: abhim
 */

#include "Address.h"

using namespace std;

Address::Address()
{
	// TODO Auto-generated constructor stub
	street = "";
	postalCode = 0;
	cityName = "";
	additionalInfo = "";

}

Address::Address(std::string &streetName, unsigned short &pCode,
		std::string &cName, std::string &addInfo) :
		street
		{ streetName }, postalCode
		{ pCode }, cityName
		{ cName }, additionalInfo
		{ addInfo }
{
}

Address::~Address()
{
	// TODO Auto-generated destructor stub
}
void Address::enterAddressDetails()
{
	string street, cityName, additionalInfo;
	unsigned int postalCode;
	cout << "Enter street Name" << endl;
	getline(cin, street);
	cout << "Enter City name" << endl;
	getline(cin, cityName);
	setCityName(cityName);
	cout << "Enter additional info" << endl;
	getline(cin, additionalInfo);
	setAdditionalInfo(additionalInfo);
	setStreet(street);
	setPostalCode(postalCode);
}

const std::string& Address::getAdditionalInfo() const
{
	return additionalInfo;
}

void Address::setAdditionalInfo(const std::string &additionalInfo)
{
	this->additionalInfo = additionalInfo;
}

const std::string& Address::getCityName() const
{
	return cityName;
}

void Address::setCityName(const std::string &cityName)
{
	this->cityName = cityName;
}

unsigned short Address::getPostalCode() const
{
	return postalCode;
}

void Address::setPostalCode(unsigned short postalCode)
{
	this->postalCode = postalCode;
}

const std::string& Address::getStreet() const
{
	return street;
}

void Address::setStreet(const std::string &street)
{
	this->street = street;
}

std::ostream& operator<<(std::ostream &out, const Address &address)
{
	out << endl << "Street:" << address.getStreet() << "\n" << "City name:"
			<< address.getCityName() << endl << "Postal Code:"
			<< address.getPostalCode() << endl << "Additional Info:"
			<< address.getAdditionalInfo();
	return out;
}
