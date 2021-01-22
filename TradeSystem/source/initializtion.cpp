#include "Header/TradeSystem.h"

void Initialization(TradeSystem& tradeSystem)
{
	tradeSystem += Seller("Pipin", "23456", Address("Nowhere", 5, "Tel Aviv", "Earth"));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("Notebook", 56, Product::Office, tradeSystem.CheckUniqueId("Notebook")));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("PS5", 400, Product::Electronics, tradeSystem.CheckUniqueId("PS5")));
	tradeSystem.GetSeller("Pipin").AddProduct(Product("Axe", 1000, Product::Office, tradeSystem.CheckUniqueId("Axe")));
	tradeSystem.AddUser(Seller("John", "23456", Address("Nowhere", 5, "Tel Aviv", "Earth")));
	tradeSystem.GetSeller("John").AddProduct(Product("Axe", 1000, Product::Office, tradeSystem.CheckUniqueId("Axe")));
	tradeSystem += Buyer("Timon", "23456", Address("Nothing", 5, "Hell", "Earth"));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(tradeSystem.GetProductBySeller("Notebook"));
	tradeSystem.GetBuyer("Timon").AddToShoppingCart(tradeSystem.GetProductBySeller("PS5"));
	tradeSystem.AddToOrderList(*tradeSystem.GetBuyer("Timon").OrderAndCheckout());
	tradeSystem += Buyer("Brunhilda", "23456", Address("Valhalla Street", 5, "Midgard", "Asgard"));
	tradeSystem.GetBuyer("Brunhilda").AddToShoppingCart(tradeSystem.GetProductBySeller("Axe"));
	
}
