#include <iostream>

#include <thread>
#include <mutex>

using namespace std;

class Base {
public:	
	Base(int initDyna):dyna(initDyna)
	{}
protected:
	int dyna;
};

class A : public Base {
public:
	A(const A &a) : Base(a.dyna), base(a.base) { cout << "!!!!!!!! Copying A!\n"; }

	A& operator= (A &a) {
		dyna = a.dyna;
		cout << "!!!!!!!! Assigning A!\n";

		return *this;
	}

	A(int initBase) : Base(33), base(initBase)
	{	}

	A() : Base(11), base(staticBase)
	{	}

	int getDynamicVar() { return dyna; }
	void setDynamicVar(int newValue) { dyna = newValue; }

	static int staticVar;

	const int base;
	static const int staticBase = 10;
};

int A::staticVar;

A &modifyA(const A &obj) {
	A tmp(obj);
	tmp.setDynamicVar(99);
	return tmp;
}

void printA(char *name, A &obj) {
	cout << name << endl
		<< " Dynamic: " << obj.getDynamicVar()
		<< "; Base: " << obj.base
		<< "; Static: " << obj.staticVar
		<< endl;
}

void main()
{
	int tmpVar = 2;
	A tester(3), secondTester;
	tester.setDynamicVar(tester.getDynamicVar() + 1);
	tester.staticVar = 1;
	secondTester.staticVar = 2;

	tester = modifyA(tester);

	//A thirdTester(tester);

	printA("The first tester: ", tester);
	//printA("The third tester: ", thirdTester);
}