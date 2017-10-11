#pragma once
#include "Dish.h"

class Soup : public Dish
{
public:
	Soup(string name, double price);
	string getName() override;
};