#include "Soup.h"

#include <iostream>
using namespace std;

Soup::Soup(string name, double price) : Dish(name, price)
{
	cookingTime = 20;
}

string Soup::getName()
{
	return "Soup \"" + name + "\"";
}
