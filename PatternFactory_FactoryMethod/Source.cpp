#include <iostream>

using namespace std;
//Factory Method

class Transport
{

public:
	virtual void Go() = 0;
	
};

class Car:public Transport
{

public:
	void Go()override
	{
		cout << "Car moves" << endl;
	}
};

class Truck: public Transport
{

public:
	void Go()override
	{
		cout << "Truck moves" << endl;
	}
};

class Factory
{

public:
	virtual Transport* CreateObj() = 0;

};

class CarFactory:public Factory
{

public:

	Transport* CreateObj()override
	{
		return new Car;
	}
};

class TruckFactory: public Factory
{

public:

	Transport* CreateObj()override
	{
		return new Truck;
	}
};

int main()
{

	Factory* obj = new CarFactory;
	Factory* obj1 = new TruckFactory;
	Transport* t1 = obj->CreateObj();
	t1->Go();
	Transport* t2 = obj1->CreateObj();
	t2->Go();
	delete obj;
	delete obj1;




}