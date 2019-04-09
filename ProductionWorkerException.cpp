#include "pch.h"
#include <iostream>
#include <string>

class Employee
{
private:
	std::string m_name;
	int m_number;
	int m_hireDate;
public:
	class InvalidEmployee {};
	Employee(std::string name, int number, int hireDate)
	{
		m_name = name;
		if (number < 0 || number > 9999)
			throw InvalidEmployee();
		else
			m_number = number;
		m_hireDate = hireDate;
	}
	Employee() 
	{
		m_name = "";
		m_number = 0;
		m_hireDate = 0;
	}
	void setName(std::string name) { m_name = name; }
	void setNumber(int number)
	{
		if (number < 0 || number > 9999)
			throw InvalidEmployee();
		else
			m_number = number;
	}
	void setHireDate(int hireDate) { m_hireDate = hireDate; }
	std::string getName() { return m_name; }
	int getNumber() { return m_number; }
	int getHireDate() { return m_hireDate; }
};

class ProductionWorker : public Employee
{
private:
	int m_shift;
	double m_hourRate;
public:
	class InvalidShift {};
	class InvalidPayRate {};
	ProductionWorker(std::string name, int number, int hireDate,
		int shift, double hourRate) : Employee(name, number, hireDate)
	{
		if (shift != 1 && shift != 2)
			throw InvalidShift();
		else
			m_shift = shift;
		if (hourRate < 0)
			throw InvalidPayRate();
		else
			m_hourRate = hourRate;
	}
	ProductionWorker(int shift, double hourRate) : Employee()
	{
		if (shift != 1 && shift != 2)
			throw InvalidShift();
		else
			m_shift = shift;
		if (hourRate < 0)
			throw InvalidPayRate();
		else
			m_hourRate = hourRate;
	}
	ProductionWorker() : Employee()
	{
		m_shift = 1;
		m_hourRate = 0;
	}
	void setShift(int shift)
	{
		if (shift != 1 && shift != 2)
			throw InvalidShift();
		else
			m_shift = shift;
	}
	void setHourRate( double hourRate) 
	{
		if (hourRate < 0)
			throw InvalidPayRate();
		else
			m_hourRate = hourRate;
	}
	int getShift() { return m_shift; }
	double getHourRate() { return m_hourRate; }
};

void printProductionWorker( ProductionWorker& worker)
{
	int shift = worker.getShift();
	double hourRate = worker.getHourRate();
	std::string name = worker.getName();
	int number = worker.getNumber();
	int hireDate = worker.getHireDate();
	std::string shiftTime;

	if (shift == 1)
		shiftTime = "Day Shift";
	else
		shiftTime = "Night Shift";

	std::cout << "Production worker: " << name
		<< "\nEmployee number: " << number
		<< "\nHire Date: " << hireDate
		<< "\nShift: " << shiftTime
		<< "\nHourly Rate: " << hourRate << std::endl;
}

int main()
{
	try
	{
		ProductionWorker billy = ProductionWorker("Billy", 1038, 2019, 1, 8.50);
		printProductionWorker(billy);
		ProductionWorker brock = ProductionWorker("Brock", 10300, 2018, 2, 5.00);
		printProductionWorker(brock);
	}
	catch (Employee::InvalidEmployee)
	{
		std::cout << "\nEmployee Number not valid." << std::endl;
	}
	try
	{
		ProductionWorker bobby = ProductionWorker("Bobby", 7654, 2018, 3, 6.75);
		printProductionWorker(bobby);
	}
	catch (ProductionWorker::InvalidShift)
	{
		std::cout << "\nProduction Worker has an Invalid Shift." << std::endl;
	}
	try
	{
		ProductionWorker brant = ProductionWorker("Brant", 4236, 2019, 1, -7.65);
		printProductionWorker(brant);
	}
	catch(ProductionWorker::InvalidPayRate)
	{
		std::cout << "Production worker has an invalid Hourly Rate." << std::endl;
	}
	std::cout << "End of Program." << std::endl;
}