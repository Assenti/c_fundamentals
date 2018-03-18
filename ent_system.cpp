#include<iostream>
#include<string>
#include<time.h>

using namespace std;

#pragma region Const variables
int const quests_numb = 10;
int const test_numb = 3;
int const answers_numb = 4;
#pragma endregion 

#pragma region Structures
struct Question {
	string question_body;
	string answer_options[answers_numb];
	int correct_answer_index;
};

struct Test {
	string test_name;
	Question questions[quests_numb];
};

#pragma endregion

#pragma region Data_bases
Test tests[test_numb] = {
	{ "Common",
		{
			{"Who is Euqlid?",
				{
					{ "0: Greek" },
					{ "1: Chinese" },
					{ "2: Japanese" },
					{ "3: Naiman" }
				},
				0
			},
			{"Who is Chingiskhan?", 
				{
					{"0: Chinese"},
					{"1: American"},
					{"2: Kazakh"},
					{"3: Mongol"}
				},
				3
			},
			{ "Where is Cheops Pyramids located?",
				{
					{ "0: India" },
					{ "1: Egypt" },
					{ "2: England" },
					{ "3: Iran" }
				},
				1
			},		
			{"What is the capital of France?",
				{
					{"0: London"},
					{"1: Paris"},
					{"2: Munich"},
					{"3: Marsel"}
				},
				1
			},
			{"Who is the first USA president?",
				{
					{"0: Washington"},
					{"1: Trump"},
					{"2: Bush"},
					{"3: Lincoln"}
				},
				0
			},
			{"Which color is Kazakhstans flag?",
				{
					{"0: Red"},
					{"1: Yellow"},
					{"2: Blue"},
					{"3: Green"}
				},
				2
			},
			{"What is the biggest country in the world?",
				{
					{"0: Canada"},
					{"1: Australia"},
					{"2: China"},
					{"3: Russia"}
				},
				3
			},
			{"What is biggest city in Kazakhstan?",
				{
					{"0: Astana"},
					{"1: Almaty"},
					{"2: Shymkent"},
					{"3: Aktobe"}
				},
				1
			},
			{"What is the currency of China?",
				{
					{"0: Dollar"},
					{"1: Ruble"},
					{"2: Yena"},
					{"3: Yuan"}
				},
				3
			},
			{"Who is the greatest boxer ever in the history?",
				{
					{"0: Ali"},
					{"1: Tyson"},
					{"2: GGG"},
					{"3: Roy Jones"}
				},
				0
			}
		}
	},
	{"History",
		{
			{ "When Kazakhstan got an independence?",
				{
					{ "0: 1990" },
					{ "1: 1991" },
					{ "2: 1993" },
					{ "3: 2001" }
				},
				1
			},
			{ "When Astana was founded?",
				{
					{ "0: 1997" },
					{ "1: 1993" },
					{ "2: 1998" },
					{ "3: 1991" }
				},
				0
			},
			{"When did the tenge come about?",
				{
					{"0: 1991"},
					{"1: 1992"},
					{"2: 2001"},
					{"3: 1993"}
				},
				3
			},
			{"In what century was formed the Kazakh Khanate?",
				{
					{"0: XV"},
					{"1: XVI"},
					{"2: XIV"},
					{"3: XIII"}
				},
				0
			},
			{"How many dzhuzes are Kazakh people are divided?",
				{
					{"0: Two"},
					{"1: Three"},
					{"2: What is that - dhuz?"},
					{"3: One"}
				},
				1
			},
			{"Who was Abylai khan?",
				{
					{"0: Poet"},
					{"1: Judge"},
					{"2: Khan of three dhuzes"},
					{"3: Batyr"}
				},
				2
			},
			{"Who was Kabanbay?",
				{
					{"0: Boxer"},
					{"1: Poet"},
					{"2: Batyr"},
					{"3: Khan"}
				},
				2
			},
			{"Who is the first president of Kazakhstan?",
				{
					{"0: Konayev"},
					{"1: Nazarbayev"},
					{"2: Kolbin"},
					{"3: Baibek"}
				},
				1
			},
			{"When Kazakhstans army was formed?",
				{
					{"0: 1991"},
					{"1: 1990"},
					{"2: 1993"},
					{"3: 1992"}
				},
				3
			},
			{"Who is Abay?",
				{
					{"0: Poet"},
					{"1: Batyr"},
					{"2: Khan"},
					{"3: Traveler"}
				},
			}
		}
		
	},
{}
};
#pragma endregion

#pragma region Functions prototypes
void questions_shuffle(Question* question);

void print_question(Question* question, int current_index);

bool test_check(int test_number, int question_number, int index);
#pragma endregion

/*****************************Main**********************************/
int main() {
	srand(time(0));
	int choice, answer, counter = 0;
	cout << "Choose the test:\n0 - Common\n1 - History" << endl;
	cin >> choice;

	if (choice == 0)
	{
		system("cls");
		questions_shuffle(tests[choice].questions);

		for (int i = 0; i < quests_numb; i++)
		{
			cout << "Question #:" << i + 1 << endl;
		
			print_question(tests[choice].questions, i);
							
			cin >> answer;
			test_check(choice, i, answer);
			if (test_check(choice, i, answer) == true)
			{
				counter++;
			}
			//cout << tests[choice].questions[i].correct_answer_index << endl;
			
			system("pause");
			system("cls");
		}
	}
	else if (choice == 1)
	{
		system("cls");
		questions_shuffle(tests[choice].questions);

		for (int i = 0; i < quests_numb; i++)
		{
			cout << "Question #:" << i + 1 << endl;
			
			print_question(tests[choice].questions, i);

			cin >> answer;
			test_check(choice, i, answer);
			if (test_check(choice, i, answer) == true)
			{
				counter++;
			}
			//cout << tests[choice].questions[i].correct_answer_index << endl;

			system("pause");
			system("cls");
		}
	}
	cout << "Tests Over" << endl;
	cout << "Right answers: " << counter << " from " << quests_numb << endl;
	system("pause");
	return 0;
}

void questions_shuffle(Question* question)
{
	int rand_index = rand() % 10;
	swap(question[0], question[rand_index]);
}

void print_question(Question* question, int current_index)
{
	cout << question[current_index].question_body << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << question[current_index].answer_options[i] << endl;
	}
}

bool test_check(int test_number, int question_number, int index)
{
	bool match = true;
	if (tests[test_number].questions[question_number].correct_answer_index == index)
	{
		match = true;
		//cout << "Correct" << endl;
	}
	else
	{
		match = false;
		//cout << "Wrong" << endl;
	}
	return match;
}