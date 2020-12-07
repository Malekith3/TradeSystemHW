#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H

#include "Product.h"

class ShoppingCart
{
	int sizeOfCartArray;
	int numberOfProducts;
	Product** products;
public:
	//***************************Constructors*************************************
	ShoppingCart() :
	sizeOfCartArray(0),
	numberOfProducts(0) {}
	ShoppingCart(const Product& product);
	//***************************Destructor***************************************
	~ShoppingCart() { ReleaseProductArray(); }
	//***************************Copy C'tor***************************************
	ShoppingCart(const ShoppingCart& other);
	//***************************Getters & Setters********************************
	int GetNumberOfProducts() const{return numberOfProducts;}
	Product** GetProducts() const{return products;}
	//***************************Methods******************************************
	void AddProductToShopingCart(const Product& product);
	void PrintShopingCart() const;
	void EmptyTheShoppingCart();
	const int CalculateCartSum()const;
private :
	Product** RealocateProductArray();
	void ReleaseProductArray();
	//****************************************************************************
};

#endif
