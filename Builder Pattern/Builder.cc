#include<iostream>
using namespace std;


//建造者模式


//抽象建造者
class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
};



//具体建造者1
class ConcreteBuilder1: public Builder
{
public:
	void BuildPartA(){
		cout<<"Build PartA using 1"<<endl;
	}

	void BuildPartB(){
		cout<<"Build PartB using 1"<<endl;
	}
};



//具体建造者2
class ConcreteBuilder2: public Builder
{
public:
	void BuildPartA(){
		cout<<"Build PartA using 2"<<endl;
	}

	void BuildPartB(){
		cout<<"Build PartB using 2"<<endl;
	}
};


//指挥者，方法的参数是抽象建造者的指针
class Director
{
public:
	void Construct(Builder *builder)
	{
		builder->BuildPartA();
		builder->BuildPartB();
	}
};

void main()
{
	Director d;
	d.Construct(new ConcreteBuilder1());
    d.Construct(new ConcreteBuilder2());

}