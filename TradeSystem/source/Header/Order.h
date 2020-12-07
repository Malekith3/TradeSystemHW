#ifndef _ORDER__H
#define _ORDER__H

#include "Buyer.h"
class Order
{
	Buyer buyer;
	int orderInvoiceSum;
public:
	//***************************Constructors*************************************
	Order::Order(const Buyer& buyer ,int orderInvoiceSum) : buyer(buyer) ,orderInvoiceSum(orderInvoiceSum){ std::cout << "Order Ctor called \n"; }
	//***************************Copy Ctor****************************************
	Order(const Order& other) = default;
	//***************************Destructor***************************************
	~Order() { std::cout << "Order Dtor called \n"; }
	//***************************Getters & Setters********************************
	const Buyer& GetOrder()const { return  this->buyer; };
	//***************************Methods******************************************
	void PrintOrder(bool printAddress = false) const;
	//****************************************************************************
};
#endif
