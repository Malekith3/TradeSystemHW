#ifndef __ADDRESS_H__
#define __ADDRESS_H__
class Address
{
	char* streetName;
	int buildingNumber;
	char* city;
	char* country;

public:
	//***************************Constructors*************************************
	Address(const char* streetName, int buildingNumber, const char* city, const char* country);
	Address() = default;
	
	//***************************Copy Ctor****************************************
	Address(const Address& other);
	Address& operator=(const Address& other);
	//***************************Destructor***************************************
	~Address();

	//***************************Methods******************************************
	void PrintAddress() const;

	//***************************Getters & Setters********************************
	Address& SetStreetName(const char* streetName);
	Address& SetBuildingNumber(const int& buiildingNumber);
	Address& SetCity(const char* city);
	Address& SetCountry(const char* country);

	const char* GetStreetName() const { return this->streetName; }
	const int& GetBuildingNumber() const { return this->buildingNumber; }
	const char* GetCity() const { return this->city; }
	const char* GetCountry() const { return this->country; }

	//****************************************************************************
};

#endif

