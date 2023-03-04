#include <iostream>
#include <vector>

void ReadMesage(std::string& message)
{
	std::cout << "M(x): ";

	std::cin >> message;
}

bool VerifyMessage(std::string& message)
{
	int count = 0;

	for (int i = 0; i < message.length(); i++)
	{
		if ((message[i] == '1') || (message[i] == '0'))
		{
			count++;
		}
	}

	if (count != message.length())
	{
		return false;
	}
	return true;
}

void ReadPolynom(std::string& polynom)
{
	std::cout << std::endl;
	std::cout << "C(x): ";

	std::cin >> polynom;
}

bool VerifyPolynom(std::string& polynom)
{
	if (VerifyMessage(polynom) == false)
	{
		return false;
	}

	if (polynom[0] != '1' || polynom[polynom.length() - 1] != '1')
	{
		return false;
	}
	return true;
}

char XOR(char& x, char& y)
{
	if (x == y)
	{
		return '0';
	}
	else 
	{
		return '1';
	}
}

std::string ExtendedMessage(std::string& message, std::string& polynom)
{
	for (int i = 0; i < polynom.length() - 1; i++)
	{
		message += '0';
	}

	std::cout << std::endl;
	std::cout << "T(x): ";
	std::cout << message;
	std::cout << std::endl;
	return message;
}

std::string RemainderMessage(std::string& extendedMessage, std::string& polynom) {

	std::string remainderMessage = extendedMessage;

	while (remainderMessage.length() >= polynom.length())
	{
		std::string temp1 = remainderMessage.substr(0, polynom.length());
		std::string temp2;

		for (int i = 0; i < temp1.length(); i++)
		{
			temp2 += XOR(temp1[i], polynom[i]);
		}

		remainderMessage.replace(0, polynom.length(), temp2);

		while (remainderMessage[0] == '0')
		{
			remainderMessage.erase(0, 1);
		}
	}

	std::cout << std::endl;
	std::cout << "R(x): ";
	std::cout << remainderMessage;
	std::cout << std::endl;
	return remainderMessage;
}

void CreateMessage(std::string& extendedMessage, std::string& remainderMessage)
{
	std::string messagePrime = extendedMessage;
	std::string temp1 = messagePrime.substr(messagePrime.length() - remainderMessage.length(), messagePrime.length());
	std::string temp2;

	for (int i = 0; i < temp1.length(); i++)
	{
		temp2 += XOR(temp1[i], remainderMessage[i]);
	}

	messagePrime.replace(messagePrime.length() - remainderMessage.length(), messagePrime.length(), temp2);

	std::cout << std::endl;
	std::cout << "M'(x): ";
	std::cout << messagePrime;
	std::cout << std::endl;
}

int main() {
	std::string message;
	std::string polynom;

	ReadMesage(message);
	ReadPolynom(polynom);

	if (VerifyMessage(message) && VerifyPolynom(polynom))
	{
		std::string extendedMessage = ExtendedMessage(message, polynom);
		std::string remainderMessage = RemainderMessage(extendedMessage, polynom);
		CreateMessage(extendedMessage, remainderMessage);
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Invalid input!";
		std::cout << std::endl;
	}
	return 0;
}