#include "../Header/ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart(const Product& product)
{
	++this->numberOfProducts;
	this->sizeOfCartArray += 2;
	this->products = new Product*[sizeOfCartArray];
	this->products[numberOfProducts] = new Product(product);
}

//mby need to be reimplemented for now its very costly

ShoppingCart::ShoppingCart(const ShoppingCart& other):sizeOfCartArray(sizeOfCartArray),numberOfProducts(numberOfProducts)
{
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
			std::cout << "Product Name: " << this->products[i]->GetNameOfProduct() << std::endl
					  << "Product Price: " << this->products[i]->GetPriceOfProduct() << std::endl
					  << "Product type: " << this->products[i]->GetProductType() << std::endl;
		}
	}
}

void ShoppingCart::EmptyTheShoppingCart()
{
	RealocateProductArray();
	this->numberOfProducts = 0;
	this->sizeOfCartArray = 0;
}

Product** ShoppingCart::RealocateProductArray()
{
	this->sizeOfCartArray += 2;
	Product** buffer = new Product*[sizeOfCartArray];
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
	for (int i = 0; i < this->numberOfProducts; ++i)
	{
		delete this->products[i];
	}
	delete[] this->products;
}
