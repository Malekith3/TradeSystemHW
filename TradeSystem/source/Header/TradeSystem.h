#ifndef _TRADESYSTEM__H
#define _TRADESYSTEM__H
#include "Seller.h"
#include "Buyer.h"
#include "Order.h"
class TradeSystem
{
	char* systemName;
	int numberOfBuyers , numberOfSellers , numberOfOrders;
	int sizeOfBuyersArray, sizeOfSellersArray,sizeOfOrdersArray;
	Seller** sellers;
	Buyer** buyers;
	const Order** orders;
public:
	
	//***************************Constructors*************************************
	TradeSystem(char* systemName);
	//***************************Destructor***************************************
	~TradeSystem();
	//***************************Copy C'tor***************************************
	TradeSystem(const TradeSystem& other) = delete;
	//***************************Getters & Setters********************************
	int GetNumberOfBuyers() const { return numberOfBuyers; }
	int GetNumberOfSellers() const { return numberOfSellers; }
	int GetNumberOfOrders() const { return numberOfOrders; }
	Seller& GetSeller(const char* sellerName) const;
	Buyer& GetBuyer(const char* buyerName) const;
	const Order& GetOrder(const char* orderBuyerName) const;

	void SetSystemName(char* const systemName);
	//***************************Operators****************************************

	friend void operator+=( TradeSystem& tradeSystem, const Buyer& buyer);
	friend void operator+=( TradeSystem& tradeSystem, const Seller& seller);


	//***************************Methods******************************************
	void AddBuyer(const Buyer& buyer);
	void AddSeller(const Seller& seller);
	void AddToOrderList(const Order& order);
	void PrintBuyers(bool printAddress = false, bool printCart=false)const;
	void PrintSellers(bool printAddress = false, bool printProducts = false)const;
	void PrintOrders(bool printAddress = false)const;
	int CheckUniqueId(const char* productName);
	Product& GetProductBySeller(const char* productName);
private:
	int GenerateUniqeID();
	Seller** RealocateSellersArray();
	Buyer** RealocateBuyersArray();
	const Order** RealocateOrdersArray();
	//****************************************************************************
};
#endif
