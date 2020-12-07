#include"Header/TradeSystem.h"

int main(int argc, char* argv[])
{
	Address someAddress("Nothing", 5, "Hell", "Earth");
	TradeSystem tradeSystem("My Little Pony");
	tradeSystem.AddBuyer(Buyer("Timon", "23456", someAddress));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(Product("Notebook", 56, Product::Office));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(Product("PS5", 400, Product::Electronics));
	tradeSystem.AddToOrderList(tradeSystem.GetBuyer("Timon").OrderAndCheckout());
	tradeSystem.AddSeller(Seller("Pipin", "23456", someAddress.SetCity("Tel Aviv")));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("Notebook", 56, Product::Office));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("PS5", 400, Product::Electronics));
	tradeSystem.PrintOrders(true);
	tradeSystem.PrintBuyers(true, true);
	tradeSystem.PrintSellers(true, true);
	
}
