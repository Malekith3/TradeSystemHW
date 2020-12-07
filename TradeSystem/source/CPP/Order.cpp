#include "Header/Order.h"


void Order::PrintOrder(bool printAddress) const
{
	this->buyer.PrintBuyer(printAddress, true);
	std::cout << "TOTAL: " << this->orderInvoiceSum <<"$"<<std::endl;
}

