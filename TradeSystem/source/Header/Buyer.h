#ifndef __BUYER_H
#define __BUYER_H

#include "ShoppingCart.h"
#include "Address.h"
class Order;

class Buyer
{
	char* userName;
	char userPassword[10];
	Address address;
	ShoppingCart shopingCart;
public:

	//***************************Constructors*************************************
	Buyer(char* userName,char* userPassword, const Address& address);
	//***************************Copy Ctor****************************************
	Buyer(const Buyer& other);
	Buyer& operator=(const Buyer& other);
	//***************************Destructor***************************************
	~Buyer();
	//***************************Getters & Setters********************************
	char* GetUserName() const {return userName;}

	bool SetUserPassword(const char* userPassword, const char* key);
	bool SetUserName(char* const userName);
	Address& ChangeAddress() { return this->address;}
	//***************************Operators****************************************
	friend bool operator>(const Buyer& buyer1, const Buyer& buyer2);
	friend std::ostream& operator<<(std::ostream& os, const Buyer& buyer);
	//***************************Methods******************************************
	void AddToShoppingCart(const Product& product) { this->shopingCart.AddProductToShopingCart(product); }
	const Order& OrderAndCheckout();
	void PrintBuyer(bool printAddress = false, bool printShoppingCart = false)const;
	//****************************************************************************


};
#endif
