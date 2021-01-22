#ifndef _ORDER__H
#define _ORDER__H

#include "Buyer.h"
class Order
{
	Buyer buyer;
	int orderInvoiceSum;
public:
	//***************************Constructors*************************************
	Order(const Buyer& buyer ,int orderInvoiceSum) : buyer(buyer) ,orderInvoiceSum(orderInvoiceSum){}
	//***************************Copy Ctor****************************************
	Order(const Order& other) = default;
	Order& operator=(const Order& other);
	//***************************Destructor***************************************
	~Order() {  }
	//***************************Operators***************************************
	friend std::ostream& operator<<(std::ostream& os, const Order& order);
	//***************************Getters & Setters********************************
	const Buyer& GetOrder()const { return  this->buyer; };
	//***************************Methods******************************************
	void PrintOrder(bool printAddress = false) const;
	//****************************************************************************
};
#endif
