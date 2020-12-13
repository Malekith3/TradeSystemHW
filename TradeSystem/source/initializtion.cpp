#include "Header/TradeSystem.h"

void Initialization(TradeSystem& tradeSystem)
{
	tradeSystem.AddBuyer(Buyer("Timon", "23456", Address("Nothing", 5, "Hell", "Earth")));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(Product("Notebook", 56, Product::Office));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(Product("PS5", 400, Product::Electronics));
	//tradeSystem.AddToOrderList(tradeSystem.GetBuyer("Timon").OrderAndCheckout());
	tradeSystem.AddSeller(Seller("Pipin", "23456", Address("Nowhere", 5, "Tel Aviv", "Earth")));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("Notebook", 56, Product::Office));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("PS5", 400, Product::Electronics));
}
