#pragma once
#include <string>
using namespace std;

class Dish
{
public:
	Dish(string);
	string getName();
protected:
	int cookingTime;
private:	
	string name;
};

