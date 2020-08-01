#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
	private:

	int m_capacity;
	int m_size;
	T * m_MyArray;//ָ���������ò�Ҫ�͡�

public:
	MyArray(int capacity) //��ֻ�ô�һ��������
	{
		cout<<"�вι��캯�����á�"<<endl;
		this->m_capacity=capacity;
		this->m_size=0;
		this->m_MyArray = new T[this->m_capacity];//!������[]ǰ���T�Ƚ��Ѷ��������!
	}

	MyArray(const MyArray& arr)//!����������!
	{
		cout<<"������캯����"<<endl;
		this->m_capacity=arr.m_capacity;////����еĿ�������
		this->m_size=arr.m_size;
		//����T *MyArray = new MyArray[this->m_capacity];//?
		this->m_MyArray = new T[this->m_capacity];

		for(int i=0; i<this->m_size;i++)//!!
		{
			this->m_MyArray[i]=arr.m_MyArray[i];
		}
	}
	
	MyArray& operator=(const MyArray& arr)//!����������,operator!
	{
		if(this->m_MyArray!=NULL)//��ֵǰ��Ҫ�ѱ���ֵ����Ķ����ͷŸɾ�
		{
			cout<<"�Ⱥ����غ���"<<endl;
			delete[] this->m_MyArray;//!�ǵ��ͷŵ���m_MyArray������myarray!
			this->m_MyArray=NULL;
			this->m_size=0;
			this->m_capacity=0;
		}
		this->m_capacity=arr.m_capacity;//��������
		this->m_size=arr.m_size;
		//����T *MyArray = new MyArray[this->m_capacity];//?
		this->m_MyArray = new T [this->m_capacity];

		for(int i=0; i<this->m_size;i++)//!!
		{
			this->m_MyArray[i]=arr.m_MyArray[i];
		}

		return *this;
	}

	//��������Ԫ�� β�巨
	void Push_back(const T& val)
	{
		if(this->m_capacity == this->m_size)
		{
			cout<<"�ռ����������ܲ��룡"<<endl;
			return;
		}
		this->m_MyArray[this->m_size]=val;
		this->m_size++;
	}

	//ɾ������Ԫ�� βɾ��
void Pop_back()
	{
		if(this->m_size == 0)
		{
			cout<<"�ռ��ѿգ�����ɾ����"<<endl;
			return;
		}
		this->m_size--;
	}

//ͨ���±��������Ԫ��
T& operator[](int index) //!index��������±꣬��������ط��ص���MyArray!
{
	return this->m_MyArray[index];
}

//�������������
int get_capacity()
{
	return this->m_capacity;
}
//��������Ĵ�С
int get_size()
{
	return this->m_size;
}
	
//void printfarray()//�������Լ�д�Ĵ�ӡ�������������У�Ȼ������ʦ���Ĵ�ӡ����
//{
//	for(int i=0;i<this->m_size;i++)
//	{
//		cout<<"�����е�Ԫ��Ϊ��"<<m_MyArray[i]<<endl;
//	}
//}



	~MyArray()
	{
		if(this->m_MyArray!=NULL)
		{
			cout<<"Ĭ�������������á�"<<endl;
			delete[] this->m_MyArray;
		this->m_MyArray=NULL;
		}
		
	}

};//���������Ǽӷֺ��ˣ�