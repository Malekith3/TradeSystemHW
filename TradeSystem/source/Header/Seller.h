#ifndef __SELLER_H
#define  _SELLER_H

#include "Product.h"
#include "Address.h"

class Seller
{
	char* userName;
	char userPassword[10];
	Address* address;
	int numberOfProducts;
	int sizeOfProductArray;
	Product** products;
	
public:

	//***************************Constructors*************************************
	Seller(const char* userName, const char* userPassword,const Address& address);
	//***************************Destructor***************************************
	~Seller();
	//***************************Getters & Setters********************************
	char* GetUserName() const { return userName; }
	const int& GetNumberOfProducts() const {return numberOfProducts;}

	bool SetUserName(char* const userName);
	bool SetUserPassword(const char* userPassword, const char* key);
	Address& ChangeAddress() { return *this->address; }
	//***************************Copy Ctor****************************************
	Seller(const Seller& other);
	//***************************Methods******************************************
	void AddProduct(const Product& product);
	void PrintSeller(bool printAddress = false,bool printProducts=false);
private:
	Product** RealocateProductArray();
	//****************************************************************************
};
#endif
