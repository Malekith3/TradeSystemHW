#include "Header/TradeSystem.h"
#define MAX_STRING_SIZE 20
using namespace std;
void OrderHandler(Order* order, TradeSystem& tradeSystem);
enum Operations{Add_Buyer=1 , Add_seller, Add_product_to_seller, Add_to_cart, Checkout, Show_all_buyers, Show_all_sellers, Exit, Show_all_Orders, Logout, ShowShoppingCart , CompareTwoBuyers};
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
		cout << "{1} Add buyer"							<< endl
			 << "{2} Add seller"						<< endl
			 << "{3} Add product to seller"				<< endl
			 << "{6} Show all buyers"					<< endl
			 << "{7} Show all sellers"					<< endl
		     << "{9} Show all orders"					<< endl
			 << "{12} Compare two buyers shopping cart" << endl;
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
	
	cout << "Please enter your street name (20 characters max and _ for spaces): "  << endl;
	cin	 >> streetName;
	streetName= ResizeString(streetName);

	cout << "Please enter your building number: "				   << endl;
	cin  >> buildingNumber;


	cout << "Please enter your city (20 characters max and _ for spaces): "		   << endl;
	cin  >> city;
	city = ResizeString(city);

	cout << "Please enter your country (20 characters max and _ for spaces): "	   << endl;
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
			
			cout << "Please enter your username (20 characters max and _ for spaces): " << endl;
			cin  >> userName;
			userName = ResizeString(userName);

			cout << "Please enter your password (20 characters max and _ for spaces) " << endl;
			cin  >> password;
			password = ResizeString(password);

			tradesystem += Buyer(userName, password, InputAddress());
			break;

		case Add_seller:
			cout << "Please enter your username (20 characters max and _ for spaces) :" << endl;
			cin >> userName;
			userName = ResizeString(userName);

			cout << "Please enter your password (20 characters max and _ for spaces) " << endl;
			cin >> password;
			password = ResizeString(password);

			tradesystem += Seller(userName, password, InputAddress());
			break;

		case Add_product_to_seller:
			cout << "Please enter a valid seller name: " << endl;
			cin  >> seller;
			seller = ResizeString(seller);
		
			cout << "Please enter a product name (20 characters max and _ for spaces): "      << endl;
			cin  >> product;
			product = ResizeString(product);

			cout << "Please enter the product price: "   << endl;
			cin  >> price;
		
			PrintProductType();
			cin  >> type;
			tradesystem.GetSeller(seller).AddProduct(Product(product, price, (Product::ProductType)type , tradesystem.CheckUniqueId(product)));
			break;

		case Add_to_cart:
			cout << "Please enter a valid buyer name: " << endl;
			cin  >> buyer;
			buyer = ResizeString(buyer);

			cout << "Please enter a  valid product name : " << endl;
			cin  >> product;
			product = ResizeString(product);

			tradesystem.GetBuyer(buyer).AddToShoppingCart(Product(tradesystem.GetProductBySeller(product)));
			break;

		case Checkout:
			cout << "Please enter a valid buyer name: " << endl;
			cin >> buyer;
			buyer = ResizeString(buyer);
			OrderHandler(tradesystem.GetBuyer(buyer).OrderAndCheckout(),tradesystem);	
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
			tradesystem.GetBuyer(buyer).PrintBuyer(true);
			break;
		case CompareTwoBuyers:
			cout << "Please enter a valid first buyer name to compare: " << endl;
			cin >> buyer;
			cout << "Please enter a valid second buyer name to compare: " << endl;
			cin >> seller;
			if (tradesystem.GetBuyer(buyer) > tradesystem.GetBuyer(seller))
				cout << buyer <<  " has bigger shopping cart" << endl;
			else
				cout << seller << " has bigger shopping cart" << endl;
			break;
		default:
			cout << "Please insert valid option " << endl;
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
void OrderHandler( Order* order,TradeSystem& tradeSystem) 
{
	if (order == nullptr)
	{
		cout << "Can't checkout your shopping cart is empty!!!  " << endl;
		return;
	}
	order->PrintOrder();
	tradeSystem.AddToOrderList(*order);
}
