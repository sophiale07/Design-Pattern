#include<iostream>
using namespace std;

//ǳ���������Թ۲쵽p�ĵ�ַ��һ���ģ�������ʱ����Ϊ�ظ��ͷ�ͬһ��ַ�ռ䣬�����

class PrototypeWrong
{
private:
	int a;
	int *p;//������һ��ָ��

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
	//p1��p2ָ��ͬһ����ַ�������ظ�����ָ��p����ɴ���
	PrototypeWrong p1;
	PrototypeWrong p2 = p1;

	p1.outputPointerAddress();
	p2.outputPointerAddress();

}