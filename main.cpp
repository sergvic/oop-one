#include "Pizza.h"
#include "Soup.h"
#include "Pasta.h"
#include "Order.h"
#include "MrCat.h"
#include <iostream>

#include <thread>
#include <mutex>

//denisov.univ@gmail.com
//sergvic
//sireukr

using namespace std;

#pragma region Threading tests
mutex itemsLock;
vector<int> items = {1,2,3,4,5,6,6};

void addThread() {
	int i = 0;
	while (i<500000000) {
		itemsLock.lock();
		items.push_back(i*i);
		itemsLock.unlock();
		//this_thread::sleep_for(0.00000001s);
		
		i++;
	}
}

void removeThread() {
	int i = 0;
	while (i<50000000) {
		
		itemsLock.lock();

		for (int k = 0;k < 100;k++)
		{
			if (items.size() > 0)
				items.pop_back();
		}
		
		//this_thread::sleep_for(0.00000001s);
		
		itemsLock.unlock();
		i++;
	}
}

void testThreads()
{
	thread workers[] = { thread(addThread), thread(addThread), thread(addThread),  thread(removeThread), thread(removeThread) };

	int k = 0;
	while (k<500) {
		itemsLock.lock();
		cout << items.size() << endl;
		itemsLock.unlock();

		this_thread::sleep_for(1s);
		k++;
	}

	for (int j = 0; j<3; j++)
		workers[j].join();

	cout << "All threads finished!" << endl;
}
#pragma endregion

void main_main()
{
	int tableNum = 3;
	MrCat cafe;
	cafe.showMenu();

	Order newOrder(tableNum);

#pragma region Take order
	char c = -1;
	while (c != '0') {
		Dish *newDish = nullptr;
		cin >> c;
		switch (c)
		{
		case '1':
			newDish = new Pizza("QuattroFormagio", 150);
			break;
		case '2':
			newDish = new Soup("MisoSoup", 45);
			break;
		case '3':
			newDish = new Pasta("Spagetti", 50);
			break;
		default:
			break;
		}
		if (newDish != nullptr) {
			newOrder += newDish;
			cout << newDish->getName() << 
				" added to order. Current cheque: " << newOrder.Price() << endl;
		}
	}
		
	cout << newOrder<<endl;
	cout << "Cooking time: " << newOrder.getCookingTime()<<endl;
#pragma endregion

	//cafe.startOrder(newOrder);
	
	system("pause");
}