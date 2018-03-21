#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<fstream>

using namespace std;


int const clients_number = 20;
int const transactions_number = 20;
double bank_comission_percentage = 0.05;
int current_transaction_id = 0;
double exchange_1_usd_cost_kzt = 323.3;
double exchange_1_eur_cost_kzt = 399.0;
double exchange_1_eur_cost_usd = 1.229;


#pragma region Structures

struct Bank
{
	string bank_name;
};

struct Client_account
{
	int account_id; //from 100 - credit, from 200 - deposit
	string account_currency; //KZT, USD, EUR
	double account_balance;
};

struct Bank_client
{
	int client_id;
	string client_name;
	Bank bank_name;
	Client_account client_account;
};

struct Bank_transaction {
	Bank_client sender;
	Bank_client recipient;

	//Transaction's info
	int transaction_id;
	double transaction_sum;
	string currency;
	double bank_comission;

	//Struct's method
	void Print()
	{
		cout << "transaction's id: " << transaction_id << endl;
		cout << "transaction's amount: " << transaction_sum << endl;
		cout << "transaction's currency: " << currency << endl;
		cout << "transaction's comission: " << bank_comission << endl;
	}
};

#pragma endregion

#pragma region Data_bases

Bank_client clients_base[clients_number] =
{
	{ 0, "David", "AMRO Bank",
		{ 100, "KZT", 15000.55 }
	},
	{ 1, "Henry", "CITI Bank",
		{ 101, "USD", 25550.75 }
	},
	{ 2, "Harold", "Qazkom",
		{ 103, "EUR", 50000.55 }
	},
	{ 3, "Mark", "Halyk Bank",
	{ 104, "KZT", 100000 }
	},
	{ 4, "Ben", "ForteBank",
	{ 105, "USD", 555444.75 }
	},
	{ 5, "John", "Bank CenterCredit",
	{ 106, "KZT", 159159 }
	},
	{ 6, "Peter", "Sberbank",
	{ 107, "EUR", 258852 }
	},
	{ 7, "James", "NY Bank",
	{ 108, "USD", 159951.35 }
	},
	{ 8, "William", "London Bank",
	{ 109, "KZT", 200654 }
	},
	{ 9, "Philip", "China Agriculture Bank",
	{ 110, "USD", 450000.25 }
	}
};

Bank_transaction transactions_base[transactions_number];

#pragma endregion

#pragma region Functions prototypes
//overload of operator <<
ostream& operator << (ostream& os, const Bank_transaction& transaction);
//overload of operator >>
istream& operator >> (istream& is, Bank_transaction& transaction);

string get_name_by_id(int wanted_id);

string get_bank_name_by_id(int wanted_id);

int get_account_id_by_clients_id(int wanted_id);

int get_index_in_base_by_id(int wanted_id);

double currency_convert(string currency_from, string currency_to, double number);

void make_transaction(int sender_id, int recipient_id, string currency, double transaction_sum);

void make_transaction_menu();
//Write data into file
void output_into_file(int current_index);
//Display data to console from file
void display_from_file();
#pragma endregion


/*********************Main***********************/

int main()
{
	srand(time(0));
	int size = transactions_number;
	while (size>0)
	{
		make_transaction_menu();
		size--;
	}

	//display_from_file();

	return 0;
}

/*************************************************/

#pragma region Functions

string get_name_by_id(int wanted_id)
{
	for (int i = 0; i < clients_number; i++)
	{
		if (clients_base[i].client_id == wanted_id)
		{
			return clients_base[i].client_name;
		}
	}
}

string get_bank_name_by_id(int wanted_id)
{
	for (int i = 0; i < clients_number; i++)
	{
		if (clients_base[i].client_id == wanted_id)
		{
			return clients_base[i].bank_name.bank_name;
		}
	}
}

int get_account_id_by_clients_id(int wanted_id)
{
	for (int i = 0; i < clients_number; i++)
	{
		if (clients_base[i].client_id == wanted_id)
		{
			return clients_base[i].client_account.account_id;
		}
	}
}

int get_index_in_base_by_id(int wanted_id)
{
	for (int i = 0; i < clients_number; i++)
	{
		if (clients_base[i].client_id == wanted_id)
		{
			return i;
		}
	}
}

void make_transaction(int sender_id, int recipient_id, string currency, double transaction_sum)
{
	double bank_comission = transaction_sum * bank_comission_percentage;
	int sender_index = get_index_in_base_by_id(sender_id);
	int recipient_index = get_index_in_base_by_id(recipient_id);

	transactions_base[current_transaction_id] =
	{
		clients_base[sender_index] =
	{
		clients_base[sender_index].client_id,
		clients_base[sender_index].client_name,
		clients_base[sender_index].bank_name,
	{
		clients_base[sender_index].client_account.account_id,
		clients_base[sender_index].client_account.account_currency,
		clients_base[sender_index].client_account.account_balance
	}
	},
		clients_base[recipient_index] =
	{
		clients_base[recipient_index].client_id,
		clients_base[recipient_index].client_name,
		clients_base[recipient_index].bank_name,
	{
		clients_base[recipient_index].client_account.account_id,
		clients_base[recipient_index].client_account.account_currency,
		clients_base[recipient_index].client_account.account_balance
	}
	},
		current_transaction_id,
		transaction_sum,
		currency,
		bank_comission
	};

	cout << "--------------------------------------" << endl;
	cout << "Inside information" << endl;
	
	cout << "Sender's account balance before: " <<
		clients_base[sender_index].client_account.account_balance << " " <<
		clients_base[sender_index].client_account.account_currency << endl;
	
	cout << "Recipient's account before: " <<
		clients_base[recipient_index].client_account.account_balance << " " <<
		clients_base[recipient_index].client_account.account_currency << endl;

	if (clients_base[sender_index].client_account.account_currency != currency)
	{
		string to_currency = clients_base[sender_index].client_account.account_currency;
		
		double amount_for_deduction = currency_convert(currency, to_currency, transaction_sum);
		
		clients_base[sender_index].client_account.account_balance =
			clients_base[sender_index].client_account.account_balance
			- amount_for_deduction - currency_convert(currency, to_currency, bank_comission);
		
		clients_base[recipient_index].client_account.account_balance =
						clients_base[recipient_index].client_account.account_balance
						+ transaction_sum;
	}

	else
	{
		clients_base[sender_index].client_account.account_balance =
			clients_base[sender_index].client_account.account_balance
			- transaction_sum - bank_comission;

		clients_base[recipient_index].client_account.account_balance =
			clients_base[recipient_index].client_account.account_balance
			+ transaction_sum;
	}

	cout << "--------------------------------------" << endl;
	cout << "Transaction successfully completed" << endl << endl;

	//Transaction's info output
	cout << "Transaction #: " << current_transaction_id << endl;
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	cout << "Transaction's date and time: " << asctime(timeinfo);
	cout << "Transaction amount: " << transaction_sum << " " << currency << endl;
	cout << "Bank comission: " << bank_comission << " " << currency << endl;

	//Sender's info output
	string sender_name = get_name_by_id(sender_id);
	string sender_bank_name = get_bank_name_by_id(sender_id);
	int sender_account = get_account_id_by_clients_id(sender_id);
	cout << "Sender: " << sender_name << endl;
	cout << "Sender's bank: " << sender_bank_name << endl;
	cout << "Sender's account: " << sender_account << endl;

	//Recipient's info output
	string recipient_name = get_name_by_id(recipient_id);
	string recipient_bank_name = get_bank_name_by_id(recipient_id);
	int recipient_account = get_account_id_by_clients_id(recipient_id);
	cout << "Recipient: " << recipient_name << endl;
	cout << "Recipient's bank: " << recipient_bank_name << endl;
	cout << "Recipient's account: " << recipient_account << endl;

	cout << "--------------------------------------" << endl;
	cout << "Inside information" << endl;
	cout << "Sender's account balance after: " <<
		clients_base[sender_index].client_account.account_balance << " " <<
		clients_base[sender_index].client_account.account_currency << endl;

	cout << "Recipient's account balance: " <<
		clients_base[recipient_index].client_account.account_balance << " " <<
		clients_base[recipient_index].client_account.account_currency << endl;

	output_into_file(current_transaction_id);

	++current_transaction_id;
}

double currency_convert(string currency_from, string currency_to, double number)
{
	if (currency_from == "USD" && currency_to == "KZT")
	{
		return number * exchange_1_usd_cost_kzt;
	}
	else if (currency_from == "USD" && currency_to == "EUR")
	{
		return number * exchange_1_eur_cost_usd;
	}
	else if (currency_from == "EUR" && currency_to == "USD")
	{
		return number / exchange_1_eur_cost_usd;
	}
	else if (currency_from == "EUR" && currency_to == "KZT")
	{
		return number * exchange_1_eur_cost_kzt;
	}
	else if (currency_from == "KZT" && currency_to == "USD")
	{
		return number / exchange_1_usd_cost_kzt;
	}
	else if (currency_from == "KZT" && currency_to == "EUR")
	{
		return number / exchange_1_eur_cost_kzt;
	}
}

void make_transaction_menu()
{
	cout << "-------MAKE A TRANSACTION MENU--------" << endl;

	cout << "Enter Sender's id: ";
	int sender_id;
	cin >> sender_id;

	cout << "Enter Recipient's id: ";
	int recipient_id;
	cin >> recipient_id;

	int index = get_index_in_base_by_id(recipient_id);

	cout << "Recipient account currency: " << clients_base[index].client_account.account_currency << endl;
	cout << "Enter the currency of transaction (KZT/USD/EUR),\nit must be the same with recipient account currency: ";

	string currency;
	cin >> currency;

	cout << "Enter the amount of transaction: ";
	double transaction_sum;
	cin >> transaction_sum;

	make_transaction(sender_id, recipient_id, currency, transaction_sum);
	
	cout << "\nReturning to Main menu >>>" << endl << endl;
}

ostream& operator << (ostream& os, const Bank_transaction& transaction)
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	os << "\n-----------CHEQUE-----------\n" <<
		"Sender: " << transaction.sender.client_name << "\n" <<
		"Recipient: " << transaction.recipient.client_name << "\n" <<
		"Date and time: " << asctime(timeinfo) <<
		"Transaction # " << transaction.transaction_id << "\n" <<
		"Transaction currency: " << transaction.currency << "\n" <<
		"Transaction amount: " << transaction.transaction_sum << "\n" <<
		"Transaction comission: " << transaction.bank_comission <<
		"\n----------------------------\n";

	return os;
}

istream& operator >> (istream& is, Bank_transaction& transaction)
{
	is >> transaction.sender.client_name >>
		transaction.recipient.client_name >>
		transaction.transaction_id >>
		transaction.currency >>
		transaction.transaction_sum >>
		transaction.bank_comission;

	return is;
}

void output_into_file(int current_index)
{
	string path = "cheque.txt"; //write your path - by default is created in the project folder
	
	fstream receipt;
	receipt.open(path, fstream::in | fstream::out | fstream::app);

	string error_msg = !receipt.is_open() ? "\nError\n" : "\nFile successfully opened\n";
	cout << error_msg << endl;
	
	receipt << transactions_base[current_index];
	
	receipt.close();
}

void display_from_file()
{
	string path = "base.txt"; //write your path - by default is created in the project folder

	fstream receipt;
	receipt.open(path, fstream::in | fstream::out | fstream::app);

	string error_msg = !receipt.is_open() ? "Error" : "File successfully opened";
	cout << error_msg << endl;

	while (!receipt.eof())
	{
		Bank_transaction temp;
		receipt >> temp;
		cout << temp;
	}
	
	receipt.close();
}
#pragma endregion