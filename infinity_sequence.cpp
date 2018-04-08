//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	long long int first_element, favourite_number, difference;
//	cin >> first_element >> favourite_number >> difference;
//	bool infinity_sequence = false;
//
//	if ((difference == 0 && favourite_number != first_element) ||
//		(first_element < 0 && difference < 0 && favourite_number > first_element) ||
//		(first_element > 0 && difference > 0 && favourite_number < first_element)
//		)
//	{
//		cout << "NO" << endl;
//	}
//	else if ((abs(difference) == 1 && (favourite_number > 0 && difference > 0)) ||
//			 (abs(difference) == 1 && (favourite_number < 0 && difference < 0)))
//	{
//		cout << "YES" << endl;
//	}
//	else
//	{
//		if (difference < 0)
//		{
//			while (first_element >= favourite_number)
//			{
//				if (first_element == favourite_number)
//				{
//					infinity_sequence = true;
//					break;
//				}
//				else
//				{
//					infinity_sequence = false;
//				}
//				first_element += difference;
//			}
//		}
//		else
//		{
//			while (first_element <= favourite_number)
//			{
//				if (first_element == favourite_number)
//				{
//					infinity_sequence = true;
//					break;
//				}
//				else
//				{
//					infinity_sequence = false;
//				}
//				first_element += difference;
//			}
//		}
//		if (!(infinity_sequence))
//		{
//			cout << "NO" << endl;
//		}
//		else
//		{
//			cout << "YES" << endl;
//		}
//	}
//
//	return 0;
//}