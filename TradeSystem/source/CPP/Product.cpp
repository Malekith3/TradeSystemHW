#include "Header/Product.h"

#include "Header/Seller.h"
const char* Product::productTypeStr[4] = {"Kids","Electronics","Office","Clothes"};

Product::Product(const char* nameOfProduct, const int& priceOfProduct, ProductType productType,int uniqueID)
	: priceOfProduct(priceOfProduct),
	productType(productType),
id(uniqueID)
{
	//std::cout << "Product C'tor called \n";
	this->nameOfProduct = new char[strlen(nameOfProduct) + 1];
	strcpy(this->nameOfProduct, nameOfProduct);
}

bool Product::SetPriceOfProduct(int priceOfProduct)
{
	this->priceOfProduct = priceOfProduct;
	return true;
}

bool Product::SetProductType(ProductType productType)
{
	this->productType = productType;
	return true;
}

bool Product::SetNameOfProduct(char* nameOfProduct)
{

	delete[] this->nameOfProduct;
	this->nameOfProduct = new char[strlen(nameOfProduct) + 1];
	strcpy(this->nameOfProduct, nameOfProduct);
	return true;
}

void Product::PrintProduct(bool Seller) const
{
	std::cout << "Name of the product : " << this->nameOfProduct			<< std::endl
			  << "Type of the product :"  << this->GetProductType()			<< std::endl
			  << "Price of the product :" << this->priceOfProduct  <<"$"	<< std::endl;
	if (Seller)
	{
		std::cout << "Seller of this product is : " << seller->GetUserName() << std::endl;
	}
		
	
	
}

Product& Product::SetSeller(const Seller& seller)
{
	this->seller = &seller;
	return *this;
}

Product::Product(const Product& other):
priceOfProduct(other.priceOfProduct),productType(other.productType),id(other.id),seller(other.seller)
{
	//std::cout << "Product copy C'tor called \n";
	this->nameOfProduct = new char[strlen(other.nameOfProduct) + 1];
	strcpy(this->nameOfProduct, other.nameOfProduct);
}

Product& Product::operator=(const Product& other)
{
	if (this == &other)
		return *this;
	this->nameOfProduct = strdup(other.nameOfProduct);
	this->SetPriceOfProduct(other.priceOfProduct);
	this->SetProductType(other.productType);
	this->seller = other.seller;
	return *this;
}






