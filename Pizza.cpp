#include "Pizza.h"

#include <iostream>
using namespace std;

int test = 2;

Pizza::Pizza(string name, double price) : Dish(name, price)
{
	cookingTime = 15;
}

string Pizza::getName()
{
	return "Pizza \"" + name + "\"";
}
