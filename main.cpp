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
	
	Dish *dishes[] = { 
		new Pizza("QuattroFormagio"),
		new Pizza("Margarita"),
		new Pizza("Havayian"),
		new Soup("Miso"),
		new Soup("CreamCheese"),
		new Pasta("Bolognees")
	};

	for (auto dish : dishes) 
		cout << dish->getName() << endl;

	for (auto dish : dishes) {
		delete dish;
	}	
}