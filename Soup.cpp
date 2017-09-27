#include "Soup.h"

#include <iostream>
using namespace std;

Soup::Soup(string name) : Dish(name)
{
}

string Soup::getName()
{
	return "Soup \"" + name + "\"";
}
