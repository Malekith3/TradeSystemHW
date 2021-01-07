#include "Header/Buyer.h"
#include "Header/Order.h"
Buyer::Buyer(char* userName, char* userPassword, const Address& address)
{
	//std::cout << "Buyer C'tor called \n";
	if (strlen(this->userPassword) >= strlen(userName))
	{
		strcpy(this->userPassword, userPassword);
		this->userName = new char[strlen(userName) + 1];
		strcpy(this->userName, userName);
		this->address =  address;
		this->shopingCart =  ShoppingCart();
	}
	else
		std::cout << "Max length of password is 10  . Object Seller is not initialized \n";
}

Buyer::Buyer(const Buyer& other)
{
	if (strlen(this->userPassword) >= strlen(other.userName)) {
		//std::cout << "Buyer copy C'tor called \n";
		strcpy(this->userPassword, other.userPassword);
		this->userName = new char[strlen(other.userName) + 1];
		strcpy(this->userName, other.userName);
		this->address =  other.address;
		this->shopingCart =  other.shopingCart;
	}
	else
		std::cout << "Max length of password is 10  . Object Seller is not initialized \n";
}

Buyer& Buyer::operator=(const Buyer& other)
{
	if (this == &other)
		return *this;
	this->userName = strdup(other.userName);
	this->address = other.address;
	this->shopingCart = other.shopingCart;
	return *this;
}

Buyer::~Buyer()
{
	//std::cout << "Buyer D'tor called \n";
	delete[] userName;

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
	std::cout << "Buyer name : " << this->userName << std::endl;
	if (printAddress)
		this->address.PrintAddress();
	if (printShoppingCart)
		this->shopingCart.PrintShopingCart();
}


bool Buyer::SetUserPassword(const char* userPassword, const char* key)
{
	if (!strcmp(this->userPassword, key) && strlen(this->userPassword) >= strlen(userName))
	{
		strcpy(this->userPassword, userPassword);
		std::cout << "Password is changed \n";
		return true;
	}
	else
	{
		std::cout << "key need to be previous password ! please enter the right one \n ";
		return false;
	}
}

bool Buyer::SetUserName(char* const userName)
{
	delete[] this->userName;
	this->userName = new char[strlen(userName) + 1];
	strcpy(this->userName, userName);
	return true;
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
