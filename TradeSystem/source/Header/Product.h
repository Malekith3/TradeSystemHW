#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>

class Product
{

public:
	//***************************Declarations*************************************
	enum ProductType {Kids,Electronics,Office,Clothes};
	//***************************Constructors*************************************
	Product(const char* name_of_poduct, const int& price_of_product, ProductType product_type);
	//***************************Copy Ctor****************************************
	Product(const Product& other);
	//***************************Destructor***************************************
	~Product(){std::cout << "Product D'tor called \n";delete[] this->nameOfPoduct;}
	//***************************Getters & Setters********************************
	char* GetNameOfProduct() const {return this->nameOfPoduct;}
	const int& GetPriceOfProduct() const {return this->priceOfProduct;}
	const char* GetProductType() const { return productTypeStr[productType]; }
	void SetPriceOfProduct(int price_of_product) { this->priceOfProduct = price_of_product; }
	void SetProductType(ProductType product_type) {this->productType = product_type;}
	void SetNameOfProduct(char* name_of_poduct);
	//***************************Methods******************************************
	void PrintProduct() const;
	//****************************************************************************
	
private:
	static const char* productTypeStr[4];
	char* nameOfPoduct{};
	int priceOfProduct;
	ProductType productType;
};
#endif 



