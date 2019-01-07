#include<iostream>
#include<math.h>
#include<iomanip>
#include"heap.h"
using namespace std;
void main()
{
	int a[12]={17,16,25,14,87,29,11,15,22,81,10,38};
	int flag,high;
	cout<<"输入数据序列："<<endl;
	for(int i=0;i<12;i++)
		cout<<setw(4)<<a[i];
	cout<<endl;
	cout<<"请输入要创建的堆的种类，小堆输入0，大堆输入1"<<endl;
	cin>>flag;
	heap<int>myheap(a,12,flag);
	high=int(log(12*1.0)/log(2*1.0))+1;
    myheap.Vprint(high);
}