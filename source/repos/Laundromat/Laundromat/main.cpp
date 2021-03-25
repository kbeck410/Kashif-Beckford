#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <time.h>
#include "POSService.h"
#include "Msg.h"

using namespace std;

void beginTransaction(vector<string>, string, string);
void setPin(int);
bool setReceipt(bool);
void cancelTransaction();
string id;
int pinNo;
bool isAuthorized = false;
int cost;
bool receipt = false;
string pin;
string paymentform = "debit";

int main()
{
	srand(time(NULL));

	POSService serv;
	Msg msg;

	cout << "Welcome to the BJs Landromat";

	msg.add("Select payment form (default: debit)");
	cin >> paymentform;
	if (paymentform == "debit")
	{
		vector<string> debitCard;
		string iMethod;
		msg.add("Insert debit card and click [inserted]");
		cin >> iMethod;

		debitCard.push_back(to_string(rand() & 10000));
		debitCard.push_back(to_string(rand() & 10000));
		debitCard.push_back(to_string(rand() & 10000));
		debitCard.push_back(to_string(rand() & 10000));

		beginTransaction(debitCard, pin, id);

		int pinNo;
		msg.add("Enter pin");
		cin >> pinNo;
		setPin(pinNo);

		if (pinNo == true)
		{
			isAuthorized = serv.getDebitAuth(debitCard, pinNo);
			msg.add("payment authorized", pinNo);
		}
		else
		{
			msg.add("Payment declined", pinNo);
			cancelTransaction;
		}
	}
	

	return 0;
}
void beginTransaction(vector<string> debitCard, string pin, string id)
{
	id = to_string(1 + (rand() % 10000));
	for (int i = 0; i < pin.size(); i++)
	{
		if (i == 4)
		{
			pin = debitCard[i];
		}
	}
}
void setPin(int pin)
{
	pinNo = pin;
}

bool setReceipt(bool answer)
{
	return answer;
}

void cancelTransaction()
{
	exit(EXIT_FAILURE);
}
