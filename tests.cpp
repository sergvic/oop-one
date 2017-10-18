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

void main()
{
	int tmpVar = 2;
	A tester(3), secondTester;
	tester.setDynamicVar(tester.getDynamicVar() + 1);
	tester.staticVar = 1;
	secondTester.staticVar = 2;

	cout << "Tests: \n" 
		<< " Dynamic: " << tester.getDynamicVar() 
		<< "; Base: " << tester.base 
		<< "; Static: " << tester.staticVar 
		<< endl;
}