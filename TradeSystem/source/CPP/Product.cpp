#include "Header/Product.h"
const char* Product::productTypeStr[4] = {"Kids","Electronics","Office","Clothes"};

Product::Product(const char* nameOfProduct, const int& priceOfProduct, ProductType productType)
	: priceOfProduct(priceOfProduct),
	productType(productType)
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

void Product::PrintProduct() const
{
	std::cout << "Name of the product : " << this->nameOfProduct			<< std::endl
			  << "Type of the product :"  << this->GetProductType()		<< std::endl
			  << "Price of the product :" << this->priceOfProduct  <<"$"<<std::endl;
}

Product::Product(const Product& other):
priceOfProduct(other.priceOfProduct),productType(other.productType)
{
	//std::cout << "Product copy C'tor called \n";
	this->nameOfProduct = new char[strlen(other.nameOfProduct) + 1];
	strcpy(this->nameOfProduct, other.nameOfProduct);
}






