#include<iostream>
using namespace std;

//抽象工厂模式


//抽象产品A
class AbstractProductA
{
public:
	virtual void Operation() = 0;//纯虚函数
};


//具体产品A1
class ConcreteProductA1: public AbstractProductA
{
public:
	void Operation()
	{
		cout<<"ConcreteProductA1"<<endl;
	}
};


//具体产品A2
class ConcreteProductA2:public AbstractProductA
{
public:
	void Operation()
	{
		cout<<"ConcreteProductA2"<<endl;
	}
};

//抽象产品B
class AbstractProductB
{
public:
	virtual void Operation() = 0;//纯虚函数
};


//具体产品B1
class ConcreteProductB1: public AbstractProductB
{
public:
	void Operation()
	{
		cout<<"ConcreteProductB1"<<endl;
	}
};


//具体产品B2
class ConcreteProductB2:public AbstractProductB
{
public:
	void Operation()
	{
		cout<<"ConcreteProductB2"<<endl;
	}
};


//抽象工厂
class AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
};

//具体工厂1
class ConcreteFactory1: public AbstractFactory
{
public:
	AbstractProductA* CreateProductA()
	{
		return new ConcreteProductA1();
	}
	AbstractProductB* CreateProductB()
	{
		return new ConcreteProductB1();
	}
			
};

//具体工厂2
class ConcreteFactory2: public AbstractFactory
{
public:
	AbstractProductA* CreateProductA()
	{
		return new ConcreteProductA2();
	}
	AbstractProductB* CreateProductB()
	{
		return new ConcreteProductB2();
	}
			
};


void main()
{
	AbstractFactory *f1 = new ConcreteFactory1();
    AbstractFactory *f2 = new ConcreteFactory2();
	f1->CreateProductA()->Operation();
	f1->CreateProductB()->Operation();
	f2->CreateProductA()->Operation();
	f2->CreateProductB()->Operation();

	delete f1;
	delete f2;
}