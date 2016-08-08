#include<iostream>
#include<string.h>
using namespace std;

//װ��ģʽ

//Component�����࣬����������Ľӿ�
class Component
{
public:
	virtual void Operation() = 0;
};

//ConcreteDecorator�������Component���󣬿��Ը��ö���̬���ְ��
class ConcreteComponent : public Component
{
public:
	void Operation(){
		cout<<"ԭְ��:ConcreteComponent"<<endl;
	}
};

//Decorator��װ�γ����࣬�̳���Component
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


 //ConcreteDecorator���Ǿ����װ�ζ���A���𵽸�Component���ְ��Ĺ���
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
		cout<<"����ְ��A:ConcreteDecoratorA::AddBehavorA"<<endl;
	}
	
};


 //ConcreteDecorator���Ǿ����װ�ζ���B���𵽸�Component���ְ��Ĺ���
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
		cout<<"����ְ��B:ConcreteDecoratorB::AddBehavorB"<<endl;
	}
};


void main()
{

	ConcreteComponent *c = new ConcreteComponent(); //Ҫװ�εĶ���c
	Decorator *d1 = new ConcreteDecoratorA();
	Decorator *d2 = new ConcreteDecoratorB();

	d1->SetComponent(c); //��װ�ζ��󸽼�ְ��d1
	d2->SetComponent(d1); //��װ�ζ��󸽼�ְ��d2
	d2->Operation();
	
}


//���ֻ��һ��ConcreteComponent���û�г����Component�࣬��ôDecorator�������ConcreteComponent��һ�����ࡣ
//Decoratorģʽ���˲�����ϵķ�ʽȡ���˱Ȳ��ü̳з�ʽ���õ�Ч����
//Decoratorģʽ������ƴ���һ�֡����ü������ķ�ʽ�����ְ��
//��OO��ƺͷ�������������һ�������Ϊ�˶�̬��ͨ������ָ��ָ����������࣬������ʹ�������һ�����⣬
//����������Ҫ����µ�ְ�𣬾ͱ������丸�����һ�����ְ��ĳ���ӿڣ�
//������ͨ������ָ���ǵ��ò�����������ˡ��������ڸ߲�ĸ���ͳ�����̫�����������������
//���Ҽ̳������������������඼���ɱ���̳��˸������Щ�ӿڣ����ǿ����Ⲣ�������������������Ҫ�ġ�
//����Decoratorģʽ�ṩ��һ�ֽϺõĽ������������Ҫ���һ��������ʱ��Ϳ���ͨ��Decoratorģʽ�������
//�����һ��������µ�ְ�𡣡�����������