#pragma once
#include <string>
using namespace std;

class Dish
{
public:
	Dish(string, double);
	virtual string getName()=0;
	double getPrice();
	int getCookingTime();

protected:
	int cookingTime;
	string name;
	double price;

};

