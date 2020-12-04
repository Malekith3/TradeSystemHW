#include <iostream>
using namespace std;
#include "Address.h"

int main(int argc, char* argv[])
{
	Address a1("Pizda", 666, "Shithole", "Hell");
	Address a2(a1);
	int b;
	a1.PrintAddress();
	a2.PrintAddress();
	b = a2.GetBuildingNumber();
	cout << endl << b << endl;
	a2.SetBuildingNumber(69);
	a2.PrintAddress();
	
}
