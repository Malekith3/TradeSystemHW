#include "Header/ShoppingCart.h"

ShoppingCart::ShoppingCart(const Product& product):numberOfProducts(0),sizeOfCartArray(1)
{
	//std::cout << "ShopingCart Ctor called \n";
	this->products = new Product*[sizeOfCartArray];
	this->products[numberOfProducts] = new Product(product);
	++this->numberOfProducts;
}

//mby need to be reimplemented for now its very costly

ShoppingCart::ShoppingCart(const ShoppingCart& other):sizeOfCartArray(other.sizeOfCartArray),numberOfProducts(other.numberOfProducts)
{
	//std::cout << "ShopingCart copy Ctor called \n";
	this->products = new Product * [other.numberOfProducts];
	for (int i = 0; i < other.numberOfProducts; ++i)
	{
		this->products[i] = new Product(*other.products[i]);
	}
}

void ShoppingCart::AddProductToShopingCart(const Product& product)
{
	if (sizeOfCartArray == numberOfProducts)
	{
		this->products = RealocateProductArray();
		this->products[numberOfProducts]= new Product(product);
		++numberOfProducts;
	}
	else
	{
		this->products[numberOfProducts] = new Product(product);
		++numberOfProducts;
	}
}

void ShoppingCart::PrintShopingCart() const
{
	if (this->numberOfProducts == 0)
		std::cout << "Shopping Cart is empty \n";
	else 
	{
		for (int i = 0; i < numberOfProducts; ++i)
		{
			this->products[i]->PrintProduct();
		}
	}
}

bool ShoppingCart::EmptyTheShoppingCart()
{

	if (this->numberOfProducts != 0)
	{
		ReleaseProductArray();
		this->numberOfProducts = 0;
		this->sizeOfCartArray = 0;

		return true;

	}

	return false;
}




const int ShoppingCart::CalculateCartSum() const
{
	if (!this->GetNumberOfProducts())
	{
		return 0;
	}
	else
	{
		int summOfOrder = 0;
		for (int i = 0; i < this->GetNumberOfProducts(); ++i)
		{
			summOfOrder += this->products[i]->GetPriceOfProduct();
		}
		return summOfOrder;
	}
}


Product** ShoppingCart::RealocateProductArray()
{
	if (this->sizeOfCartArray==0)
		++this->sizeOfCartArray;
	this->sizeOfCartArray *= 2;
	Product** buffer = new Product*[this->sizeOfCartArray];
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

void ShoppingCart::ReleaseProductArray()
{
	//std::cout << "ShoppingCart D'tor called\n";
	if (this->numberOfProducts !=0)
	{
		for (int i = 0; i < this->numberOfProducts; ++i)
		{
			delete this->products[i];
		}
		delete this->products;
	}
	
}
