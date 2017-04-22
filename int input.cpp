#include<iostream>
#include<string>
using namespace std;

int getIntegerInput();

int main()
{
	cout << "enter in an integer: ";
	int number = getIntegerInput();
	cout << "number enter: " << number << endl;
	cout << "press enter to exit ...";
	cin.get();
	return 0;
}

int getIntegerInput()
{
	int number;
	string temp;
	bool hasAlphaChars = false;
	getline(cin, temp);
	for (int count = 0; count < (temp.length()); count ++)
		if (isdigit(temp[count]) == 0)
		{
			hasAlphaChars = true;
		}
	while (hasAlphaChars || temp == "\0")
	{
		hasAlphaChars = false;
		cout << "only numbers are valid, try again: " ;
		getline(cin, temp);
		for (int count = 0; count < (temp.length()); count++)
			if (isdigit(temp[count]) == 0)
			{
				hasAlphaChars = true;
			}
	}
	number = stoi(temp);
	return number;
}