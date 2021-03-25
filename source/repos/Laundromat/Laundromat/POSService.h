#pragma once
#include <vector>
#include <string>
class POSService
{
public:
	bool getDebitAuth(std::vector<std::string> &debitCard, int pinNo);
	void logTransaction(std::string, std::string, int);
	bool printRecepit(int cost);

	void input_file_date(std::vector<std::string> &id, std::vector<std::string> &debitCard, std::vector<int> &cost);
	void display_customer_data(std::vector<std::string> id, std::vector<std::string> debitCard, std::vector<int> cost);

private:

};

