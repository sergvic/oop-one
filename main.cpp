#include "Pizza.h"
#include "Soup.h"
#include "Pasta.h"
#include "MrCat.h"
#include <iostream>

//denisov.univ@gmail.com
//sergvic
//sireukr

using namespace std;

void main()
{
	MrCat cafe;
	cafe.showMenu();
	
	Dish dishes[] = { 
		Pizza("QuattroFormagio"),
		Pizza("Margarita"),
		Pizza("Havayian"),
		Soup("Miso"),
		Soup("CreamCheese"),
		Pasta("Bolognees")
	};

	for (auto dish : dishes) 
		cout << "Dish: " << dish.getName() << endl;
}