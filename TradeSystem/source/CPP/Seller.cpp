#include "Header/Seller.h"

Seller::Seller( const char* userName,  const char* userPassword ,const Address& address):User(userName,userPassword,address),sizeOfProductArray(0),numberOfProducts(0)
{
}

Seller::~Seller()
{

	if (this->sizeOfProductArray !=0)
	{
		for (int i = 0; i < this->numberOfProducts; ++i)
		{
			delete this->products[i];
		}
		delete[] this->products;
	}
}



Seller::Seller(const Seller& other) : numberOfProducts(other.numberOfProducts) , sizeOfProductArray(other.sizeOfProductArray), User(other)
{
}

void Seller::AddProduct(const Product& product)
{
	
	if (this->numberOfProducts == this->sizeOfProductArray )
	{
		this->products = RealocateProductArray();
		this->products[numberOfProducts] = &((new Product (product))->SetSeller(*this));
		++this->numberOfProducts;
	}
	else
	{
		this->products[numberOfProducts] = &((new Product(product))->SetSeller(*this));
		++this->numberOfProducts;
	}
}



void Seller::PrintSeller( bool printProducts ) const
{
	static_cast<User>(*this).PrintUser();
	
	
	if (printProducts)
	{
		if (this->numberOfProducts==0)
		{
			std::cout << "This seller has no products to sell" << std::endl;
			return;
		}
		std::cout <<  "Seller products : " << std::endl;
		for (int i = 0; i < this->numberOfProducts; ++i)
		{
			std::cout << "Product number " << i << "  :\n";
			this->products[i]->PrintProduct();
			std::cout << "Product ID: " << products[i]->id << std::endl;
		}
	}
}

Product** Seller::RealocateProductArray()
{
	if (this->sizeOfProductArray == 0)
		++this->sizeOfProductArray;
	this->sizeOfProductArray *= 2;
	Product** buffer = new Product * [this->sizeOfProductArray];
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
		delete products;
		return buffer;
	}
}

std::ostream& operator<<(std::ostream& os, const Seller& seller)
{
	seller.PrintSeller(true);
	return os;
}

int Seller::CheckOfProductExistence(const char* productName)
{
	for (int i = 0; i < this->numberOfProducts; ++i)
	{
		if (!strcmp(this->products[i]->GetNameOfProduct(), productName))
		{
			
			return products[i]->id;
		}
	}
	return 0;
}