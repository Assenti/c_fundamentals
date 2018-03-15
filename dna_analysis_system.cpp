#include<iostream>
#include<string>
#include<random>
#include<algorithm>
#include<cstdlib>

using namespace std;

/**************************Global Variable Definition***************************/
const int total_patients_number = 7;
const int dna_size = 10000; //1000 - for good PC performance
const int doctors_number = 3;

/*******************************Structure Definition*********************************/
#pragma region 

struct Doctor {
	string doctor_name;
	string doctor_password;
};

struct Patient {
	string patient_name;
	string patient_id;
	int blood_group;
	int age;
	char dna_sequence[dna_size];
};

struct PatientDnaPercentage 
{
	string patient_id;
	double dna_analysis_result[4];
};

struct PatientDnaElements {
	string patient_id;
	int dna_analysis_result;
};

struct DnaDifferenceResultByPercentCompare {
	string patient_a_id;
	string patient_b_id;
	double percentage_difference_result;
};

struct DnaDifferenceResultByElemsCompare {
	string patient_a_id;
	string patient_b_id;
	int dna_elements_difference_result;
};


#pragma endregion

/**********************************Data base arrays**************************************/
#pragma region 
Doctor doctor_records[doctors_number] =
{
	"Iskander", "iskander",
	"Dana", "dana",
	"Assel", "assel"
};

Patient patient_records[total_patients_number] =
{
	{ "Hugh", "S12", 2 , 50 },
	{ "Mark", "C13", 1 , 40 },
	{ "Kate", "A31", 3 , 60 },
	{ "Brad", "B12", 2 , 50 },
	{ "Ryan", "A23", 2 , 35 },
	{ "Alen", "GG2", 2 , 70 },
	{ "John", "AID", 2 , 70 }
};

PatientDnaPercentage dna_results[total_patients_number * 3] =
{
	{ "S12" },
	{ "C13" },
	{ "A31" },
	{ "B12" },
	{ "A23" },
	{ "GG2" },
	{ "AID" }
};

PatientDnaElements dna_elems_compare_results[total_patients_number * 3] =
{
	{ "S12" },
	{ "C13" },
	{ "A31" },
	{ "B12" },
	{ "A23" },
	{ "GG2" },
	{ "AID" }
};

char dna_elements[4] = { 'A', 'G', 'C', 'T' };
#pragma endregion

/***********************************Function Prototype Definition********************************/
#pragma region 

int generate_random_number(int range_from, int range_to);

void generate_random_dna(char * ptr);

void initialize_patients();

void initialize_system();

void perform_percentage_analysis(
	string patient_id,
	char * dna_sequence, int dna_sequence_size,
	char * dna_elements, int dna_elements_size);

void perform_percentage_analysis_to_all();

int get_result_index_by_id(string id);

bool DnaDifferenceResultByPercent_sort(
	DnaDifferenceResultByPercentCompare a, DnaDifferenceResultByPercentCompare b);

bool DnaDifferenceResultByDnaElems_sort(
	DnaDifferenceResultByElemsCompare a, DnaDifferenceResultByElemsCompare b);

void find_percentage_similarity();

int levenstein(string value1, string  value2);

void patients_with_max_compatibilty_by_DNA_elems();

int find_composition_similarity(string first_patiend_id, string second_patient_id);

void artificial_dna_tests(double Adenin_percent, double Guanin_percent,
	double Citosin_percent, double Timin_percent);

void artificial_dna_tests_menu();

void display_patients_DNA_percentages();

void display_patients_list();

void artificial_dna_tests_modul();

void autentification_menu();

void autentification(string name, string password);

#pragma endregion

/****************************************Main********************************************/
int main() {
	initialize_patients();
	autentification_menu();
	
	system("pause");
	return 0;
}

/*********************************Function Implementation*******************************/
#pragma region 

void perform_percentage_analysis(
	string patient_id,
	char * dna_sequence, int dna_sequence_size,
	char * dna_elements, int dna_elements_size)
{
	int * occured_counter = new int[dna_elements_size] { 0 };

	for (int i = 0; i < dna_elements_size; i++) {
		for (int j = 0; j < dna_sequence_size; j++) {
			if (dna_sequence[j] == dna_elements[i]) {
				occured_counter[i]++;
			}
		}
	}

	for (int i = 0; i < total_patients_number; i++) {
		if (dna_results[i].patient_id == patient_id) {
			for (int j = 0; j < 4; j++) {
				dna_results[i].dna_analysis_result[j] =
					(double)(occured_counter[j] / (double)dna_sequence_size) * 100;
			}
		}
	}
}

int generate_random_number(int range_from, int range_to) {
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int> distr(range_from, range_to);

	return distr(generator);
}

void generate_random_dna(char * ptr) {
	for (int i = 0; i < total_patients_number; i++) {
		for (int j = 0; j < dna_size; j++) {
			ptr[j] = dna_elements[generate_random_number(0, 3)];
		}
	}
}

void initialize_patients() {
	for (int i = 0; i < total_patients_number; i++) {
		generate_random_dna(patient_records[i].dna_sequence);
	}
}

void perform_percentage_analysis_to_all() {
	for (int i = 0; i < total_patients_number; i++) {
		perform_percentage_analysis(patient_records[i].patient_id,
			patient_records[i].dna_sequence, dna_size, dna_elements, 4);
	}
}

int get_result_index_by_id(string id) {
	for (int i = 0; i < total_patients_number; i++) {
		if (dna_results[i].patient_id == id) {
			return i;
		}
	}
	return -1;
}

void find_percentage_similarity() {
	cout << "\n----Find patients with the best similarity to each other by percentage ratio----" << endl;
	display_patients_list();
	//int current_patient_index = get_result_index_by_id(id);
	DnaDifferenceResultByPercentCompare results[total_patients_number * 3];
	int results_iterator = 0;
	int size = total_patients_number - 1;
	double total_difference = 0;
	int i = 0, j = 0, k = 0;
	int min = INT_MAX;
	int best_index = 0;

	for (i = 0; i <= total_patients_number; i++)
	{
		for (j = i + 1; j < total_patients_number; j++)
		{
			for (k = 0; k < 4; k++)
			{
				total_difference += abs(dna_results[i].dna_analysis_result[k] - dna_results[j].dna_analysis_result[k]);
			}
			results[results_iterator] = { dna_results[i].patient_id, dna_results[j].patient_id, total_difference };

			//cout << dna_results[i].patient_id << " and " << dna_results[j].patient_id << " : " << total_difference << endl;
			results_iterator++;
			total_difference = 0;
		}
	}

	sort(results, results + (total_patients_number * 3), DnaDifferenceResultByPercent_sort);

	cout << "Percentage ratio of patients DNA:" << endl;

	for (int i = 0; i < total_patients_number * 3; i++)
	{
		if (results[i].percentage_difference_result < min)
		{
			min = (int)results[i].percentage_difference_result;
			best_index = i;
		}
		cout << results[i].patient_a_id << " and " << results[i].patient_b_id <<
			". Difference value: " << results[i].percentage_difference_result << endl;
	}

	for (int i = 0; i < total_patients_number * 3; i++)
	{
		if ((int)results[i].percentage_difference_result == min)
		{
			cout << "Patients with the best ratio: " << results[i].patient_a_id << " and "
				<< results[i].patient_b_id << ". Difference value: " << results[i].percentage_difference_result << endl;
		}
	}
}

void display_patients_DNA_percentages()
{
	cout << "---------------Patients percentage analysis list-----------------" << endl;
	for (int i = 0; i < total_patients_number; i++)
	{
		cout << "id: " << patient_records[i].patient_id << "\t| DNA elems %: ";
		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 0:	cout << "(A)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			case 1: cout << "(G)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			case 2: cout << "(C)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			case 3: cout << "(T)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

void display_patients_list()
{
	cout << "---------------Patients list-----------------" << endl;
	for (int i = 0; i < total_patients_number; i++)
	{
		cout << "id: " << patient_records[i].patient_id <<
			" | name: " << patient_records[i].patient_name <<
			" | age: " << patient_records[i].age <<
			" | blood: " << patient_records[i].blood_group
			<< " | DNA elems %: ";
		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 0:	cout << "(A)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			case 1: cout << "(G)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			case 2: cout << "(C)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			case 3: cout << "(T)" << dna_results[i].dna_analysis_result[j] << " ";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

int levenstein(string value1, string value2) {
	int height = value1.length() + 1;
	int length = value2.length() + 1;
	int** matrix = new int*[height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new int[length];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			if (i == 0 && j == 0) {
				matrix[i][j] = 0;
			}
			else if (i == 0) {
				matrix[i][j] = matrix[i][j - 1] + 1;
			}
			else if (j == 0) {
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			else {
				if (value1[i - 1] == value2[j - 1]) {
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else {
					matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
				}
			}
		}
	}
	return matrix[height - 1][length - 1];
}

char* get_dna_sequence_by_patient_id(string patient_id) {
	for (int i = 0; i < total_patients_number; i++) {
		if (patient_records[i].patient_id == patient_id) {
			return patient_records[i].dna_sequence;
		}
	}
}

int find_composition_similarity(string first_patiend_id, string second_patient_id) {
	char* first_dna_sequence =	get_dna_sequence_by_patient_id(first_patiend_id);
	char* second_dna_sequence = get_dna_sequence_by_patient_id(second_patient_id);

	int start_position = 0, offset_value = 10;
	int total_composition_difference = 0;

	while (start_position != 10000) {
		int finish_value = start_position + offset_value;

		string first_dna_chunk, second_dna_chunk;

		for (int i = start_position; i < finish_value; i++) {
			first_dna_chunk += first_dna_sequence[i];
			second_dna_chunk += second_dna_sequence[i];
		}

		int difference = levenstein(
			first_dna_chunk, second_dna_chunk);
		total_composition_difference += difference;
		start_position += offset_value;
	}
	return total_composition_difference;
}

void patients_with_max_compatibilty_by_DNA_elems()
{
	cout << "-----------Find patients with maximum compatibilty by comparing DNA elements-------------" << endl;
	cout << "The analysis is in progress... ";

	int difference = 0;
	int min = INT_MAX;
	DnaDifferenceResultByElemsCompare dif_results[total_patients_number * 3];
	int res_iterator = 0;

	for (int i = 0; i <= total_patients_number; i++)
	{
		for (int j = i + 1; j < total_patients_number; j++)
		{
			difference = find_composition_similarity(patient_records[i].patient_id, patient_records[j].patient_id);
			
			if (difference < min)
			{
				min = difference;
			}

			dif_results[res_iterator] = { dna_elems_compare_results[i].patient_id,
				dna_elems_compare_results[j].patient_id, difference };

			cout << dna_elems_compare_results[i].patient_id << " and " << dna_elems_compare_results[j].patient_id << "\tDifference value: " <<
			difference << endl;

			res_iterator++;
		}
	}

	sort(dif_results, dif_results + (total_patients_number * 3), DnaDifferenceResultByDnaElems_sort);
	cout << "The analysis is completed." << endl;
	cout << "Patients compatibility by DNA elements are: " << endl;
	for (int i = 0; i < total_patients_number * 3; i++)
	{
		cout << i + 1 << ") " << dif_results[i].patient_a_id << " and " << dif_results[i].patient_b_id <<
			"\tDifference value: " << dif_results[i].dna_elements_difference_result << endl;

	}

	for (int i = 0; i < total_patients_number * 3; i++)
	{
		if (dif_results[i].dna_elements_difference_result == min)
		{
			cout << "Patients with the best ratio: " << dif_results[i].patient_a_id << " and "
				<< dif_results[i].patient_b_id << ". Difference value: "
				<< dif_results[i].dna_elements_difference_result << endl;
		}
	}
}

bool DnaDifferenceResultByPercent_sort(DnaDifferenceResultByPercentCompare a, DnaDifferenceResultByPercentCompare b)
{
	return a.percentage_difference_result < b.percentage_difference_result;
}

bool DnaDifferenceResultByDnaElems_sort(DnaDifferenceResultByElemsCompare a, DnaDifferenceResultByElemsCompare b)
{
	return a.dna_elements_difference_result < b.dna_elements_difference_result;
}

void artificial_dna_tests(double Adenin_percent, double Guanin_percent,
	double Citosin_percent, double Timin_percent)
{
	char dna_sequence[dna_size];
	int random_num = 0;

	for (int i = 0; i < dna_size; i++)
	{
		random_num = generate_random_number(0, dna_size);
		double A = (dna_size / 100) * Adenin_percent;
		double G = (dna_size / 100) * Guanin_percent;
		double C = (dna_size / 100) * Citosin_percent;
		double T = (dna_size / 100) * Timin_percent;
		if (random_num >= 0 && random_num <= A)
		{
			dna_sequence[i] = 'A';
		}
		else if (random_num > A && random_num <= (G + A))
		{
			dna_sequence[i] = 'G';
		}
		else if (random_num > (G + A) &&
			random_num <= (G + A + C))
		{
			dna_sequence[i] = 'C';
		}
		else if (random_num > (G + A + C) &&
			random_num <= (G + A + C + T))
		{
			dna_sequence[i] = 'T';
		}
	}
	cout << "Arttificial DNA sequence generated" << endl;
	cout << "Do you want to display DNA each elements amount? (0 - no, yes - 1)" << endl;
	int doctors_choice;
	cin >> doctors_choice;

	int A_counter = 0, G_counter = 0, C_counter = 0, T_counter = 0;

	if (doctors_choice == 1)
	{
		for (int i = 0; i < dna_size; i++)
		{
			if (dna_sequence[i] == 'A')
			{
				A_counter++;
			}
			else if (dna_sequence[i] == 'G')
			{
				G_counter++;
			}
			else if (dna_sequence[i] == 'C')
			{
				C_counter++;
			}
			else
			{
				T_counter++;
			}
		}
	}

	cout << A_counter << "(A) " << G_counter 
		<< "(G) " << C_counter << "(C) " << T_counter << "(T)" << endl;
}

void artificial_dna_tests_modul()
{
	cout << "----------Artificial DNA tests Modul----------" << endl;
	cout << "Choose command code below" << endl;
	cout << "1 - Generate DNA sequence artificially" << endl;
	int code;
	cin >> code;

	switch (code)
	{
	case 1:
		artificial_dna_tests_menu();
		break;
	default:
		return;
	}

}

void artificial_dna_tests_menu()
{
	cout << "Enter the percentage of Adenin: ";
	double adenin;
	cin >> adenin;
	cout << "Enter the percentage of Guanin:: ";
	double guanin;
	cin >> guanin;
	cout << "Enter the percentage of Citosin: ";
	double citosin;
	cin >> citosin;
	cout << "Enter the percentage of Timin: ";
	double timin;
	cin >> timin;

	artificial_dna_tests(adenin, guanin, citosin, timin);
}

void initialize_system() {
	cout << "---------DNA analysis system-----------" << endl << endl;
	cout << "----------------MAIN MENU--------------" << endl;
	cout << "Choose the command code below" << endl;
	cout << "0 - Display patients list with informatioin" << endl;
	cout << "1 - Performing percentage analysis of patients DNA" << endl;
	cout << "2 - Find patients with the best similarity to each other by percentage ratio" << endl;
	cout << "3 - Find patients with max compatibilty by DNA" << endl;
	cout << "4 - Artificial DNA test (generate DNA sequence artificialy)" << endl;

	int command;
	cin >> command;
	switch (command)
	{
	case 0:
		perform_percentage_analysis_to_all();
		display_patients_list();
		break;
	case 1:
		perform_percentage_analysis_to_all();
		display_patients_DNA_percentages();
		break;
	case 2:
		perform_percentage_analysis_to_all();
		find_percentage_similarity();
		break;
	case 3:
		patients_with_max_compatibilty_by_DNA_elems();
		break;
	case 4:
		artificial_dna_tests_modul();
		break;
	default:
		return;
	}



}

void autentification(string name, string password)
{
	bool match = true;
	for (int i = 0; i < doctors_number; i++)
	{
		if (name == doctor_records[i].doctor_name && password == doctor_records[i].doctor_password)
		{
			match = true;
			break;
		}
		else
		{
			match = false;
		}
	}

	if (match)
	{
		cout << "Welcome to system, Doc" << endl << endl;
		while (true)
		{
			initialize_system();
		}

	}
	else
	{
		cout << "Wrong name or password, please try again" << endl;
		autentification_menu();
	}

}

void autentification_menu()
{
	cout << "---------Doctors autentification-----------" << endl;
	cout << "Enter name: ";
	string name;
	cin >> name;
	cout << "Enter password: ";
	string password;
	cin >> password;

	autentification(name, password);

}

#pragma endregion
