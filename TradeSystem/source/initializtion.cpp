#include "Header/TradeSystem.h"

void Initialization(TradeSystem& tradeSystem)
{
	tradeSystem.AddBuyer(Buyer("Timon", "23456", Address("Nothing", 5, "Hell", "Earth")));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(Product("Notebook", 56, Product::Office));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(Product("PS5", 400, Product::Electronics));
	tradeSystem.AddToOrderList(tradeSystem.GetBuyer("Timon").OrderAndCheckout());
	tradeSystem.AddBuyer(Buyer("Brunhilda", "23456", Address("Valhalla Street", 5, "Midgard", "Asgard")));
	tradeSystem.GetBuyer("Brunhilda").AddToShoppingCart(Product("Axe", 1000, Product::Office));
	tradeSystem.AddSeller(Seller("Pipin", "23456", Address("Nowhere", 5, "Tel Aviv", "Earth")));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("Notebook", 56, Product::Office));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("PS5", 400, Product::Electronics));
	tradeSystem.GetBuyer("Pipin").AddToShoppingCart(Product("Axe", 1000, Product::Office));
}
