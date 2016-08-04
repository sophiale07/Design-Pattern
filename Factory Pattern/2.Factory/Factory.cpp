#include<iostream>
using namespace std;

//(普通)工厂模式


//抽象产品
class Product
{
public:
	virtual void Operation() = 0;//纯虚函数
};


//具体产品1
class ConcreteProduct1: public Product
{
public:
	void Operation()
	{
		cout<<"ConcreteProduct1"<<endl;
	}
};


//具体产品2
class ConcreteProduct2:public Product
{
public:
	void Operation()
	{
		cout<<"ConcreteProduct2"<<endl;
	}
};

//抽象工厂
class Factory
{
public:
	virtual Product* CreateProduct() = 0;
};

//具体工厂1
class ConcreteFactory1: public Factory
{
public:
	Product* CreateProduct()
	{
		return new ConcreteProduct1();
	}
			
};

//具体工厂2
class ConcreteFactory2: public Factory
{
public:
	Product* CreateProduct()
	{
		return new ConcreteProduct2();
	}
			
};


void main()
{
	Factory *f1 = new ConcreteFactory1();
    Factory *f2 = new ConcreteFactory2();
	f1->CreateProduct()->Operation();
	f2->CreateProduct()->Operation();

	delete f1;
	delete f2;
}