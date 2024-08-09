#include <iostream>
#include <cstdlib>
#include <ctime>

int generateNumber()
{
	std::srand(std::time(nullptr));
	return std::rand();
}

int main()
{
	int difficulty;
	int number;
	int attemps;
	int user_number;
	int max_number;
	bool running = true;
	bool win;
	char response;

	while(running)
	{
		win = false;
		
		std::cout << "Choose your difficulty :\n\t1) Easy (0 to 50, 5 attemps)\n\t2) Medium (0 to 100, 7 attemps)\n\t3) Hard (0 to 500, 10 attemps)\n=> ";
		std::cin >> difficulty;

		switch (difficulty)
		{
			case 1:
				max_number = 50;
				number = generateNumber() % max_number;
				attemps = 5;
				break;

			case 2:
				max_number = 100;
				number = generateNumber() % max_number;
				attemps = 7;
				break;

			case 3:
				max_number = 500;
				number = generateNumber() % max_number;
				attemps = 10;
				break;
			
			default:
				break;
		}

		std::cout << "Choose a number between 0 and " << max_number << std::endl;

		for (int i = 0; i < attemps; i++)
		{
			std::cout << "=> ";
			std::cin >> user_number;

			if (user_number < number)
				std::cout << "MORE" << std::endl;

			else if (user_number > number)
				std::cout << "LESS" << std::endl;

			else if (user_number == number)
			{
				std::cout << "WIN" << std::endl;
				i = attemps;
				win = true;
			}

			std::cout << std::endl;
		}

		if (!win)
			std::cout << "LOSS" << std::endl;
		

		while (true)
		{
			std::cout << "New game ? (y or n)\n=> ";
			std::cin >> response;

			if (response == 'y')
				break;

			else if (response == 'n')
			{
				running = false;
				break;
			}

			else
			{
				std::cout << "Response unvalible" << std::endl;
				response = ' ';
			}
		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

	}

	return 0;
}