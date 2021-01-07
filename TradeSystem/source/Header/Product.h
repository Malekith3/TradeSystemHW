#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>

class Seller;

class Product
{

public:
	//***************************Declarations*************************************
	enum ProductType {Kids,Electronics,Office,Clothes};
	//***************************Constructors*************************************
	Product(const char* nameOfProduct, const int& priceOfProduct, ProductType productType, int uniqueID);
	//***************************Copy Ctor****************************************
	Product(const Product& other);
	//***************************Destructor***************************************
	~Product(){delete[] this->nameOfProduct;}
	Product& operator=(const Product& other);
	//***************************Getters & Setters********************************
	char* GetNameOfProduct() const {return this->nameOfProduct;}
	const int& GetPriceOfProduct() const {return this->priceOfProduct;}
	const char* GetProductType() const { return productTypeStr[productType]; }
	bool SetPriceOfProduct(int priceOfProduct);
	bool SetProductType(ProductType productType);
	bool SetNameOfProduct(char* nameOfProduct);
	//***************************Methods******************************************
	void PrintProduct(bool Seller = false) const;
private:
	Product& SetSeller(const Seller& seller);
	//****************************************************************************
	

	friend class Seller;
	friend class ShopingCart;
	static const char* productTypeStr[4];
	char* nameOfProduct;
	int priceOfProduct;
	int id;
	const Seller* seller;
	ProductType productType;
};
#endif 



