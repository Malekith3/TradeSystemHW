#ifndef __BUYER_H
#define __BUYER_H

#include "ShoppingCart.h"
#include "Address.h"
#include "User.h"
class Order;

class Buyer: public User
{
	Address address;
	ShoppingCart shopingCart;
public:

	//***************************Constructors*************************************
	Buyer(const char* userName,const char* userPassword, const Address& address);
	//***************************Copy Ctor****************************************
	Buyer(const Buyer& other);
	Buyer& operator=(const Buyer& other);
	//***************************Getters & Setters********************************
	Address& ChangeAddress() { return this->address;}
	//***************************Operators****************************************
	friend bool operator>(const Buyer& buyer1, const Buyer& buyer2);
	friend std::ostream& operator<<(std::ostream& os, const Buyer& buyer);
	//***************************Methods******************************************
	void AddToShoppingCart(const Product& product) { this->shopingCart.AddProductToShopingCart(product); }
	const Order& OrderAndCheckout();
	void PrintBuyer(bool printAddress = false, bool printShoppingCart = false) const;
	//****************************************************************************


};
#endif
