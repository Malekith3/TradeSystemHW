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
	//***************************Destructor***************************************

	ShoppingCart(const ShoppingCart& other);
	//***************************Methods******************************************
	void AddProductToShopingCart(const Product& product);
	void PrintShopingCart() const;
	void EmptyTheShoppingCart();
private :
	Product** RealocateProductArray();
	void ReleaseProductArray();
	//****************************************************************************
};

#endif
