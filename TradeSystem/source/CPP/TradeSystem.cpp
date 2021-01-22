#include "Header/TradeSystem.h"

TradeSystem::TradeSystem(char* systemName): numberOfUsers(0) , numberOfOrders(0),sizeOfUsersArray(0),sizeOfOrdersArray(0)
{
	this->systemName = strdup( systemName);
}

TradeSystem::~TradeSystem()
{
	delete[] this->systemName;
	
	if (this->numberOfOrders)
	{
		for (int i = 0; i < this->numberOfOrders; ++i)
		{
			delete this->orders[i];
		}
		delete[] this->orders;
	}
	if (this->numberOfUsers)
	{
		for (int i = 0; i < this->numberOfUsers; ++i)
		{
			delete this->users[i];
		}
		delete[] this->users;
	}
}

Seller& TradeSystem::GetSeller(const char* sellerName) const
{
	for (int i = 0; i < this->numberOfUsers; ++i)
	{
		if (!strcmp(this->users[i]->GetUserName(), sellerName))
		{
			Seller* tmp = dynamic_cast<Seller*>(users[i]);
			
			if (tmp)
			{
				return *tmp;
			}
			
		}
	}
	std::cout << "Please insert valid seller name \n";
}

Buyer& TradeSystem::GetBuyer(const char* buyerName) const
{
	for (int i = 0; i < this->numberOfUsers; ++i)
	{
		if (!strcmp(this->users[i]->GetUserName(), buyerName))
		{
			Buyer* tmp = dynamic_cast<Buyer*>(users[i]);

			if (tmp)
			{
				return *tmp;
			}

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
	delete[] this->systemName;
	this->systemName = strdup(systemName);
}

void TradeSystem::PrintBuyers(bool printAddress, bool printCart) const
{
	int numBuyers = 1;
	for (int i = 0; i < this->numberOfUsers; ++i)
	{
		Buyer* tmp = dynamic_cast<Buyer*>(this->users[i]);
		if (tmp) 
		{
			std::cout << "Buyer number : " << numBuyers << std::endl;
			std::cout << *tmp;
			++numBuyers;
		}
	}
	
}

void TradeSystem::PrintSellers(bool printAddress, bool printProducts) const
{
	int numSellers = 1;
	for (int i = 0; i < this->numberOfUsers; ++i)
	{
		Seller* tmp = dynamic_cast<Seller*>(this->users[i]);
		if (tmp) 
		{
			std::cout << "Seller number : " << numSellers << std::endl;
			std::cout << *tmp;
			++numSellers;
		}
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


void TradeSystem::AddUser(const User& user)
{
	const Seller* tmpSeller =  dynamic_cast<const Seller*>(&user);
	const Buyer*  tmpBuyer = dynamic_cast<const Buyer*>(&user);
	
	if (tmpSeller)
	{
		if (this->sizeOfUsersArray == this->numberOfUsers)
		{
			this->users = RealocateUsersArray();
			this->users[this->numberOfUsers] = new Seller(*tmpSeller);
			++this->numberOfUsers;
		}
		else
		{
			this->users[this->numberOfUsers] = new Seller(*tmpSeller);
			++this->numberOfUsers;
		}
	}
	else if (tmpBuyer)
	{
		if (this->sizeOfUsersArray == this->numberOfUsers)
		{
			this->users = RealocateUsersArray();
			this->users[this->numberOfUsers] = new Buyer(*tmpBuyer);
			++this->numberOfUsers;
		}
		else
		{
			this->users[this->numberOfUsers] = new Buyer(*tmpBuyer);
			++this->numberOfUsers;
		}
	}
	else
		std::cout << "Cant add Buyer/Seller \n ";
	
}

void TradeSystem::AddToOrderList(const Order& order)
{
	if (this->sizeOfOrdersArray == this->numberOfOrders)
	{
		this->orders = RealocateOrdersArray();
		this->orders[this->numberOfOrders] = &order;
		++this->numberOfOrders;
	}
	else
	{
		this->orders[this->numberOfOrders] = &order;
		++this->numberOfOrders;
	}
}

int TradeSystem::CheckUniqueId(const char* productName)
{
	for (int i = 0; i < numberOfUsers; ++i)
	{
		Seller* tmp = dynamic_cast<Seller*>(this->users[i]);
		if (tmp)
		{
			int tmp1 = tmp->CheckOfProductExistence(productName);
			if (tmp1 == 0)
			{
				return this->GenerateUniqeID();
			}
			else
				return tmp1;
		}
		
	}
	return this->GenerateUniqeID();
}

Product& TradeSystem::GetProductBySeller(const char* productName)
{
	for (int i = 0; i < this->numberOfUsers; ++i)
	{
		Seller* tmp = dynamic_cast<Seller*>(this->users[i]);
		if (tmp)
		{
			for (int j = 0; j < tmp->numberOfProducts; ++j)
			{
				if (!strcmp(tmp->products[j]->GetNameOfProduct(), productName))
				{
					return *tmp->products[j];
				}
			}
		}
	}
}

int TradeSystem::GenerateUniqeID()
{
	return ++Seller::seedID;
}

User** TradeSystem::RealocateUsersArray()
{
	if (this->sizeOfUsersArray == 0)
		++this->sizeOfUsersArray;
	this->sizeOfUsersArray *= 2;
	User** buffer = new User*  [this->sizeOfUsersArray];

	if (this->numberOfUsers == 0)
	{
		return buffer;
	}
	else
	{
		for (int i = 0; i < this->numberOfUsers; ++i)
		{
			buffer[i] = this->users[i];
		}
		delete users;
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

void operator+=(TradeSystem& tradeSystem, const User& user) {tradeSystem.AddUser(user);}
