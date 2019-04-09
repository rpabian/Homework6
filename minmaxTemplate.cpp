#include "pch.h"
#include <iostream>

template <typename T>
T maximum(T const& first, T const& second)
{
	return(first > second ? first : second);
}

template <typename T>
T minimum(T const& first, T const& second)
{
	return(first < second ? first : second);
}

int main()
{
	int firstInt = 15;
	int secondInt = 31;
	long firstLong = 45;
	long secondLong = 67;
	float firstFloat = 54.6;
	float secondFloat = 67.8;
	double firstDouble = 12.567;
	double secondDouble = 13.149;

	int maxInt = maximum(firstInt, secondInt);
	float maxFloat = maximum(firstFloat, secondFloat);
	long minLong = minimum(firstLong, secondLong);
	double minDouble = minimum(firstDouble, secondDouble);

	std::cout << "Maximum int between " << firstInt << " and "
		<< secondInt << " is: " << maxInt << std::endl;
	std::cout << "Maximum float between " << firstFloat << " and "
		<< secondFloat << " is: " << maxFloat << std::endl;
	std::cout << "Minimum long between " << firstLong << " and "
		<< secondLong << " is: " << minLong << std::endl;
	std::cout << "Minimum double between " << firstDouble << " and "
		<< secondDouble << " is: " << minDouble << std::endl;

	return 0;
}