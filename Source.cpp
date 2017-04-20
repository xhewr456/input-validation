#include<iostream>
#include<string>
using namespace std;

int getMenuInput(int);

int main()
{
	cout << "this is a test of the getUserInput ...\n";

	cout << "number returned is " << getMenuInput(5);


	cin.get();
	return 0;
}

int getMenuInput(int size)
{
	int userInput = 0;
	string tempString;
	getline(cin, tempString);
	while ((tempString[0] < 49 || tempString[0] > (48 + size)) || tempString[1] != '\0') 
	{
		cout << "1 - " << size << " are the only valid choices, try again: ";
		getline(cin, tempString);
	}
	userInput = stoi(tempString);
	return userInput;
}