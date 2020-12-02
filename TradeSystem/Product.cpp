#include "Product.h"
#include <iostream>
const char* Product::productTypeStr[4] = {"Kids","Electronics","Office","Clothes"};

Product::Product(const char* name_of_poduct, int price_of_product, ProductType product_type)
	: priceOfProduct(price_of_product),
	productType(product_type)
{
	this->nameOfPoduct = new char[strlen(name_of_poduct) + 1];
	strcpy(this->nameOfPoduct, name_of_poduct);
}

void Product::SetNameOfProduct(char* name_of_poduct)
{
	delete[] this->nameOfPoduct;
	this->nameOfPoduct = new char[strlen(name_of_poduct) + 1];
	strcpy(this->nameOfPoduct, name_of_poduct);
}

Product::Product(const Product& other):
priceOfProduct(other.priceOfProduct),productType(other.productType)
{
	SetNameOfProduct(other.GetNameOfProduct());
}






