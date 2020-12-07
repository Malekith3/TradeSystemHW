#include "Header/Seller.h"

Seller::Seller(const char* userName, const char* userPassword , const Address& address):sizeOfProductArray(0),numberOfProducts(0)
{
	std::cout << "Seller C'tor called \n";
	if (strlen(this->userPassword) >= strlen(userName))
	{
		strcpy(this->userPassword, userPassword);
		this->userName = new char[strlen(userName) + 1];
		strcpy(this->userName, userName);
		this->address = new Address(address);
	}
	else
		std::cout << "Max length of password is 10  . Object Seller is not initialized \n";
}

Seller::~Seller()
{
	std::cout << "Seller D'tor called \n";
	delete[] userName;
	delete address;
	if (this->sizeOfProductArray !=0)
	{
		for (int i = 0; i < this->numberOfProducts; ++i)
		{
			delete this->products[i];
		}
		delete[] this->products;
	}
}

void Seller::SetUserName(char* const userName)
{
	delete[] this->userName;
	this->userName = new char[strlen(userName) + 1];
	strcpy(this->userName, userName);
}

void Seller::SetUserPassword(const char* userPassword , const char* key)
{
	if (!strcmp(this->userPassword,key) && strlen(this->userPassword) >= strlen(userName))
	{
		strcpy(this->userPassword, userPassword);
		std::cout << "Password is changed \n";
	}
	else
		std::cout << "key need to be previous password ! please enter the right one \n ";
}

Seller::Seller(const Seller& other) : numberOfProducts(other.numberOfProducts) , sizeOfProductArray(other.sizeOfProductArray)
{
	std::cout << "Seller copy C'tor called \n";
	if (strlen(this->userPassword) >= strlen(other.userName))
	{
		strcpy(this->userPassword, other.userPassword);
		this->userName = new char[strlen(other.userName) + 1];
		strcpy(this->userName, other.userName);
		this->address = new Address(*other.address);
	}
	else
		std::cout << "Max length of password is 10  . Object Seller is not initialized \n";
}

void Seller::AddProduct(const Product& product)
{

	if (this->numberOfProducts == this->sizeOfProductArray )
	{
		this->products = RealocateProductArray();
		this->products[numberOfProducts] = new Product (product);
		++this->numberOfProducts;
	}
	else
	{
		this->products[numberOfProducts] = new Product(product);
		++this->numberOfProducts;
	}
}

void Seller::PrintSeller(bool printAddress , bool printProducts )
{
	std::cout << "Seller name : " << this->userName << std::endl;
			  
	if (printAddress)
		this->address->PrintAddress();
	if (printProducts)
	{
		std::cout <<  "Seller products : " << std::endl;
		for (int i = 0; i < this->numberOfProducts; ++i)
		{
			std::cout << "Product number " << i << "  :\n";
			this->products[i]->PrintProduct();
		}
	}
}

Product** Seller::RealocateProductArray()
{
	Product** buffer = new Product * [this->sizeOfProductArray + 2];
	this->sizeOfProductArray += 2;
	if (this->numberOfProducts == 0)
	{
		return buffer;
	}
	else
	{
		for (int i = 0; i < this->numberOfProducts; ++i)
		{
			buffer[i] = this->products[i];
		}
		delete[] products;
		return buffer;
	}
}
