#include "POSService.h"
#include <iostream>
#include <fstream>
using namespace std;

bool POSService::getDebitAuth(std::vector<std::string>& debitCard, int pinNo)
{
    cout << "Processing Debit Card: ";
    for (int i = 0; i < debitCard.size() - 1; i++) {
        cout << "XXXX ";
    }
    cout << debitCard[debitCard.size() - 1] << endl;
    cout << "pin: " << pinNo << endl;

    if ((debitCard[debitCard.size() - 1] + to_string(pinNo)).length() == 4) {
        return true;
    }
    return false;
}

void POSService::logTransaction(string id, string debitCard, int cost)
{
    ofstream fileOUT;
    string word, filename;
    filename = "Text.txt";
    fileOUT.open(filename.c_str(), ios::app);

    fileOUT << id << " ";
    fileOUT << debitCard << " ";
    fileOUT << cost << " ";

}

bool POSService::printRecepit(int cost)
{
    cout << "cost: " << cost << endl;
    return false;
}

void POSService::input_file_date(std::vector<std::string>& id, std::vector<std::string>& debitCard, std::vector<int>& cost)
{
    fstream fileIN;
    string word, filename;

    int count = 0;
    filename = "Text.txt";

    fileIN.open(filename.c_str());

    while (fileIN >> word)
    {
        if (count == 0)
        {
            id.push_back(word);

        }
        else if (count == 1)
        {
            debitCard.push_back(word);
        }
        else if (count == 3)
        {
            cost.push_back(stoi(word));
        }
        count++;
    }
}

void POSService::display_customer_data(vector<string> id,vector<string> debitCard, vector<int> cost)
{
    cout << to_string(10) << "Customer Generated ID";
    cout << to_string(10) << "DebitCard";
    cout << to_string(10) << "Cost";
    cout << endl;

    for (int i = 0; i < id.size(); i++)
    {
        cout << to_string(10) << id[i];
        cout << to_string(10) << debitCard[i];
        cout << to_string(10) << cost[i];
        cout << endl;
    }
    cout << endl;


}
