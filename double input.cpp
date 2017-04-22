#include<iostream>
#include<string>
using namespace std;

double getDoubleInput();
bool hasAlphaCharacters(string);
bool hasExtraDecimals(string);

int main()
{
	cout << "calling get double value ....\n";
	double x = getDoubleInput();
	cout << "number returned is: " << x << endl;
	cout << "\npress enter to exit program ...";
	cin.get();
	return 0;
}

double getDoubleInput()
{
	string temp = "\0";
	double validatedDouble;
	cout << "enter a double: ";
	getline(cin, temp);
	bool hasAlphaChars = hasAlphaCharacters(temp);
	bool hasExtraDecimalPoints = hasExtraDecimals(temp);
	while (hasAlphaChars == true || hasExtraDecimalPoints == true || temp == "\0" || temp == ".")
	{
		if (hasAlphaChars == true)
		{
			cout << "only numbers are valid, try again: ";
			getline(cin, temp);
			hasAlphaChars = hasAlphaCharacters(temp);
			hasExtraDecimalPoints = hasExtraDecimals(temp);
		}
		else if (hasExtraDecimalPoints == true)
		{
			cout << "only one decimal point is valid, try again: ";
			getline(cin, temp);
			hasAlphaChars = hasAlphaCharacters(temp);
			hasExtraDecimalPoints = hasExtraDecimals(temp);
		}
		else
		{
			cout << "invalid input, try again: ";
			getline(cin, temp);
			hasAlphaChars = hasAlphaCharacters(temp);
			hasExtraDecimalPoints = hasExtraDecimals(temp);
		}
	}

	validatedDouble = stod(temp);
	return validatedDouble;
}

bool hasAlphaCharacters(string validate)
{
	bool hasAlphaChars = false;
	int length = validate.length();
	for (int count = 0; count < length; count++)
	{
		if (validate[count] == 46)
		{
			continue;
		}
		if (isdigit(validate[count]) == 0)
			hasAlphaChars = true;
	}
	return hasAlphaChars;
}


bool hasExtraDecimals(string validate)
{
	bool hasExtraPoints = false;
	int length = validate.length();
	int decimalCount = 0;
	for (int count = 0; count < length; count++)
	{
		if (validate[count] == 46)
			decimalCount++;
	}
	if (decimalCount > 1)
		hasExtraPoints = true;

	return hasExtraPoints;
}
