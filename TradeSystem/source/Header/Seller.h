#ifndef __SELLER_H
#define  _SELLER_H

#include "Product.h"
#include "Address.h"
#include "User.h"

class Seller : public User
{
	Address address;
	int numberOfProducts;
	int sizeOfProductArray;
	Product** products;
	inline static int seedID = 1;
	
public:

	//***************************Constructors*************************************
	Seller(const char* userName,  const char* userPassword,const Address& address);
	//***************************Destructor***************************************
	~Seller();
	//***************************Getters & Setters********************************
	const int& GetNumberOfProducts() const {return numberOfProducts;}
	Address& ChangeAddress() { return this->address; }
	//***************************Copy Ctor****************************************
	Seller(const Seller& other);
	//***************************Operators****************************************
	friend std::ostream& operator<<(std::ostream& os, const Seller& seller);
	//***************************Methods******************************************
	void AddProduct(const Product& product);
	void PrintSeller(bool printAddress = false,bool printProducts=false) const;
private:
	friend class TradeSystem;
	int CheckOfProductExistence(const char* productName);
	Product** RealocateProductArray();
	//****************************************************************************
};



#endif
