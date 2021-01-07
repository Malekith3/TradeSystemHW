#include "Header/Order.h"


void Order::PrintOrder(bool printAddress) const
{
	this->buyer.PrintBuyer(printAddress, true);
	std::cout << "TOTAL: " << this->orderInvoiceSum <<"$"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Order& order)
{
	order.PrintOrder(true);
	return os;
}
