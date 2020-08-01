#include<iostream>
using namespace std;
#include<string>
#include "myarray.hpp"

void printfArray(MyArray<int> &arr)
{
	for(int i=0;i<arr.get_size();i++)//!不能写成arr.m_size，这是类外访问,因为它是私有!
	{
		cout<<"数组中的元素为："<<arr[i]<<endl;//！不用写成r'r！
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

cout<<"arr1的容量"<<arr1.get_capacity()<<endl;
cout<<"arr1的数组大小"<<arr1.get_size()<<endl;

MyArray<int>arr2(arr1);//!顺序很重要，不能放在最前面!
cout << "arr2的打印输出为： " << endl;
printfArray( arr2);

//尾删
	arr2.Pop_back();
	cout << "arr2尾删后：" << endl;
	cout << "arr2的容量为： " << arr2.get_capacity() << endl;
	cout << "arr2的大小为： " << arr2.get_size() << endl;

	cout << "arr2的打印输出为： " << endl;
	printfArray( arr2);
}


int main()
{
	test01();

	system("pause");
	return 0;
}
