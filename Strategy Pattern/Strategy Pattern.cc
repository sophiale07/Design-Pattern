#include<iostream>
using namespace std;

//策略模式

class Strategy{
public:
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA: public Strategy{
public:
	void AlgorithmInterface(){
		cout<<"算法A实现"<<endl;
	}
};

class ConcreteStrategyB: public Strategy{
public:
	void AlgorithmInterface(){
		cout<<"算法B实现"<<endl;
	}
};

class ConcreteStrategyC: public Strategy{
public:
	void AlgorithmInterface(){
		cout<<"算法C实现"<<endl;
	}
};

class Context{
public:
	Strategy *strategy;
    /* //普通策略模式
	Context(Strategy *strategy){
		this->strategy = strategy;
	}*/

	//策略模式与简单工厂模式结合
	Context(char type){
		switch(type)
		{
		case 'A':
			this->strategy = new ConcreteStrategyA();
			break;
		case 'B':
			this->strategy = new ConcreteStrategyB();
			break;
		case 'C':
			this->strategy = new ConcreteStrategyC();
			break;
		}
	}


	void ContextInterface()
	{
		strategy->AlgorithmInterface();
	}
};

void main(){
	/*//普通策略模式，客户端需要认识Context类和Strategy类
	Context *context1 = new Context(new ConcreteStrategyA());
	Context *context2 = new Context(new ConcreteStrategyB());
	Context *context3 = new Context(new ConcreteStrategyC());
	
	context1->ContextInterface();
	context2->ContextInterface();
	context3->ContextInterface();*/



    //策略模式与简单工厂模式结合，客户端只需要认识一个类Context，耦合性更加降低。
	Context *context1 = new Context('A');
	Context *context2 = new Context('B');
	Context *context3 = new Context('C');
    context1->ContextInterface();
    context2->ContextInterface();
    context3->ContextInterface();
}

