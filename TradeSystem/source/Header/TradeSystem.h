#ifndef _TRADESYSTEM__H
#define _TRADESYSTEM__H
#include "User.h"
#include  "Order.h"
#include "Seller.h"
#include "Buyer.h"

class TradeSystem
{
	char* systemName;
	int numberOfUsers, numberOfOrders;
	int sizeOfUsersArray,  sizeOfOrdersArray;
	User** users;
	const Order** orders;
public:
	//***************************Constructors*************************************
	TradeSystem(char* systemName);
	//***************************Destructor***************************************
	~TradeSystem();
	//***************************Copy C'tor***************************************
	TradeSystem(const TradeSystem& other) = delete;
	//***************************Getters & Setters********************************
	Seller& GetSeller(const char* sellerName) const;
	Buyer& GetBuyer(const char* buyerName) const;
	const Order& GetOrder(const char* orderBuyerName) const;

	void SetSystemName(char* const systemName);
	//***************************Operators****************************************
	friend void operator+=(TradeSystem& tradeSystem, const User& user);
	//***************************Methods******************************************
	void PrintBuyers(bool printAddress = false, bool printCart = false) const;
	void PrintSellers(bool printAddress = false, bool printProducts = false) const;
	void PrintOrders(bool printAddress = false) const;

	void AddUser(const User& user);
	void AddToOrderList(const Order& order);
	int CheckUniqueId(const char* productName);
	Product& GetProductBySeller(const char* productName);

private:
	int GenerateUniqeID();
	User** RealocateUsersArray();
	const Order** RealocateOrdersArray();
	//****************************************************************************
};
#endif