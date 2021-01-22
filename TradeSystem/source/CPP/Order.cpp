#include "Header/Order.h"




Order& Order::operator=(const Order& other)
{
	if (this == &other)
		return *this;
	buyer = other.buyer;
	orderInvoiceSum = other.orderInvoiceSum;
	return *this;
}
void Order::PrintOrder(bool printAddress) const
{
	this->buyer.PrintBuyer(true);
	std::cout << "TOTAL: " << this->orderInvoiceSum <<"$"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const Order& order)
{
	order.PrintOrder(true);
	return os;
}
