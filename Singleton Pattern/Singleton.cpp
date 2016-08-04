#include<iostream>
using namespace std;

//����ģʽ

class Singleton
{
private:
	Singleton(){};//������ֱ�ӹ��������
	static Singleton *instance;

public:
	static Singleton* createInstance()
	{
		if(!instance)
		{
			// �����һ�α�����������
			cout<<"�����¶���"<<endl;
			instance = new Singleton();
		}
		else
		{
			 // �����ٴδ������󣬲�����
			cout<<"�Ѿ������������ˣ�����ԭ����"<<endl;
		}
		return instance;
	}

	void getAddress()
	{
		cout<< "�ҵĵ�ַ��"<<instance<<endl;
	}
};

Singleton* Singleton::instance = 0; //�ڳ�ʼ����ʱ�򣬲�����ǰ���static��

int main()
{
	//Singleton s;  //�����޷����� private ��Ա(�ڡ�Singleton����������)
	Singleton *s1 = Singleton::createInstance();
	s1->getAddress();

	cout<<endl<<endl;

	Singleton *s2 = Singleton::createInstance();
	s2->getAddress();

	return 0;
}


