#include "ShoppingCart.h"
int main(int argc, char* argv[])
{
	ShoppingCart p;
	p.AddProductToShopingCart(Product("Star Wars Toy", 32, Product::Kids));
	p.AddProductToShopingCart(Product("TShirt", 32, Product::Clothes));
	p.AddProductToShopingCart(Product("Notebook", 32, Product::Office));
	p.PrintShopingCart();
	
}
