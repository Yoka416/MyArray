#include<iostream>
using namespace std;
#include<string>
#include "myarray.hpp"

void printfArray(MyArray<int> &arr)
{
	for(int i=0;i<arr.get_size();i++)//!����д��arr.m_size�������������,��Ϊ����˽��!
	{
		cout<<"�����е�Ԫ��Ϊ��"<<arr[i]<<endl;//������д��r'r��
	}
}
//void printfArray(MyArray <int>& arr)
//{
//	for (int i = 0; i < arr.get_size(); i++)
//	{
//		cout << arr[i] << endl;
//	}
//}
void test01()
{
	MyArray <int> arr1(5);
	
	/*MyArray<int>arr3(arr1);
	arr3=arr1;*/
for(int i=0;i<5;i++)
{
	arr1.Push_back(i);
}

printfArray( arr1);

cout<<"arr1������"<<arr1.get_capacity()<<endl;
cout<<"arr1�������С"<<arr1.get_size()<<endl;

MyArray<int>arr2(arr1);//!˳�����Ҫ�����ܷ�����ǰ��!
cout << "arr2�Ĵ�ӡ���Ϊ�� " << endl;
printfArray( arr2);

//βɾ
	arr2.Pop_back();
	cout << "arr2βɾ��" << endl;
	cout << "arr2������Ϊ�� " << arr2.get_capacity() << endl;
	cout << "arr2�Ĵ�СΪ�� " << arr2.get_size() << endl;

	cout << "arr2�Ĵ�ӡ���Ϊ�� " << endl;
	printfArray( arr2);
}


int main()
{
	test01();

	system("pause");
	return 0;
}
