#include<iostream>
using namespace std;

//���󹤳�ģʽ


//�����ƷA
class AbstractProductA
{
public:
	virtual void Operation() = 0;//���麯��
};


//�����ƷA1
class ConcreteProductA1: public AbstractProductA
{
public:
	void Operation()
	{
		cout<<"ConcreteProductA1"<<endl;
	}
};


//�����ƷA2
class ConcreteProductA2:public AbstractProductA
{
public:
	void Operation()
	{
		cout<<"ConcreteProductA2"<<endl;
	}
};

//�����ƷB
class AbstractProductB
{
public:
	virtual void Operation() = 0;//���麯��
};


//�����ƷB1
class ConcreteProductB1: public AbstractProductB
{
public:
	void Operation()
	{
		cout<<"ConcreteProductB1"<<endl;
	}
};


//�����ƷB2
class ConcreteProductB2:public AbstractProductB
{
public:
	void Operation()
	{
		cout<<"ConcreteProductB2"<<endl;
	}
};


//���󹤳�
class AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
};

//���幤��1
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

//���幤��2
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