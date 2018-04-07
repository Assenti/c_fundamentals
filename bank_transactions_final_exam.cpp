#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#define TRANSACTIONS_MAX_SIZE 200
#define ACCOUNTS_MAX_SIZE 20
#define ACCOUNT_ID_SIZE 10 //for convenience 
#define ACCOUNT_PASSWORD_SIZE 10
#define ACCOUNT_NAME_HOLDER_SIZE 20
#define CLIENT_ID_SIZE 10

#include<iostream>
#include<string>
#include<algorithm>
#include<random>

using namespace std;
#pragma region Business Rules
//Account -> AccountType [1 - 4]
//AccountType::1 - Each transaction requires
//commission of 3.0% of transaction amount
//to serving bank
//AccountType::2 - Each transaction requires
//commission of 1.0% of transaction amount
//to serving bank
//AccountType::3 - Each transaction requires
//commission of 0.0% of transaction amount
//to serving bank
//AccountType::2 - Each transaction returns
//cashback of 3.0% of transaction amount
//to operation performer
//
//Account -> CurrentSum calculation rules:
//Sent = All Transactions where SenderId = AccountId
//Received = All Transactions where ReceiverId = AccountId
//CurrentSum = Received - Sent
//
//Transaction adding rule:
//For each transaction add an extra transaction for commission to bank
//Example:
//Account A1 with AccountType = 1 sends 400$ to Account A2
//Transaction T1 : A1 A2 400$
//Transaction T2 : A1 BANK 400$ * 3.0%
//
//Account:
//Для каждого акаунта пароль хранить в защифрованном виде
//
//Общие технические требования:
//- Максимальное количество клиентов - 20
//- Максимальное количество транзакции - 200
//- Максимальное количество банков - 1
//- В момент первого запуска программы проверить, имеется ли
//БД (база данных (accounts.txt, transactions.txt, bank.txt),
//если нет, то воссоздать по следующим правилам:
//- 50% от суммы денег в банке распределяются случайным
//образом между всеми 20 аккаунтами и фиксируются в БД
//- ID аккаунта генерируется автоматически в виде AC2113, DC1222... .
#pragma endregion

#pragma region Structure Definition
struct Bank
{
	string company_id;
	string company_name;
	double finance_amount;
};

struct Account {
	string account_id;
	string account_holder_name;
	string account_password;
	int account_type;
};

struct Transaction {
	string sender_account_id;
	string receiver_account_id;
	double transaction_amount;
};
#pragma endregion

#pragma region Used global variables
//Storages definitions
const char * storage_table_bank = "Bank",
		   * storage_table_accounts = "Accounts",
		   * storage_table_transactions = "Transactions";

//Counters definitions
int bank_counter = 0,
    accounts_counter = 0,
    transactions_counter = 0;

//Temporary storage definitions
Bank company[1]{"KZKOKZKX","QAZKOM"}; 
Account * accounts = new Account[ACCOUNTS_MAX_SIZE];
Transaction* transactions = new Transaction[TRANSACTIONS_MAX_SIZE];

//Crypt key
int crypt_key = 7;
#pragma endregion 

#pragma region Function Definition
template <typename T> T * serialize_single_data(T * data, const char * table_name);

template <typename T> T * serialize_data_with_rewrite(T * data, const char * table_name);

template <typename T> T * deserialize_data(const char * name, int &counter);

template <typename T, typename K> void assign_value(T transmitted_value, K &returned_value);

bool detect_account_db(); 

void system_initialize();

void random_transactions_adding(double half_amount);

int generate_random_number(int range_from, int range_to);

double amount_randomizer(double amount, int size);

string random_name();

string random_password();

string password_encrypt(string &origin_password);

string password_decrypt(string crypted_password);

string account_id_generator();

void accounts_list();

void add_transactions_menu();

void comission_or_cashback_auto_transaction(Transaction * transaction, string sender_id, double amount);

double calculate_comission(int account_type, double amount);

int get_account_type_by_account_id(string account_id);

string get_name_by_account_id(string account_id);

void display_transactions_base();

double * get_transaction_by_account_id_where_he_is_sender(string account_id);

double * get_transaction_by_account_id_where_he_is_receiver(string account_id);

void display_accounts_info_menu();

void display_accounts_info(string account_id);

bool id_validating(string account_id);

bool main_menu();

void accounts_full_info();

void display_banks_transactions();

void bank_capital_info();
#pragma endregion

#pragma region Main
int main()
{
	system_initialize();
	
	//Function for getting internal info
	//accounts_full_info();
	
	return 0;
}
#pragma endregion

#pragma region Function Implementation
template <typename T> T * serialize_single_data(T * data, const char * table_name) {
	FILE * fp = fopen(table_name, "ab");
	int size = sizeof(T);
	char * binary_data;
	if (fp != NULL) {
		binary_data = (char *)data;
		for (int i = 0; i < size; i++) {
			putc(*binary_data++, fp);
		}
		fclose(fp);
	}
	return data;
}

template <typename T> T * serialize_data_with_rewrite(T * data, const char * table_name) {
	FILE * fp = fopen(table_name, "wb");
	int size = sizeof(T);
	char * binary_data;
	if (fp != NULL) {
		binary_data = (char *)data;
		for (int i = 0; i < size; i++) {
			putc(*binary_data++, fp);
		}
		fclose(fp);
	}
	return data;
}

template <typename T> T * deserialize_data(const char * name, int &counter)
{
	FILE * fp = fopen(name, "rb");
	char * binary_data;
	int iterator = 0;
	int inner_counter = 0;
	T * ptr = (T *)malloc(sizeof(T) * 100);
	if (ptr != NULL)
	{
		binary_data = (char *)ptr;
		while ((iterator = getc(fp)) != EOF)
		{
			*binary_data = iterator;
			binary_data++;
			inner_counter++;
			if (inner_counter == sizeof(T)) {
				counter++;
				inner_counter = 0;
			}
		}
	}
	fclose(fp);
	return ptr;
}

template <typename T, typename K> void assign_value(T transmitted_value, K &returned_value)
{
	returned_value = transmitted_value;
}

void system_initialize()
{
	bool is_accounts_db_exist = detect_account_db();
	
	if (!(is_accounts_db_exist))
	{
		cout << "Enter the initial bank capital amount: ";
		cin >> company->finance_amount;
		serialize_single_data<Bank>(company, storage_table_bank);
		
		random_transactions_adding(company->finance_amount/2);
		cout << "Thank you, accounts were successfully generated, please re-open the app" << endl;
	}
	else
	{
		cout << "\nData bases detected. Please use shown options in menu.\n" << endl;
		bool check = true;
		while (check)
		{
			check = main_menu();
		}
	}
}

void random_transactions_adding(double half_amount)
{
	Transaction * transaction = new Transaction[TRANSACTIONS_MAX_SIZE];
	Account * account = new Account[ACCOUNTS_MAX_SIZE];

	for (int i = 0; i < ACCOUNTS_MAX_SIZE; i++)
	{
		//Filling transaction info
		assign_value(company->company_id, transaction->sender_account_id);
		assign_value(account_id_generator(), transaction->receiver_account_id);
		transaction->transaction_amount = amount_randomizer(half_amount, ACCOUNTS_MAX_SIZE);
		//Filling account info
		assign_value(transaction->receiver_account_id, account->account_id);
		assign_value(random_name(), account->account_holder_name);
		assign_value(random_password(), account->account_password);
		password_encrypt(account->account_password);
		int rand_type = generate_random_number(1, 4);
		account->account_type = rand_type;

		serialize_single_data<Transaction>(transaction, storage_table_transactions);
		serialize_single_data<Account>(account, storage_table_accounts);

		transaction++;
		account++;
	}
}

void add_transactions_menu()
{
	Transaction * transaction = new Transaction;
	accounts_list();
	cout << "Let's make a new transaction" << endl;
	cout << "Enter sender's account ID: ";
	cin >> transaction->sender_account_id;
	cout << "Enter receiver's account ID: ";
	cin >> transaction->receiver_account_id;
	cout << "Enter transaction amount: ";
	cin >> transaction->transaction_amount;
	serialize_single_data<Transaction>(transaction, storage_table_transactions);

	comission_or_cashback_auto_transaction(transaction, transaction->sender_account_id,
		transaction->transaction_amount);
}

void comission_or_cashback_auto_transaction(Transaction * transaction, string sender_id, double amount)
{
	Bank * bank = new Bank;
	bank = deserialize_data<Bank>(storage_table_bank, bank_counter);
	accounts = deserialize_data<Account>(storage_table_accounts, accounts_counter);
	int account_type = get_account_type_by_account_id(sender_id);

	if (account_type == 1 || account_type == 2)
	{
		assign_value(bank->company_id, transaction->receiver_account_id);
		assign_value(sender_id, transaction->sender_account_id);
		double comission = calculate_comission(account_type, amount);
		transaction->transaction_amount = comission;
		bank->company_id = company->company_id;
		bank->company_name = company->company_name;
		bank->finance_amount += comission;
	}
	else if (account_type == 4)
	{
		assign_value(sender_id, transaction->receiver_account_id);
		assign_value(bank->company_id, transaction->sender_account_id);
		double cashback = calculate_comission(account_type, amount);
		transaction->transaction_amount = cashback;
		bank->company_id = company->company_id;
		bank->company_name = company->company_name;
		bank->finance_amount += cashback;
	}
	else
	{
		return;
	}

	serialize_data_with_rewrite<Bank>(bank, storage_table_bank);
	serialize_single_data<Transaction>(transaction, storage_table_transactions);
	accounts_counter = 0;
	bank_counter = 0;
}

void accounts_list()
{
	accounts = deserialize_data<Account>(storage_table_accounts, accounts_counter);
	cout << "ACCOUNTS LIST: " << endl;
	for (int i = 0; i < accounts_counter; i++)
	{
		cout << i+1 <<") " << "HOLDER: " << accounts->account_holder_name 
			 << " | ID: " << accounts->account_id 
			 << " | TYPE: " << accounts->account_type << endl;
		accounts++;
	}
	accounts_counter = 0;
}

void accounts_full_info() // For checking only (internal info)
{
	accounts = deserialize_data<Account>(storage_table_accounts, accounts_counter);
	cout << "ACCOUNTS LIST: " << endl;
	for (int i = 0; i < accounts_counter; i++)
	{
		cout << i + 1 << ") " << "HOLDER: " << accounts->account_holder_name
			<< " | ID: " << accounts->account_id
			<< " | PSWR (encrypted): " << password_encrypt(accounts->account_password)
			<< " | PSWR (decrypted): " << password_decrypt(accounts->account_password)
			<< " | TYPE: " << accounts->account_type << endl;
		accounts++;
	}
	accounts_counter = 0;
}

void display_transactions_base() 
{
	transactions = deserialize_data<Transaction>(storage_table_transactions, transactions_counter);

	cout << "ALL TRANSACTIONS: " << endl;
	for (int i = 0; i < transactions_counter; i++)
	{
		cout << i+1 << ") (S): " << transactions->sender_account_id << 
						" -->> (R): " << transactions->receiver_account_id << 
						" = " << transactions->transaction_amount << "$" << endl;
		transactions++;
	}
	transactions_counter = 0;
}

void display_accounts_info(string account_id)
{
	accounts = deserialize_data<Account>(storage_table_accounts, accounts_counter);
	transactions = deserialize_data<Transaction>(storage_table_transactions, transactions_counter);
	double send_amount = 0, receive_amount = 0, balance = 0;

	if (id_validating(account_id))
	{
		cout << "ACCOUNT STATEMENT" << endl;
		cout << "HOLDER: " << get_name_by_account_id(account_id) <<
				" | Account type: " << get_account_type_by_account_id(account_id) << endl;
		for (int i = 0; i < transactions_counter; i++)
		{
			if (account_id == transactions->receiver_account_id)
			{
				cout << "+" << transactions->transaction_amount << " (INCOME)\n";
				receive_amount += transactions->transaction_amount;
			}
			if (account_id == transactions->sender_account_id)
			{
				int acc_type = get_account_type_by_account_id(account_id);
				double comission = calculate_comission(acc_type, transactions->transaction_amount);
				cout << "-" << transactions->transaction_amount << " (EXPENSE)\n";
				/*char sign = comission >= 0 ? '-' : '+';
				string cmsn_or_cshb = comission >= 0 ? " (COMISSION)\n" : " (CASHBACK)\n";
				cout << sign << comission << cmsn_or_cshb;*/
				send_amount += transactions->transaction_amount;
			}
			transactions++;
		}
		balance = receive_amount - send_amount;
		cout << "BALANCE: " << balance << endl;
	}
	else
	{
		cout << "There is no such ID, enter the correct ID" << endl;
	}
	transactions_counter = 0;
	accounts_counter = 0;
}

/****************************Secondary functions*********************************/
bool main_menu()
{
	cout << "********************MAIN MENU*************************" << endl;
	cout << "1 - ADD A NEW TRANSACTION" << endl;
	cout << "2 - CLIENT ACCOUNT DETAILS" << endl;
	cout << "3 - TRANSACTIONS LIST" << endl;
	cout << "4 - BANK ACCOUNT DETAILS" << endl;
	cout << "0 - EXIT" << endl;
	
	int command;
	cin >> command;

	switch (command)
	{
	case 0:
		return false;
	case 1:
		add_transactions_menu();
		break;
	case 2:
		display_accounts_info_menu();
		break;
	case 3:
		display_transactions_base();
		break;
	case 4:
		bank_capital_info();
		break;
	default:
		return false;
	}
}

int generate_random_number(int range_from, int range_to) {
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int> distr(range_from, range_to);

	return distr(generator);
}

void display_accounts_info_menu()
{
	accounts_list();
	cout << "Enter account's ID: ";
	string account_id;
	cin >> account_id;
	display_accounts_info(account_id);
}

bool detect_account_db() // This is the primary database, so it's better to check the availability of this database
{
	FILE * file = fopen(storage_table_accounts, "r");
	bool opening_checking = file != NULL ? opening_checking = true : opening_checking = false;
	return opening_checking;
}

bool id_validating(string account_id)
{
	for (int i = 0; i < accounts_counter; i++)
	{
		if (account_id == accounts->account_id)
		{
			return true;
			break;
		}
		accounts++;
	}
	return false;
}

double calculate_comission(int account_type, double amount)
{
	if (account_type == 1 || account_type == 4)
	{
		return amount * 0.03;
	}
	else if (account_type == 2)
	{
		return amount * 0.01;
	}
	else if (account_type == 3)
	{
		return 0;
	}
}

int get_account_type_by_account_id(string account_id)
{
	for (int i = 0; i < accounts_counter; i++)
	{
		if (account_id == accounts->account_id)
		{
			return accounts->account_type;
		}
		accounts++;
	}
}

string get_name_by_account_id(string account_id)
{
	for (int i = 0; i < accounts_counter; i++)
	{
		if (account_id == accounts->account_id)
		{
			return accounts->account_holder_name;
		}
		accounts++;
	}
}

double amount_randomizer(double half_amount, int size)
{
	int half_amount_copy = half_amount;
	double * amounts_arr = new double[size];
	int sum = 0, random_divider = 0, rand_index = 0;

	for (int i = 0; i < size; i++)
	{
		random_divider = generate_random_number(5, 8);
		int split_amount = half_amount / random_divider;
		half_amount -= split_amount;
		amounts_arr[i] = split_amount;
		sum += amounts_arr[i];
	}

	if (sum < half_amount_copy)
	{
		amounts_arr[size - 1] += half_amount_copy - sum;
	}

	for (int i = 0; i < size; i++)
	{
		rand_index = generate_random_number(0, size-1);
	}

	return amounts_arr[rand_index];
}

string random_name()
{
	string names[ACCOUNTS_MAX_SIZE] =
	{ "Steve", "Mark", "Bill", "Linus", "Tim", "Larry", "Sergey", "Pavel",
		"Ilon", "Jeff", "Dennis", "James", "Sundar", "Satya", "Iskander",
		"Guido", "Ken", "Donald", "Brian", "Bjarne" };
	int rand_index = 0;
	for (int i = 0; i < ACCOUNTS_MAX_SIZE/3; i++)
	{
		rand_index = generate_random_number(0, ACCOUNTS_MAX_SIZE-1);;
	}
	return names[rand_index];
}

string random_password()
{
	string passwords[ACCOUNTS_MAX_SIZE] = { "St123", "Ma123", "Bi123", "Li123", "Ti123", "La123", "Se123", "Pa123",
		"Il123", "Je123", "De123", "Ja123", "Su123", "Sa123", "Is123",
		"Gu123", "Ke123", "Do123", "Br123", "Bj123" };
	int rand_index = 0;
	for (int i = 0; i < 5; i++)
	{
		rand_index = generate_random_number(0, ACCOUNTS_MAX_SIZE-1);
	}
	return passwords[rand_index];
}

double * get_transaction_by_account_id_where_he_is_sender(string account_id)
{
	double * sender_transactions = new double[TRANSACTIONS_MAX_SIZE];
	int counter = 0;
	for (int i = 0; i < TRANSACTIONS_MAX_SIZE; i++)
	{
		if (account_id == transactions->sender_account_id)
		{
			sender_transactions[counter] = transactions->transaction_amount;
			counter++;
		}
		transactions++;
	}
	return sender_transactions;
}

double * get_transaction_by_account_id_where_he_is_receiver(string account_id)
{
	double * receiver_transactions = new double[TRANSACTIONS_MAX_SIZE];
	int counter = 0;
	for (int i = 0; i < TRANSACTIONS_MAX_SIZE; i++)
	{
		if (account_id == transactions->receiver_account_id)
		{
			receiver_transactions[counter] = transactions->transaction_amount;
			counter++;
		}
		transactions++;
	}
	return receiver_transactions;
}

string password_encrypt(string &origin_password)
{
	string temple;
	for (int i = 0; i < origin_password.length(); i++)
	{
		temple += (int)origin_password[i] + crypt_key;
	}
	origin_password = temple;
	return origin_password;
}

string password_decrypt(string crypted_password)
{
	string origin_password;
	for (int i = 0; i < crypted_password.length(); i++)
	{
		origin_password += (int)crypted_password[i] - crypt_key;
	}
	return origin_password;
}

string account_id_generator()
{
	char convert_helper[2];
	string id;
	int first_two_letter_rand = 0, rand_number = 0;
	for (int i = 0; i < ACCOUNT_ID_SIZE; i++)
	{
		first_two_letter_rand = generate_random_number(65, 90); // range from 65 to 90 uppercase letters in ascii
		rand_number = generate_random_number(0, 9);
		if (i < 2)
		{
			id += (char)first_two_letter_rand;
		}
		else
		{
			id += _itoa(rand_number, convert_helper, 10)[0];
		}
	}
	return id;
}

void display_banks_transactions()
{
	transactions = deserialize_data<Transaction>(storage_table_transactions, transactions_counter);
	int trans_counter = 0;
	double sent_sum = 0, rec_sum = 0;
	for (int i = 0; i < transactions_counter; i++)
	{
		if (transactions->receiver_account_id == company->company_id)
		{
			cout << "+" << transactions->transaction_amount << "$" << endl;
			trans_counter++;
			rec_sum += transactions->transaction_amount;
		}
		else if (transactions->sender_account_id == company->company_id)
		{
			cout << "-" << transactions->transaction_amount << "$" << endl;
			trans_counter++;
			sent_sum -= transactions->transaction_amount;
		}
		transactions++;
	}
	cout << trans_counter << " transactions" << endl;
	cout << "TOTAL EXPENSE: " << sent_sum << " | TOTAL INCOME: " << rec_sum << endl;
	transactions_counter = 0;
}

void bank_capital_info()
{
	Bank * bank = new Bank;
	bank = deserialize_data<Bank>(storage_table_bank, bank_counter);
	display_banks_transactions();
	bank_counter = 0;
}
#pragma endregion


