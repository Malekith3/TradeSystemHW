#include "Header/Buyer.h"
#include "Header/Order.h"
Buyer::Buyer(const char* userName, const char* userPassword, const Address& address): User(userName,userPassword,address)
{
	//std::cout << "Buyer C'tor called \n";
}

Buyer::Buyer(const Buyer& other): User(other)
{
	this->shopingCart = other.shopingCart;
}

Buyer& Buyer::operator=(const Buyer& other)
{
	static_cast<User&>(*this) = other;
	this->shopingCart = other.shopingCart;
	return *this;
}


Order* Buyer::OrderAndCheckout() 
{
	if (this->shopingCart.GetNumberOfProducts() != 0)
	{
		Order* order = new Order(*this, shopingCart.CalculateCartSum());
		this->shopingCart.EmptyTheShoppingCart();
		return order;
	}
	else
		return  nullptr;
}

void Buyer::PrintBuyer( bool printShoppingCart)const
{
	static_cast<User>(*this).PrintUser();
	if (printShoppingCart)
		this->shopingCart.PrintShopingCart();
}



bool operator>(const Buyer& buyer1, const Buyer& buyer2)
{
	return buyer1.shopingCart.CalculateCartSum() > buyer2.shopingCart.CalculateCartSum();
}

std::ostream& operator<<(std::ostream& os, const Buyer& buyer)
{
	buyer.PrintBuyer(true);
	return os;
}
