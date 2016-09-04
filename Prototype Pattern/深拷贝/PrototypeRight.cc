#include<iostream>
using namespace std;

//原型模式，本质就是深拷贝

class PrototypeRight
{
private:
	int a;
	int *p;
public:
	PrototypeRight()
	{
		a = 3;
		p = new int(2);
	}

	//不使用默认的拷贝构造函数
	PrototypeRight(const PrototypeRight &obj)
	{
		a = obj.a;
		p = new int(*obj.p);
	}

	//不使用默认的重载"="操作符
	PrototypeRight & PrototypeRight::operator = (const PrototypeRight &obj)
	{
		if(this == &obj)
			return *this;

		delete p; //删除指针p所值空间
		p = NULL; //防止野指针

		a = obj.a;
		p = new int(*obj.p);

		return *this;
	}

	void outputPointerAddress()
	{
		cout << p <<endl;
	}

	~PrototypeRight()
	{
		delete p;
	}
};

int main()
{
	PrototypeRight p1;
	PrototypeRight p2;
	p2 = p1; //调用重载操作符"="

	PrototypeRight p3 = p1;//调用拷贝构造函数


	p1.outputPointerAddress();
	p2.outputPointerAddress();
    p3.outputPointerAddress();

	return 0;
}
