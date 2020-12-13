#include"Header/TradeSystem.h"

void UI(TradeSystem& tradesystem);
void Initialization(TradeSystem& tradeSystem);
int main(int argc, char* argv[])
{
	TradeSystem tradesystem("My little pony");
	Initialization(tradesystem);
	UI(tradesystem);
	
}
