#include "Header/Buyer.h"
#include "Header/Order.h"
Buyer::Buyer(const char* userName, const char* userPassword, const Address& address): User(userName,userPassword)
{
	//std::cout << "Buyer C'tor called \n";
	this->address = address;
}

Buyer::Buyer(const Buyer& other): User(other)
{
	
	this->address = other.address;
	this->shopingCart = other.shopingCart;
}

Buyer& Buyer::operator=(const Buyer& other)
{
	static_cast<User&>(*this) = other;
	this->address = other.address;
	this->shopingCart = other.shopingCart;
	return *this;
}


const Order& Buyer::OrderAndCheckout() 
{
	if (this->shopingCart.GetNumberOfProducts() !=0)
	{
		Order* order = new Order(*this, shopingCart.CalculateCartSum());
		this->shopingCart.EmptyTheShoppingCart();
		return *order;
	}
	
}

void Buyer::PrintBuyer(bool printAddress, bool printShoppingCart)const
{
	std::cout << "Buyer name : " << std::endl;
	static_cast<User>(*this).PrintUser();
	if (printAddress)
		this->address.PrintAddress();
	if (printShoppingCart)
		this->shopingCart.PrintShopingCart();
}



bool operator>(const Buyer& buyer1, const Buyer& buyer2)
{
	return buyer1.shopingCart.CalculateCartSum() > buyer2.shopingCart.CalculateCartSum();
}

std::ostream& operator<<(std::ostream& os, const Buyer& buyer)
{
	buyer.PrintBuyer(true,true);
	return os;
}
