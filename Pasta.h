#pragma once

#include "Dish.h"

class Pasta : public Dish
{
public:
	Pasta(string name);
	string getName() override;
};

