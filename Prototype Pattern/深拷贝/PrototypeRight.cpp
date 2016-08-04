#include<iostream>
using namespace std;

//ԭ��ģʽ�����ʾ������

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

	//��ʹ��Ĭ�ϵĿ������캯��
	PrototypeRight(const PrototypeRight &obj)
	{
		a = obj.a;
		p = new int(*obj.p);
	}

	//��ʹ��Ĭ�ϵ�����"="������
	PrototypeRight & PrototypeRight::operator = (const PrototypeRight &obj)
	{
		if(this == &obj)
			return *this;

		delete p; //ɾ��ָ��p��ֵ�ռ�
		p = NULL; //��ֹҰָ��

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
	p2 = p1; //�������ز�����"="

	PrototypeRight p3 = p1;//���ÿ������캯��


	p1.outputPointerAddress();
	p2.outputPointerAddress();
    p3.outputPointerAddress();

	return 0;
}
