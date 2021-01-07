#include "Header/TradeSystem.h"

TradeSystem::TradeSystem(char* systemName)
	: numberOfBuyers(0),numberOfSellers(0),numberOfOrders(0),
	  sizeOfBuyersArray(0),sizeOfSellersArray(0),sizeOfOrdersArray(0)
{
	//std::cout << "TradeSystem Ctor called \n";
	this->systemName = new char[strlen(systemName) + 1];
	strcpy(this->systemName, systemName);
}

TradeSystem::~TradeSystem()
{
	//std::cout << "TradeSystem Dtor called \n";
	if (this->numberOfBuyers)
	{
		for (int i = 0; i < this->numberOfBuyers; ++i)
		{
			delete this->buyers[i];
		}
		delete[] this->buyers;
	}
	if (this->numberOfOrders)
	{
		for (int i = 0; i < this->numberOfOrders; ++i)
		{
			delete this->orders[i];
		}
		delete[] this->orders;
	}
	if (this->numberOfSellers)
	{
		for (int i = 0; i < this->numberOfSellers; ++i)
		{
			delete this->sellers[i];
		}
		delete[] this->sellers;
	}
}

Seller& TradeSystem::GetSeller(const char* sellerName) const
{
	for (int i = 0; i < this->numberOfSellers; ++i)
	{
		if (!strcmp(this->sellers[i]->GetUserName(),sellerName))
		{
			return *sellers[i];
		}
	}
	std::cout << "Please insert valid seller name \n";
}

Buyer& TradeSystem::GetBuyer(const char* buyerName) const
{
	for (int i = 0; i < this->numberOfBuyers; ++i)
	{
		if (!strcmp(this->buyers[i]->GetUserName(), buyerName))
		{
			return *buyers[i];
		}
	}
	std::cout << "Please insert valid buyer name \n";
}

const Order& TradeSystem::GetOrder(const char* orderBuyerName) const
{
	for (int i = 0; i < this->numberOfOrders; ++i)
	{
		if (!strcmp(this->orders[i]->GetOrder().GetUserName(), orderBuyerName))
		{
			return *orders[i];
		}
	}
	std::cout << "Please insert valid buyer name who has order \n";
}

void TradeSystem::SetSystemName(char* const systemName)
{
	delete[] systemName;
	this->systemName = new char [strlen(systemName) + 1];
	strcpy(this->systemName, systemName);
}

void TradeSystem::AddBuyer(const Buyer& buyer)
{
	if (this->sizeOfBuyersArray == this->numberOfBuyers)
	{
		this->buyers = RealocateBuyersArray();
		this->buyers[this->numberOfBuyers] = new Buyer(buyer);
		++this->numberOfBuyers;
	}
	else
	{
		this->buyers[this->numberOfBuyers] = new Buyer(buyer);
		++this->numberOfBuyers;
	}
	
}

void TradeSystem::AddSeller(const Seller& seller)
{

	if (this->sizeOfSellersArray == this->numberOfSellers)
	{
		this->sellers = RealocateSellersArray();
		this->sellers[this->numberOfSellers] = new Seller(seller);
		++this->numberOfSellers;
	}
	else
	{
		this->sellers[this->numberOfSellers] = new Seller(seller);
		++this->numberOfSellers;
	}
}

void TradeSystem::AddToOrderList(const Order& order)
{
	if (this->sizeOfOrdersArray == this->numberOfOrders)
	{
		this->orders = RealocateOrdersArray();
		this->orders[this->numberOfOrders] =  &order;
		++this->numberOfOrders;
	}
	else
	{
		this->orders[this->numberOfOrders] = &order;
		++this->numberOfOrders;
	}
}

void TradeSystem::PrintBuyers(bool printAddress,bool printCart) const
{
	for (int i = 0; i < this->numberOfBuyers; ++i)
	{
		std::cout << "Buyer number : " << i << std::endl
				  <<*this->buyers[i];
	}
}

void TradeSystem::PrintSellers(bool printAddress, bool printProducts) const
{
	for (int i = 0; i < this->numberOfSellers; ++i)
	{
		std::cout << "Seller number : " << i << std::endl
			<< *this->sellers[i];
	}
}

void TradeSystem::PrintOrders(bool printAddress) const
{
	for (int i = 0; i < this->numberOfOrders; ++i)
	{
		std::cout << "Order number : " << i << std::endl
				  << *this->orders[i];
	}
}

int TradeSystem::CheckUniqueId(const char* productName)
{
	for (int i = 0; i < numberOfSellers; ++i)
	{
		int tmp = this->sellers[i]->CheckOfProductExistence(productName);
		if (tmp == 0)
		{
			return this->GenerateUniqeID();
		}
		else
			return tmp;
	}
	return this->GenerateUniqeID();
}

Product& TradeSystem::GetProductBySeller(const char* name)
{
	for (int i = 0; i < this->numberOfSellers; ++i)
	{
		for (int j = 0; j < this->sellers[i]->numberOfProducts; ++j)
		{
			if (!strcmp(this->sellers[i]->products[j]->GetNameOfProduct(), name))
			{
				return *this->sellers[i]->products[j];
			}
		}
	
	}
}


int TradeSystem::GenerateUniqeID()
{
	return this->sellers[0]->seedID++;
}

Seller** TradeSystem::RealocateSellersArray()
{
	if (this->sizeOfSellersArray == 0)
		++this->sizeOfSellersArray;
	this->sizeOfSellersArray *= 2;
	Seller** buffer = new Seller* [this->sizeOfSellersArray ];
	
	if (this->numberOfSellers == 0)
	{
		return buffer;
	}
	else
	{
		for (int i = 0; i < this->numberOfSellers; ++i)
		{
			buffer[i] = this->sellers[i];
		}
		delete sellers;
		return buffer;
	}
	
}

Buyer** TradeSystem::RealocateBuyersArray()
{
	if (this->sizeOfBuyersArray == 0)
		++this->sizeOfBuyersArray;
	this->sizeOfBuyersArray *= 2;
	Buyer** buffer = new Buyer * [this->sizeOfBuyersArray];
	
	if (this->numberOfBuyers == 0)
	{
		return buffer;
	}
	else
	{
		for (int i = 0; i < this->numberOfBuyers; ++i)
		{
			buffer[i] = this->buyers[i];
		}
		delete buyers;
		return buffer;
	}
}

const Order** TradeSystem::RealocateOrdersArray()
{
	if (this->sizeOfOrdersArray == 0)
		++this->sizeOfOrdersArray;
	this->sizeOfOrdersArray *= 2;
	const Order** buffer = new const Order * [this->sizeOfOrdersArray];
	
	if (this->numberOfOrders == 0)
	{
		return buffer;
	}
	else
	{
		for (int i = 0; i < this->numberOfOrders; ++i)
		{
			buffer[i] = this->orders[i];
		}
		delete orders;
		return buffer;
	}
}

void operator+=(TradeSystem& tradeSystem, const Buyer& buyer)
{
	tradeSystem.AddBuyer(buyer);
}

void operator+=(TradeSystem& tradeSystem, const Seller& seller)
{
	tradeSystem.AddSeller(seller);
}
