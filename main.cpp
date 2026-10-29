#include <iostream>
#include <fstream>
#include <string>

void addCarSpecs()//Writing to file
{
	std::cout << "How many cars do you want to add?: ";
	int carNumber{};
	std::cin >> carNumber;

	std::cin.ignore();

	for (int i{ 1 }; i <= carNumber; i++)
	{
		// carName
		std::cout << "Enter a car: ";
		std::string carName{};
		std::getline(std::cin, carName);

		//topSpeed
		std::cout << "Enter top speed: ";
		int topSpeed{};
		std::cin >> topSpeed;

		// horsePower
		std::cout << "Enter horsepower: ";
		int horsepower{};
		std::cin >> horsepower;

		//engine
		std::cin.ignore();
		std::cout << "Enter car engine: ";
		std::string engine{};
		std::getline(std::cin, engine);

		//file handling
		std::ofstream file("myGarage.txt", std::ios::app);
		file << "---------------\n";
		file <<"Car Name: "<< carName << '\n';
		file <<"Top Speed: "<< topSpeed << '\n';
		file <<"Horse Power: "<< horsepower << '\n';
		file <<"Engine: "<< engine << '\n';

		file.close();
		std::cout << "car added successfully!\n";
	}
}

void displayCar()//Reading to file
{
	std::cout << "----------------------\n";
	std::cout << "   AVALIABLE CARS\n";
	std::cout << "-----------------------\n";

	std::cin.ignore();

	std::ifstream readCars("myGarage.txt");
	std::string text;
	while (std::getline(readCars, text))
	{
		std::cout << text << '\n';
	}
	readCars.close();
	std::cout << "------------------------\n";
}

int main()
{
	std::cout << "-----------------------\n";
	std::cout << "    MY CAR GARAGE\n";
	std::cout << "------------------------\n";

	std::cout << "1. add car\n";
	std::cout << "2. display cars\n";

	std::cout << "Choose an option: ";
	int input{};
	std::cin >> input;

	if (input == 1)
	{
		addCarSpecs();
	}
	else if (input == 2)
	{
		displayCar();
	}
	else
	{
		std::cout << "Not an option\n";
	}

	return 0;
}