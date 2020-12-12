#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>

class Product
{

public:
	//***************************Declarations*************************************
	enum ProductType {Kids,Electronics,Office,Clothes};
	//***************************Constructors*************************************
	Product(const char* nameOfProduct, const int& priceOfProduct, ProductType productType);
	//***************************Copy Ctor****************************************
	Product(const Product& other);
	//***************************Destructor***************************************
	~Product(){delete[] this->nameOfProduct;}
	//***************************Getters & Setters********************************
	char* GetNameOfProduct() const {return this->nameOfProduct;}
	const int& GetPriceOfProduct() const {return this->priceOfProduct;}
	const char* GetProductType() const { return productTypeStr[productType]; }
	bool SetPriceOfProduct(int priceOfProduct);
	bool SetProductType(ProductType productType);
	bool SetNameOfProduct(char* nameOfProduct);
	//***************************Methods******************************************
	void PrintProduct() const;
	//****************************************************************************
	
private:
	static const char* productTypeStr[4];
	char* nameOfProduct;
	int priceOfProduct;
	ProductType productType;
};
#endif 



