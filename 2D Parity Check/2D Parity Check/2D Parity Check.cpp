#include <iostream>
#include <vector>

void ReadMessage(std::string& message)
{
	std::cout << "M(x): ";

	std::cin >> message;
}

bool VerifyMessage(std::string& message)
{
	if (message.length() % 7 != 0)
	{
		return false;
	}

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

void CreateMessage(std::string& message)
{
	const int n = message.length() / 7 + 1, m = 8;
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	int position = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			matrix[i][j] = message[position] - '0';
			position++;
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		int count = 0;
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 1)
			{
				count++;
			}
			if (j == m - 1)
			{
				matrix[i][m - 1] = count % 2;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if (matrix[j][i] == 1)
			{
				count++;
			}
			if (j == n - 2)
			{
				matrix[n - 1][i] = count % 2;
			}
		}
	}

	std::cout << std::endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == m - 1)
			{
				std::cout << " " << matrix[i][j];
			}
			else
			{
				std::cout << matrix[i][j];
			}
		}
		std::cout << std::endl;
	}
	std::cout << "-------" << std::endl;;

	for (int j = 0; j < m - 1; j++)
	{
		std::cout << matrix[n - 1][j];
	}
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "M'(x): ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << matrix[i][j];
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	std::string message;

	ReadMessage(message);

	if (VerifyMessage(message))
	{
		CreateMessage(message);
	}
	else
	{
		std::cout << std::endl;
		std::cout << "Invalid input!";
		std::cout << std::endl;
	}
	return 0;
}