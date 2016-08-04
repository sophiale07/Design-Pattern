#include<iostream>
using namespace std;

//简单工厂模式


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

//具体工厂
class Factory
{
public:
	Product* CreateProduct(int flag)
	{
		if(flag ==1)
		{
			return new ConcreteProduct1();
		}
		else if(flag ==2)
		{
			return new ConcreteProduct2();
		}
		else
		{
			return 0;
		}
	}
};

void main()
{
	Factory f;
	Product* p1 = f.CreateProduct(1);
	Product* p2 = f.CreateProduct(2);
	p1->Operation();
	p2->Operation();

	delete p1;
	delete p2;
}