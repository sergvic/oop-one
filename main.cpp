#include "Pizza.h"
#include "Soup.h"
#include "Pasta.h"
#include "Order.h"
#include "MrCat.h"
#include <iostream>

#include <thread>

//denisov.univ@gmail.com
//sergvic
//sireukr

using namespace std;

vector<int> items = {1,2,3,4,5,6,6};

void addThread() {
	int i = 0;
	while (i<500000000) {
		items.push_back(i*i);
		//this_thread::sleep_for(0.00000001s);
		i++;
	}
}

void removeThread() {
	int i = 0;
	while (i<50000000) {
		if(items.size()>0)
			items.pop_back();
		//this_thread::sleep_for(0.00000001s);
		i++;
	}
}

void main()
{
	thread workers[] = { thread(addThread), thread(removeThread), thread(removeThread) };

	int k = 0;
	while (k<500) {
		cout << items.size()<<endl;

		this_thread::sleep_for(1s);
		k++;
	}

	for (int j=0; j<3; j++)
		workers[j].join();

	cout << "All threads finished!" << endl;

	return;
	
	MrCat cafe;
	cafe.showMenu();

	Order newOrder(3);
	newOrder += new Pizza("QuattroFormagio");
	newOrder += new Soup("Miso");
	
	cout << newOrder;

	//Dish *dishes[] = { 
	//	new Pizza("QuattroFormagio"),
	//	new Pizza("Margarita"),
	//	new Pizza("Havayian"),
	//	new Soup("Miso"),
	//	new Soup("CreamCheese"),
	//	new Pasta("Bolognees")
	//};
}