#include<iostream>
using namespace std;

//(��ͨ)����ģʽ


//�����Ʒ
class Product
{
public:
	virtual void Operation() = 0;//���麯��
};


//�����Ʒ1
class ConcreteProduct1: public Product
{
public:
	void Operation()
	{
		cout<<"ConcreteProduct1"<<endl;
	}
};


//�����Ʒ2
class ConcreteProduct2:public Product
{
public:
	void Operation()
	{
		cout<<"ConcreteProduct2"<<endl;
	}
};

//���󹤳�
class Factory
{
public:
	virtual Product* CreateProduct() = 0;
};

//���幤��1
class ConcreteFactory1: public Factory
{
public:
	Product* CreateProduct()
	{
		return new ConcreteProduct1();
	}
			
};

//���幤��2
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