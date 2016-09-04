#include<iostream>
using namespace std;

//浅拷贝，可以观察到p的地址是一样的，析构的时候因为重复释放同一地址空间，会出错

class PrototypeWrong
{
private:
	int a;
	int *p;//类中有一个指针

public:
	PrototypeWrong()
	{
		a = 3;
		p = new int(2);
	}

	void outputPointerAddress()
	{
		cout << p << endl;
	}

	~PrototypeWrong()
	{
		delete p;
	}
};

void main()
{
	//p1和p2指向同一个地址，导致重复析构指针p，造成错误
	PrototypeWrong p1;
	PrototypeWrong p2 = p1;

	p1.outputPointerAddress();
	p2.outputPointerAddress();

}