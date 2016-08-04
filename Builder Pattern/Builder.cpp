#include<iostream>
using namespace std;


//������ģʽ


//��������
class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
};



//���彨����1
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



//���彨����2
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


//ָ���ߣ������Ĳ����ǳ������ߵ�ָ��
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