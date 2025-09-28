#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>
using namespace std;

int main()
{
	float firstnum;
	float secondnum;
	float savedvalue = NULL;
	string operation; 
	int convertedoperation = 5;
	while (true) 
	{
		if (savedvalue != NULL)
		{
			string stringdata;
			std::cout << "Continue operation: " << endl;
			std::cout << savedvalue << endl;
			std::cin >> operation >> stringdata;
			try {	secondnum = std::stof(stringdata);}
			catch (exception e) { std::cout << "Unkown number, restart" << endl; this_thread::sleep_for(chrono::seconds(2)); secondnum = NULL; system("cls"); }
			std::cout << endl;
		}
		else 
		{
			string stringdata;
			string stringdata1;
			std::cout << "Calculator ready!" << endl;
			std::cin >> stringdata >> operation >> stringdata1;
			try { firstnum = std::stof(stringdata); secondnum = std::stof(stringdata1); }
			catch (exception e) { std::cout << "Unkown number, restart" << endl; this_thread::sleep_for(chrono::seconds(2)); firstnum = NULL; secondnum = NULL; system("cls"); }
		}
		if (operation == "+") { convertedoperation = 1; }
		else if (operation == "-") { convertedoperation = 2; }
		else if (operation == "*") { convertedoperation = 3; }
		else if (operation == "/") { convertedoperation = 4; }
		else { std::cout << "Unkown operator, restart" << endl; this_thread::sleep_for(chrono::seconds(2));  system("cls"); }
		if (savedvalue != NULL) { firstnum = savedvalue; }
		switch (convertedoperation) 
		{
		case 1:
			savedvalue = firstnum + secondnum;
			std::cout << "Result: " << savedvalue << endl;
			break;
		case 2:
			savedvalue = firstnum - secondnum;
			std::cout << "Result: " << savedvalue << endl;
			break;
		case 3:
			if (firstnum == 0 || secondnum == 0) {
				std::cout << "U not can make this operation, restart";
				this_thread::sleep_for(chrono::seconds(2));
			}
			else {
				savedvalue = firstnum * secondnum;
				std::cout << "Result: " << savedvalue << endl;
			}
			break;
		case 4:
			if (firstnum == 0 || secondnum == 0) {
				std::cout << "U not can make this operation, restart";
				this_thread::sleep_for(chrono::seconds(2));
			}
			else {
				savedvalue = firstnum / secondnum;
				std::cout << "Result: " << savedvalue << endl;
			}
			break;
		case 5:
			break;
		}
		convertedoperation = 5;
		system("cls");
	}	
}
