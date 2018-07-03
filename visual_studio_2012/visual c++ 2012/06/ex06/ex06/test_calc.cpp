#include <iostream>
#include <cctype>

using namespace std;

const int MAX = 80;
<<<<<<< HEAD
char buffer[MAX];

int main
{



	return 0;
};
=======

void eatspaces(char *str);
double expr(char *str);
double term(char* str, int& index);
double number(char *str, int &index);

int main_calc()
{
	char buffer[MAX] = {0};

	cout << "Welcome to your friendly calculator. " << endl
		<< "Enter an expression, or an empty line to quit." << endl;

	for (;;)
	{
		cin.getline(buffer, sizeof buffer);
		eatspaces(buffer);
		cout << buffer << endl;
		if (!buffer[0])
		{
			return 0;
		}

		try
		{
			cout << "\t= " << expr(buffer) << endl << endl;
		}
		catch (const char *pEx)
		{
			cerr << pEx << endl;
			cerr << "Ending program." << endl;
			return 1;
		}
	}

	return 0;
}

void eatspaces(char *str)
{
	int i = 0;
	int j = 0;

	while ((*(str + i ) = *(str + j++)) != '\0')
	{
		if (*(str + i ) != ' ')
			i++;
	}
	return;
}

double expr(char *str)
{
	double value = 0.0;
	int index = 0;
	value = term(str, index);

	for (;;)
	{
		switch (*(str + index++))
		{
		case '\0':
			return value;

		case '+':
			value += term(str, index);
			break;

		case '-':
			value -= term(str, index);
			break;

		default:
			char message[38] = "Expression evaluation error. Found: ";
			strncat_s(message, str + index - 1, 1);
			throw message;
			break;
		}
	}
}

double term(char* str, int& index)
{
	double value = 0.0;
	value = number(str, index);

	while (true)
	{
		if (*(str + index) == '*')
			value *= number(str, ++index);
		else if (*(str + index) == '/')
			value /= number(str, ++index);
		else
			break;
	}
	return value;
}

double number(char *str, int &index)
{
	double value = 0;
	
	if (!isdigit(*(str + index)))
	{
		char message[31] = "Invalid character in number: ";
		strncat_s(message, str + index, 1);
		throw message;
	}

	while (isdigit(*(str + index)))
	{
		value = 10 * value + (*(str + index++) - '0');
	}

	if (*(str + index) != '.')
		return value;

	double factor = 1.0;
	while (isdigit(*(str + (++index))))
	{
		factor *= 0.1;
		value = value + (*(str + index) - '0') * factor;
	}
	return value;
}
>>>>>>> f17b4d70f7482e6c76550fa1c6429769587b14a5
