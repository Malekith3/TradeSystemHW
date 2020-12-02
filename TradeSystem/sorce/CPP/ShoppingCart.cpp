#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart(const Product& product)
{
	++this->numberOfProduct;
	this->sizeOfCartArray += 2;
	this->products = new Product*[sizeOfCartArray];
	this->products[numberOfProduct] = new Product(product);
}

void ShoppingCart::AddProductToShopingCart(const Product& product)
{
	if (sizeOfCartArray == numberOfProduct)
	{
		this->products = RealocateProductArray();
		this->products[numberOfProduct]= new Product(product);
		++numberOfProduct;
	}
	else
	{
		this->products[numberOfProduct] = new Product(product);
		++numberOfProduct;
	}
}

void ShoppingCart::PrintShopingCart() const
{
	for (int i = 0; i < numberOfProduct; ++i)
	{
		std::cout << "Product Name: " << this->products[i]->GetNameOfProduct() << std::endl
				  << "Product Price: " << this->products[i]->GetPriceOfProduct() << std::endl
			      << "Product type: " << this->products[i]->GetProductType() << std::endl;
	}
}

Product** ShoppingCart::RealocateProductArray()
{
	this->sizeOfCartArray += 2;
	Product** buffer = new Product*[sizeOfCartArray];
	if (this->numberOfProduct == 0)
	{
		return buffer;
	}
	else 
	{
		for (int i = 0; i < this->numberOfProduct; ++i)
		{
			buffer[i] = this->products[i];
		}
		delete[] products;
		return buffer;
	}
}

void ShoppingCart::ReleaseProductArray()
{
	for (int i = 0; i < this->numberOfProduct; ++i)
	{
		delete this->products[i];
	}
	delete[] this->products;
}
