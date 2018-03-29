//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>

using namespace std;

#pragma region Structure Definition
struct Account
{
	int index_number;
	char account_id[5];
	char name[20];
	char password[10];
	double balance;
};

struct TransactionRecord
{
	int transaction_id;
	char sender_account_id[5];
	char receiver_account_id[5];
	double amount;
};
#pragma endregion

#pragma region Function Definitions

void serialize_single_account(Account * account);

void serialize_single_transaction(TransactionRecord * transaction);

Account * deserialize_account();

TransactionRecord * deserialize_transactions();

void display_account(Account * account);

void accounts_list(Account * account);

void display_transactions(TransactionRecord * transactions);

void add_account();

void add_transaction();

void add_transaction_after_deserialize();

int set_transaction_id(int current_id);

int get_max_id();

char * get_id_by_name(char * name);

double get_balance_by_id(char * id);

bool main_menu();

void display_accounts_all_transactions(char * name);

void clients_transactions_menu();

double accounts_send_transactions_sum(char * account_id);

double accounts_recieve_transactions_sum(char * account_id);

const char * status_in_operation(char * account_id);
#pragma endregion

#pragma region Global Variables
const int ACCOUNT_MAX_SIZE = 50;

Account * accounts = new Account[ACCOUNT_MAX_SIZE];

const int TRANSACTION_MAX_SIZE = 100;

TransactionRecord * transaction_records = new TransactionRecord[TRANSACTION_MAX_SIZE];

int index = 1;
int transactions_id = 1;
#pragma endregion

#pragma region Main
int main()
{
	bool check = true;

	while (check)
	{
		check = main_menu();
	}

	//system("pause");
	return 0;
}
#pragma endregion

#pragma region Function Implementation
void serialize_single_account(Account * account)
{
	FILE * fp = fopen("Accounts", "ab");
	int accout_size = sizeof(Account);
	char * binary_data;
	if (fp != NULL) {
		binary_data = (char *)account;
		for (int i = 0; i < accout_size; i++) {
			putc(*binary_data++, fp);
		}
		fclose(fp);
	}
	cout << "File successfuly created" << endl;
}

void serialize_single_transaction(TransactionRecord * transaction)
{
	FILE * fp = fopen("Transactions", "ab");
	int transactions_size = sizeof(TransactionRecord);
	char * binary_data;
	if (fp != NULL)
	{
		binary_data = (char *)transaction;
		for (int i = 0; i < transactions_size; i++)
		{
			putc(*binary_data++, fp);
		}
		fclose(fp);
	}
}

Account * deserialize_account()
{
	FILE * fp = fopen("Accounts", "rb");
	char * binary_data;
	int iterator = 0;
	Account * ptr = (Account *)malloc(sizeof(Account) * ACCOUNT_MAX_SIZE);
	binary_data = (char *)ptr;
	while ((iterator = getc(fp)) != EOF)
	{
		*binary_data = iterator;
		binary_data++;
	}
	fclose(fp);
	return ptr;
}

TransactionRecord * deserialize_transactions()
{
	FILE * fp = fopen("Transactions", "rb");
	char * binary_data;
	int iterator = 0;
	TransactionRecord * ptr = (TransactionRecord *)malloc(sizeof(TransactionRecord) * TRANSACTION_MAX_SIZE);
	binary_data = (char *)ptr;
	while ((iterator = getc(fp)) != EOF)
	{
		*binary_data = iterator;
		binary_data++;
	}
	fclose(fp);
	return ptr;
}

void display_account(Account * account)
{
	account = deserialize_account();

	for (int i = 0; i < account->index_number; i++)
	{
		cout << "ID: " << account->account_id << endl;
		cout << "NAME: " << account->name << endl;
		cout << "PASSWORD: " << account->password << endl;
		cout << "BALANCE: " << account->balance << endl;
		cout << "=========================" << endl;
		account++;
	}
}

void accounts_list(Account * account)
{
	account = deserialize_account();

	for (int i = 0; i < account->index_number; i++)
	{
		cout << account->index_number << ") ID: " << account->account_id << " | NAME: " << account->name << endl;
		account++;
	}
}

void display_transactions(TransactionRecord * transactions)
{
	transactions = deserialize_transactions();
	
	for (int i = 0; i < TRANSACTION_MAX_SIZE; i++)
	{
		if (transactions->transaction_id > 0)
		{
			cout << "TRANSACTION ID: " << transactions->transaction_id << endl;
			cout << "SENDER ID: " << transactions->sender_account_id << endl;
			cout << "RECEIVER ID: " << transactions->receiver_account_id << endl;
			cout << "AMOUNT: " << transactions->amount << endl;
			cout << "==========================" << endl;
			transactions++;
		}
		else
		{
			return;
		}
	}
}

void add_account()
{
	cout << "Enter the following data to create a new account" << endl;

	while (true)
	{
		accounts->index_number = index;
		index++;

		cout << "Enter ID: ";
		cin >> accounts->account_id;

		cout << "Enter NAME: ";
		cin >> accounts->name;

		cout << "Enter PASSWORD: ";
		cin >> accounts->password;

		cout << "Enter INITIAL VALUE: ";
		cin >> accounts->balance;

		serialize_single_account(accounts);

		cout << "Do you want to add another account? [Y] - YES, [N] - NO" << endl;
		char command;
		cin >> command;

		if (command == 'Y' || command == 'y')
		{
			display_account(accounts);
		}
		else if (command == 'N' || command == 'n')
		{
			cout << "Return to MAIN MENU >>>" << endl;
			break;
		}
		else
		{
			cout << "Wrong command code. Return to MAIN MENU >>>" << endl;
			break;
		}
	}
}

void add_transaction()
{
	TransactionRecord * transaction = new TransactionRecord();
	accounts = deserialize_account();
	cout << "Clients list: " << endl;
	accounts_list(accounts);
	cout << "Enter the following data to create a new transaction" << endl;

	while (true)
	{
		transaction_records->transaction_id = transactions_id;
		transactions_id++;
		
		cout << "Enter SENDER ID: ";
		cin >> transaction_records->sender_account_id;

		cout << "Enter RECEIVER ID: ";
		cin >> transaction_records->receiver_account_id;

		cout << "Enter AMOUNT: ";
		cin >> transaction_records->amount;

		double sender_balance = get_balance_by_id(transaction_records->sender_account_id);
		double receiver_balance = get_balance_by_id(transaction_records->receiver_account_id);
		sender_balance -= transaction_records->amount;
		receiver_balance += transaction_records->amount;

		cout << "OK, transaction successfully completed" << endl;

		serialize_single_transaction(transaction_records);
		serialize_single_account(accounts);

		cout << "Do you want to add another transaction? [Y] - YES, [N] - NO" << endl;
		char command;
		cin >> command;

		if (command == 'N' || command == 'n')
		{
			cout << "OK, OPERATION COMPLETED" << endl;
			break;
		}
		else if (command == 'Y' || command == 'y')
		{
			display_transactions(transaction_records);
		}
		else
		{
			cout << "WRONG COMMAND CODE, YOU SHALL NOT PASS!" << endl;
		}
	}
}

void add_transaction_after_deserialize()
{
	transaction_records = deserialize_transactions();
	accounts = deserialize_account();

	cout << "Clients list: " << endl;
	accounts_list(accounts);
	cout << "Enter the following data to create a new transaction" << endl;

	while (true)
	{
		transaction_records->transaction_id = set_transaction_id(transactions_id);
		transactions_id++;

		cout << "Enter SENDER ID: ";
		cin >> transaction_records->sender_account_id;

		cout << "Enter RECEIVER ID: ";
		cin >> transaction_records->receiver_account_id;

		cout << "Enter AMOUNT: ";
		cin >> transaction_records->amount;

		double sender_balance = get_balance_by_id(transaction_records->sender_account_id);
		double receiver_balance = get_balance_by_id(transaction_records->receiver_account_id);
		sender_balance -= transaction_records->amount;
		receiver_balance += transaction_records->amount;

		cout << "OK, transaction successfully completed" << endl;

		serialize_single_transaction(transaction_records);
		serialize_single_account(accounts);

		cout << "Do you want to add another transaction? [Y] - YES, [N] - NO" << endl;
		char command;
		cin >> command;

		if (command == 'N' || command == 'n')
		{
			cout << "OK, OPERATION COMPLETED" << endl;
			break;
		}
		else if (command == 'Y' || command == 'y')
		{
			display_transactions(transaction_records);
		}
		else
		{
			cout << "WRONG COMMAND CODE, YOU SHALL NOT PASS!" << endl;
		}
	}
}

int get_max_id()
{
	TransactionRecord * transaction_records = deserialize_transactions();

	int max_id = INT_MIN;	
	for (int i = 0; i < TRANSACTION_MAX_SIZE; i++)
	{
		if (transaction_records->transaction_id > max_id)
		{
			max_id = transaction_records->transaction_id;
		}
		transaction_records++;
	}
	return max_id;
}

int set_transaction_id(int current_id)
{
	int id = get_max_id();
	if (transactions_id == 1) 
	{
		return ++id;
	}
	else
	{
		return current_id;
	}
}

char * get_id_by_name(char * name)
{
	accounts = deserialize_account();
	string help;

	for (int i = 0; i < ACCOUNT_MAX_SIZE; i++)
	{
		help = accounts->name;
		if (help == name)
		{
			return accounts->account_id;
		}
		accounts++;
	}
}

double get_balance_by_id(char * id)
{
	accounts = deserialize_account();
	string help;

	for (int i = 0; i < ACCOUNT_MAX_SIZE; i++)
	{
		help = accounts->account_id;
		if (help == id)
		{
			return accounts->balance;
		}
		accounts++;
	}
}

double accounts_send_transactions_sum(char * account_id)
{
	TransactionRecord * transaction_records = deserialize_transactions();
	
	int size = get_max_id();
	double sender_sum = 0;

	for (int i = 0; i < size; i++)
	{
		string sender_id = transaction_records->sender_account_id;
		if (account_id == sender_id)
		{
			sender_sum += transaction_records->amount;
		}
		transaction_records++;
	}
	return sender_sum;
}

double accounts_recieve_transactions_sum(char * account_id)
{
	TransactionRecord * transaction_records = deserialize_transactions();
	
	int size = get_max_id();
	double receiver_sum = 0;

	for (int i = 0; i < size; i++)
	{
		string receiver_id = transaction_records->receiver_account_id;
		if (account_id == receiver_id)
		{
			receiver_sum += transaction_records->amount;
		}
		transaction_records++;
	}
	return receiver_sum;
}

const char * status_in_operation(char * account_id)
{
	TransactionRecord * transaction_records = deserialize_transactions();
	string checking_id = account_id;

	if (checking_id == transaction_records->receiver_account_id)
	{
		return "Receiver";
	}
	else
	{
		return "Sender";
	}
}

void display_accounts_all_transactions(char * name)
{
	TransactionRecord * transaction_records = deserialize_transactions();

	char * id = new char[5];
	id = get_id_by_name(name);
	string compare_id = id;

	cout << "Below are all " << name << "'s transactions" << endl;
	double initial_balance = get_balance_by_id(get_id_by_name(name));
	double balance = initial_balance - accounts_send_transactions_sum(id)+
		accounts_recieve_transactions_sum(id);
	cout << name << "'s initial balance: " << initial_balance << endl;
	cout << name << "'s current balance: " << balance << endl;

	for (int i = 0; i < TRANSACTION_MAX_SIZE; i++)
	{

		if (transaction_records->transaction_id > 0)
		{
			if (compare_id == transaction_records->sender_account_id ||
				compare_id == transaction_records->receiver_account_id)
			{
				cout << "Transaction's id: " << transaction_records->transaction_id << endl;
				cout << "Status in operation: " << status_in_operation(id) << endl;
				cout << "Transaction's amount: " << transaction_records->amount << endl;
				cout << "=================================" << endl;
			}
			transaction_records++;	
		}
		else
		{
			return;
		}
	}
}

void clients_transactions_menu()
{
	cout << "Enter the account's name: ";
	char name[25];
	cin >> name;
	display_accounts_all_transactions(name);
}

bool main_menu()
{
	cout << "--------MAIN MENU--------" << endl;
	cout << "Choose command code" << endl;
	cout << "1 - Add a new client (with serialization)" << endl;
	cout << "2 - Display a clients base (deserialization)" << endl;
	cout << "3 - Add a new transaction (with serialization)" << endl;
	cout << "4 - Add a new transaction after closing program" << endl;
	cout << "5 - Display a transactioins base (deserializtion)" << endl;
	cout << "6 - Display client's all transactions info" << endl;
	cout << "0 - Exit" << endl;

	int command;
	cout << "Your command code: ";
	cin >> command;

	switch (command)
	{
	case 0:
		return false;
	case 1:
		add_account();
		break;
	case 2:
		accounts_list(accounts);
		break;
	case 3:
		add_transaction();
		break;
	case 4:
		add_transaction_after_deserialize();
		break;
	case 5:
		display_transactions(transaction_records);
		break;
	case 6:
		clients_transactions_menu();
		break;
	default:
		break;
	}
}
#pragma endregion