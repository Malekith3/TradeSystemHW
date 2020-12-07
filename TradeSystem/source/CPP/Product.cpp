#include "Header/Product.h"
const char* Product::productTypeStr[4] = {"Kids","Electronics","Office","Clothes"};

Product::Product(const char* name_of_poduct, const int& price_of_product, ProductType product_type)
	: priceOfProduct(price_of_product),
	productType(product_type)
{
	std::cout << "Product C'tor called \n";
	this->nameOfPoduct = new char[strlen(name_of_poduct) + 1];
	strcpy(this->nameOfPoduct, name_of_poduct);
}

void Product::SetNameOfProduct(char* name_of_poduct)
{
	delete[] this->nameOfPoduct;
	this->nameOfPoduct = new char[strlen(name_of_poduct) + 1];
	strcpy(this->nameOfPoduct, name_of_poduct);
}

void Product::PrintProduct() const
{
	std::cout << "Name of the product : " << this->nameOfPoduct			<< std::endl
			  << "Type of the product :"  << this->GetProductType()		<< std::endl
			  << "Price of the product :" << this->priceOfProduct  <<"$"<<std::endl;
}

Product::Product(const Product& other):
priceOfProduct(other.priceOfProduct),productType(other.productType)
{
	std::cout << "Product copy C'tor called \n";
	SetNameOfProduct(other.GetNameOfProduct());
}






