#include "Header/Address.h"
#include <iostream>
using namespace std;
Address::Address(const char* streetName, int buildingNumber, const char* city, const char* country)
{
	//cout << "c'tor of Address" << endl;		//for debugging only
	
	this->streetName = new char[strlen(streetName) + 1];
	this->city = new char[strlen(city) + 1];
	this->country = new char[strlen(country) + 1];
	this->buildingNumber = buildingNumber;

	strcpy(this->streetName, streetName);
	strcpy(this->city, city);
	strcpy(this->country, country);
}

Address::Address(const Address& other)
{
	//cout << "copy c'tor of Address" << endl;		//for debugging only
	this->streetName = new char[strlen(other.streetName) + 1];
	this->city = new char[strlen(other.city) + 1];
	this->country = new char[strlen(other.country) + 1];
	this->buildingNumber = other.buildingNumber;
	

	strcpy(this->streetName, other.streetName);
	strcpy(this->city, other.city);
	strcpy(this->country, other.country);
}

Address& Address::operator=(const Address& other)
{
	if (this == &other)
		return *this;

	this->streetName = strdup(other.streetName);
	this->city = strdup(other.city);
	this->country = strdup(other.country);
	this->buildingNumber = other.buildingNumber;
	return *this;
}

Address::~Address()
{
	//cout << "d'tor of Address" << endl;		//for debugging only
	delete[] this->country;
	delete[] this->city;
	delete[] this->streetName;
}


void Address::PrintAddress() const
{
	cout << "Country: " << this->country << endl << "City: " << this->city << endl << "Street name: " << this->streetName << endl << "Building number: " << this->buildingNumber << endl;
}

Address& Address::SetStreetName(const char* streetName)
{
	delete[] this->streetName;
	this->streetName = new char[strlen(streetName) + 1];
	strcpy(this->streetName, streetName);
	return *this;
}

Address& Address::SetBuildingNumber(const int& buiildingNumber)
{
	this->buildingNumber = buiildingNumber;
	return *this;
}

Address& Address::SetCity(const char* city)
{
	delete[] this->city;
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
	return *this;
}

Address& Address::SetCountry(const char* country)
{
	delete[] this->country;
	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	address.PrintAddress();
	return os;
}
