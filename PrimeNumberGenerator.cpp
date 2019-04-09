#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void printPrime(int number)
{
	bool isPrime;
	if (number == 2 || number == 3)
		isPrime = true;
	else if (number % 2 == 0 || number % 3 == 0)
		isPrime = false;
	else
		isPrime = true;
	for (int i = 5; i * i <= number; i = i + 6)
		if (number % i == 0 || number % (i + 2) == 0)
			isPrime = false;

	if (isPrime)
		std::cout << number << std::endl;
}

int main()
{
	int vectorSize;
	std::cout << "Enter an integer greater than 1: ";
	std::cin >> vectorSize;
	std::cout << std::endl;
	std::vector<int> intVector;

	for (int i = 2; i <= vectorSize; i++)
	{
		intVector.push_back(i);
	}
	
	std::vector<int>::iterator beginIt;
	std::vector<int>::iterator endIt;
	beginIt = intVector.begin();
	endIt = intVector.end();

	std::for_each(beginIt, endIt, printPrime);

}
