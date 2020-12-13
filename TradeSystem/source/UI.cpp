#include "Header/TradeSystem.h"
#define MAX_STRING_SIZE 20
using namespace std;

enum Operations{Add_Buyer=1 , Add_seller, Add_product_to_seller, Add_to_cart, Checkout, Show_all_buyers, Show_all_sellers, Exit, Show_all_Orders, Logout, ShowShoppingCart};
static Address address;
static char* ResizeString(char* string)
{
	if (strlen(string)!=MAX_STRING_SIZE)
	{
		char* resizedString = strdup(string);
		delete[] string;
		return resizedString;
		
	}

	return string;
	
}

static void PrintOperationsList(char typeOfUser)
{
	if (typeOfUser=='A'|| typeOfUser == 'a')	//admin
	{
		cout << "{1} Add buyer"				 << endl
			 << "{2} Add seller"			 << endl
			 << "{3} Add product to seller"  << endl
			 << "{6} Show all buyers"	     << endl
			 << "{7} Show all sellers"       << endl
		     << "{9} Show all orders"		 << endl;
	}

	else if(typeOfUser=='U'||typeOfUser=='u')
	{
		cout << "{4} Add to cart"             << endl
			 << "{5} Checkout"                << endl
			 << "{11} Show shopping cart"     << endl;
	}

	cout << "{8} Exit"            << endl;
	cout << "{10} Logout"         << endl;
	
		
	
}

static void PrintProductType()
{
	cout << "Please choose product type: " << endl
		 << "{0} Kids"					   << endl
		 << "{1} Electronics"              << endl
		 << "{2} Office"				   << endl
		 << "{3} Clothes"				   << endl;
}

static char LogIn()
{
	char typeOfUser;
	cout << "Welcome to My little pony!" << endl
		 << "Press A if you are an admin, U if you are a user: " << endl;

	cin  >> typeOfUser;

	return typeOfUser;
}

static Address& InputAddress()
{
	char* streetName = new char[MAX_STRING_SIZE + 1];
	char* city       = new char[MAX_STRING_SIZE + 1];
	char* country    = new char[MAX_STRING_SIZE + 1];
	int buildingNumber;
	
	cout << "Please enter your street name (20 characters max): "  << endl;
	cin	 >> streetName;
	streetName= ResizeString(streetName);

	cout << "Please enter your building number: "				   << endl;
	cin  >> buildingNumber;


	cout << "Please enter your city (20 characters max): "		   << endl;
	cin  >> city;
	city = ResizeString(city);

	cout << "Please enter your country (20 characters max): "	   << endl;
	cin  >> country;
	country = ResizeString(country);
	address.SetStreetName(streetName).SetBuildingNumber(buildingNumber).SetCity(city).SetCountry(country);
	
	return  address;

	
}

static void SetOperation(TradeSystem& tradesystem, int operation ,char& typeOfUser)
{
	char* userName = new char[MAX_STRING_SIZE];
	char* password = new char[MAX_STRING_SIZE];
	char* product = new char[MAX_STRING_SIZE];
	char* buyer = new char[MAX_STRING_SIZE];
	char* seller = new char[MAX_STRING_SIZE];
	int type;
	int price;
	switch (operation)
	{
		case Add_Buyer:
			
			cout << "Please enter your username: " << endl;
			cin  >> userName;
			userName = ResizeString(userName);

			cout << "Please enter your password " << endl;
			cin  >> password;
			password = ResizeString(password);

			tradesystem.AddBuyer(Buyer(userName, password, InputAddress()));
			break;

		case Add_seller:
			cout << "Please enter your username: " << endl;
			cin >> userName;
			userName = ResizeString(userName);

			cout << "Please enter your password " << endl;
			cin >> password;
			password = ResizeString(password);

			tradesystem.AddSeller(Seller(userName, password, InputAddress()));
			break;

		case Add_product_to_seller:
			cout << "Please enter a valid seller name: " << endl;
			cin  >> seller;
			seller = ResizeString(seller);
		
			cout << "Please enter a product name: "      << endl;
			cin  >> product;
			product = ResizeString(product);

			cout << "Please enter the product price: "   << endl;
			cin  >> price;
		
			PrintProductType();
			cin  >> type;

			tradesystem.GetSeller(seller).AddProduct(Product(product, price, (Product::ProductType)type));
			break;

		case Add_to_cart:
			cout << "Please enter a valid buyer name: " << endl;
			cin  >> buyer;
			buyer = ResizeString(buyer);

			cout << "Please enter a product name: " << endl;
			cin  >> product;
			product = ResizeString(product);

			cout << "Please enter the product price: " << endl;
			cin  >> price;

			PrintProductType();
			cin >> type;

			tradesystem.GetBuyer(buyer).AddToShoppingCart(Product(product, price, (Product::ProductType)type));
			break;

		case Checkout:
			cout << "Please enter a valid buyer name: " << endl;
			cin >> buyer;
			buyer = ResizeString(buyer);
			tradesystem.AddToOrderList(tradesystem.GetBuyer(buyer).OrderAndCheckout());
			tradesystem.GetOrder(buyer).PrintOrder();
			break;

		case Show_all_buyers:
			tradesystem.PrintBuyers(true,true);
			break;

		case Show_all_sellers:
			tradesystem.PrintSellers(true,true);
			break;

		case Show_all_Orders:
			tradesystem.PrintOrders();
			break;

		case Logout:
			typeOfUser = LogIn();
			PrintOperationsList(typeOfUser);
			break;
		
		case ShowShoppingCart:
			cout << "Please enter a valid buyer name: " << endl;
			cin >> buyer;
			buyer = ResizeString(buyer);
			tradesystem.GetBuyer(buyer).PrintBuyer(false, true);
			break;		
	}

	delete[] userName;
	delete[] password;
	delete[] product;
	delete[] buyer;
	delete[] seller;

	
}


void UI(TradeSystem& tradeSystem)
{
	int operation=0;
	char typeOfUser = LogIn();
	while(operation!=Exit)
	{
		if(operation!=Logout)
		  PrintOperationsList(typeOfUser);

		cout << "Please select an operation: " << endl;
		cin	 >> operation;

		SetOperation(tradeSystem,operation , typeOfUser);
	}

	
}

