#include<iostream>
using namespace std;

//单例模式

class Singleton
{
private:
	Singleton(){};//不允许直接构造其对象
	static Singleton *instance;

public:
	static Singleton* createInstance()
	{
		if(!instance)
		{
			// 对象第一次被创建，允许
			cout<<"创建新对象"<<endl;
			instance = new Singleton();
		}
		else
		{
			 // 请求再次创建对象，不允许
			cout<<"已经创建过对象了，返回原对象"<<endl;
		}
		return instance;
	}

	void getAddress()
	{
		cout<< "我的地址是"<<instance<<endl;
	}
};

Singleton* Singleton::instance = 0; //在初始化的时候，不能在前面加static了

int main()
{
	//Singleton s;  //报错：无法访问 private 成员(在“Singleton”类中声明)
	Singleton *s1 = Singleton::createInstance();
	s1->getAddress();

	cout<<endl<<endl;

	Singleton *s2 = Singleton::createInstance();
	s2->getAddress();

	return 0;
}


