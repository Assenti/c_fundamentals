#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<stdio.h>   
#include<cstdlib>
#include<string>

using namespace std;

#pragma region Structures
struct Interpreter {
	char Id[10];
	char Name[20];
};

struct Language {
	char Id[10];
	char Name[20];
};

struct InterpreterLanguage {
	char InterpreterId[10];
	char LanguageId[10];
	int LevelOfKnowledge;
};
#pragma endregion

int interpreters_count = 0,
languages_count = 0,
interpretersLanguages_count = 0;

Interpreter * interpreters;
Language * languages;
InterpreterLanguage * interpretersLanguages;

const char * storage_table_interpreters = "INTERPRETERS";
const char * storage_table_languages = "LANGUAGES";
const char * storage_table_interpretersLanguages = "INTERPRETERSLANGUAGES";

#pragma region Functions prototypes
template <typename T>
T * add_record(T * data, const char * table_name);

template <typename T>
T * deserialize_data(const char * name, int & counter);

void add_interpreter_diaglogue_window();

void add_language_diaglogue_window();

void add_interpreterlanguage_diaglogue_window();

void show_all_languages_of_interpreter_diaglogue_window();

void show_info_about_language_interpreters_diaglogue_window();

void prepare_program();

char * get_name_by_id(string interpreter_id);

char * get_id_by_language(string language_name);

char * get_id_by_name(string interpreter_name);

bool main_menu();

void display_interpreters_n_languages();
#pragma endregion

int main() {
	bool check = true;

	while (check)
	{
		check = main_menu();
	}

	system("pause");
	return 0;
}

#pragma region Functions implementations
template <typename T>
T * add_record(T * data, const char * table_name) {
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


template <typename T>
T * deserialize_data(const char * name, int & counter)
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

void add_interpreter_diaglogue_window() {
	Interpreter * record = new Interpreter;

	cout << "Please enter an interpreter ID:...[10 symbols]:" << endl;
	cin >> record->Id;
	cout << "Please enter an interpreter name:...[20 symbols]:" << endl;
	cin >> record->Name;

	add_record<Interpreter>(record, storage_table_interpreters);
}

void add_language_diaglogue_window() {
	Language * record = new Language;

	cout << "Please enter a language ID:...[10 symbols]:" << endl;
	cin >> record->Id;
	cout << "Please enter a language name:...[20 symbols]:" << endl;
	cin >> record->Name;

	add_record<Language>(record, storage_table_languages);
}

void add_interpreterlanguage_diaglogue_window() {
	InterpreterLanguage * record = new InterpreterLanguage;
	display_interpreters_n_languages();
	cout << "Please enter an interpreter ID:...[10 symbols]:" << endl;
	cin >> record->InterpreterId;
	cout << "Please enter a language ID:...[10 symbols]:" << endl;
	cin >> record->LanguageId;
	cout << "Please enter a language knowledge level:..." << endl;
	cin >> record->LevelOfKnowledge;

	add_record<InterpreterLanguage>(record, storage_table_interpretersLanguages);
}

void show_all_languages_of_interpreter_diaglogue_window() {
	prepare_program();

	cout << "Enter the interpreters name: ";
	string interpreter_name;
	cin >> interpreter_name;

	for (int i = 0; i < interpretersLanguages_count; i++) {
		string first(interpretersLanguages->InterpreterId);
		string second = get_id_by_name(interpreter_name);

		if (first == second) {
			cout << "LANGUAGE: " << interpretersLanguages->LanguageId <<
				" | LEVEL: " << interpretersLanguages->LevelOfKnowledge << endl;
		}
		interpretersLanguages++;
	}
}

void show_info_about_language_interpreters_diaglogue_window() {
	prepare_program();

	cout << "Enter the language name [English, Russian, Kazakh]: ";
	string language_name;
	cin >> language_name;

	for (int i = 0; i < interpretersLanguages_count; i++) {
		string first(interpretersLanguages->LanguageId);
		string second = get_id_by_language(language_name);
		string interpreters_name = get_name_by_id(interpretersLanguages->InterpreterId);

		if (first == second) {
			cout << "NAME: " << interpreters_name << " | LEVEL: " << interpretersLanguages->LevelOfKnowledge << endl;
		}
		interpretersLanguages++;
	}
}

void prepare_program() {
	interpreters = deserialize_data<Interpreter>(storage_table_interpreters, interpreters_count);
	languages = deserialize_data<Language>(storage_table_languages, languages_count);
	interpretersLanguages = deserialize_data<InterpreterLanguage>(storage_table_interpretersLanguages, interpretersLanguages_count);

}

char * get_name_by_id(string interpreter_id)
{
	interpreters = deserialize_data<Interpreter>(storage_table_interpreters, interpreters_count);

	for (int i = 0; i < interpreters_count; i++)
	{
		string first = interpreters->Id;
		string second = interpreter_id;
		if (first == second)
		{
			return interpreters->Name;
		}
		interpreters++;
	}
}

char * get_id_by_language(string language_name)
{
	languages = deserialize_data<Language>(storage_table_languages, languages_count);

	for (int i = 0; i < languages_count; i++)
	{
		string first = languages->Name;
		string second = language_name;
		if (first == second)
		{
			return languages->Id;
		}
		languages++;
	}
}

char * get_id_by_name(string interpreter_name)
{
	interpreters = deserialize_data<Interpreter>(storage_table_interpreters, interpreters_count);

	for (int i = 0; i < languages_count; i++)
	{
		string first = interpreters->Name;
		string second = interpreter_name;
		if (first == second)
		{
			return interpreters->Id;
		}
		interpreters++;
	}
}

void display_interpreters_n_languages()
{
	interpreters = deserialize_data<Interpreter>(storage_table_interpreters, interpreters_count);
	languages = deserialize_data<Language>(storage_table_languages, languages_count);
	for (int i = 0; i < interpreters_count; i++)
	{
		cout << "ID: " << interpreters->Id << " | NAME: " << interpreters->Name << endl;
		interpreters++;
	}
	for (int i = 0; i < languages_count; i++)
	{
		cout << "ID: " << languages->Id << " | NAME: " << languages->Name << endl;
		languages++;
	}
	interpreters_count = 0;
	languages_count = 0;
}


bool main_menu()
{
	cout << "1 - Add an interpreter" << endl;
	cout << "2 - Add a language" << endl;
	cout << "3 - Add an info to interpreters and languages" << endl;
	cout << "4 - Show info about interpreters languages knowledge" << endl;
	cout << "5 - Show information about language interpreters" << endl;
	cout << "0 - EXIT" << endl;

	int command;
	cin >> command;
	switch (command)
	{
	case 0:
		return false;
	case 1:
		add_interpreter_diaglogue_window();
		break;
	case 2:
		add_language_diaglogue_window();
		break;
	case 3:
		add_interpreterlanguage_diaglogue_window();
		break;
	case 4:
		show_all_languages_of_interpreter_diaglogue_window();
		break;
	case 5:
		show_info_about_language_interpreters_diaglogue_window();
		break;
	default:
		cout << "Wrong command" << endl;
		return false;
	}
}
#pragma endregion
