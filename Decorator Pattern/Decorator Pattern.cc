#include<iostream>
#include<string.h>
using namespace std;

//装饰模式

//Component抽象类，定义该类对象的接口
class Component
{
public:
	virtual void Operation() = 0;
};

//ConcreteDecorator：具体的Component对象，可以给该对象动态添加职责
class ConcreteComponent : public Component
{
public:
	void Operation(){
		cout<<"原职责:ConcreteComponent"<<endl;
	}
};

//Decorator：装饰抽象类，继承自Component
class Decorator : public Component
{
public:
	void SetComponent(Component *component)
	{
		this->_component = component;
	}
	void Operation(){
		if(_component != NULL)
		{
			_component->Operation();
		}
	}

protected:
	Component *_component;
};


 //ConcreteDecorator就是具体的装饰对象A，起到给Component添加职责的功能
class ConcreteDecoratorA : public Decorator
{
public:
	void Operation()
	{
		this->_component->Operation();
		this->AddBehavorA();
	}
	void AddBehavorA()
	{
		cout<<"附加职责A:ConcreteDecoratorA::AddBehavorA"<<endl;
	}
	
};


 //ConcreteDecorator就是具体的装饰对象B，起到给Component添加职责的功能
class ConcreteDecoratorB : public Decorator
{
public:
	void Operation()
	{
		this->_component->Operation();
		this->AddBehavorB();
	}
	void AddBehavorB()
	{
		cout<<"附加职责B:ConcreteDecoratorB::AddBehavorB"<<endl;
	}
};


void main()
{

	ConcreteComponent *c = new ConcreteComponent(); //要装饰的对象c
	Decorator *d1 = new ConcreteDecoratorA();
	Decorator *d2 = new ConcreteDecoratorB();

	d1->SetComponent(c); //给装饰对象附加职责d1
	d2->SetComponent(d1); //给装饰对象附加职责d2
	d2->Operation();
	
}


//如果只有一个ConcreteComponent类而没有抽象的Component类，那么Decorator类可以是ConcreteComponent的一个子类。
//Decorator模式除了采用组合的方式取得了比采用继承方式更好的效果，
//Decorator模式还给设计带来一种“即用即付”的方式来添加职责。
//在OO设计和分析经常有这样一种情况：为了多态，通过父类指针指向其具体子类，但是这就带来另外一个问题，
//当具体子类要添加新的职责，就必须向其父类添加一个这个职责的抽象接口，
//否则是通过父类指针是调用不到这个方法了。这样处于高层的父类就承载了太多的特征（方法），
//并且继承自这个父类的所有子类都不可避免继承了父类的这些接口，但是可能这并不是这个具体子类所需要的。
//而在Decorator模式提供了一种较好的解决方法，当需要添加一个操作的时候就可以通过Decorator模式来解决，
//你可以一步步添加新的职责。　　　　　　