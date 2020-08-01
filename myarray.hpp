#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
	private:

	int m_capacity;
	int m_size;
	T * m_MyArray;//指针的姓名最好不要和·

public:
	MyArray(int capacity) //！只用传一个参数！
	{
		cout<<"有参构造函数调用。"<<endl;
		this->m_capacity=capacity;
		this->m_size=0;
		this->m_MyArray = new T[this->m_capacity];//!这里再[]前面的T比较难懂，多理解!
	}

	MyArray(const MyArray& arr)//!函数名不变!
	{
		cout<<"深拷贝构造函数。"<<endl;
		this->m_capacity=arr.m_capacity;////深拷贝中的拷贝过程
		this->m_size=arr.m_size;
		//错了T *MyArray = new MyArray[this->m_capacity];//?
		this->m_MyArray = new T[this->m_capacity];

		for(int i=0; i<this->m_size;i++)//!!
		{
			this->m_MyArray[i]=arr.m_MyArray[i];
		}
	}
	
	MyArray& operator=(const MyArray& arr)//!函数名不变,operator!
	{
		if(this->m_MyArray!=NULL)//赋值前需要把被赋值的类的堆区释放干净
		{
			cout<<"等号重载函数"<<endl;
			delete[] this->m_MyArray;//!记得释放的是m_MyArray，不是myarray!
			this->m_MyArray=NULL;
			this->m_size=0;
			this->m_capacity=0;
		}
		this->m_capacity=arr.m_capacity;//拷贝过程
		this->m_size=arr.m_size;
		//错了T *MyArray = new MyArray[this->m_capacity];//?
		this->m_MyArray = new T [this->m_capacity];

		for(int i=0; i<this->m_size;i++)//!!
		{
			this->m_MyArray[i]=arr.m_MyArray[i];
		}

		return *this;
	}

	//插入数组元素 尾插法
	void Push_back(const T& val)
	{
		if(this->m_capacity == this->m_size)
		{
			cout<<"空间已满，不能插入！"<<endl;
			return;
		}
		this->m_MyArray[this->m_size]=val;
		this->m_size++;
	}

	//删除数组元素 尾删法
void Pop_back()
	{
		if(this->m_size == 0)
		{
			cout<<"空间已空，不能删除！"<<endl;
			return;
		}
		this->m_size--;
	}

//通过下标访问数组元素
T& operator[](int index) //!index代表传入的下标，上面的重载返回的是MyArray!
{
	return this->m_MyArray[index];
}

//返回数组的容量
int get_capacity()
{
	return this->m_capacity;
}
//返回数组的大小
int get_size()
{
	return this->m_size;
}
	
//void printfarray()//这是我自己写的打印函数，可以运行，然后看下老师给的打印函数
//{
//	for(int i=0;i<this->m_size;i++)
//	{
//		cout<<"数组中的元素为："<<m_MyArray[i]<<endl;
//	}
//}



	~MyArray()
	{
		if(this->m_MyArray!=NULL)
		{
			cout<<"默认析构函数调用。"<<endl;
			delete[] this->m_MyArray;
		this->m_MyArray=NULL;
		}
		
	}

};//！类又忘记加分号了！