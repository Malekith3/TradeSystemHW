#ifndef __ADDRESS_H__
#define __ADDRESS_H__
#include <cstring>

class Address
{
	char* streetName;
	int buildingNumber;
	char* city;
	char* country;

public:
	//***************************Constructors*************************************
	Address(const char* streetName, int buildingNumber, const char* city, const char* country);
	
	//***************************Copy Ctor****************************************
	Address(const Address& other);

	//***************************Destructor***************************************
	~Address();

	//***************************Methods******************************************
	void PrintAddress();

	//***************************Getters & Setters********************************
	void SetStreetName(const char* streetName);
	void SetBuildingNumber(const int& buiildingNumber) { this->buildingNumber = buiildingNumber; }
	void SetCity(const char* city);
	void SetCountry(const char* country);

	const char* GetStreetName() { return this->streetName; }
	const int& GetBuildingNumber() { return this->buildingNumber; }
	const char* GetCity() { return this->city; }
	const char* GetCountry() { return this->country; }

	//****************************************************************************
};

#endif

