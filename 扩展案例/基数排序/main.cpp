#include<iostream>
#include<math.h>
#include<iomanip>
#include"SqList.h"
#include"Sequeue.h"
using namespace std;
void basesort(SqList<int>&L,int num)
{
	int i,j,k,n,temp,sub; 
	n=L.leng();
	SqQueue<int> base[10];
	for(i=0;i<num;i++)
	{
		k=int(pow(10,i*1.0));
		for(j=1;j<=n;j++)//将各位数字进入相应的队列
		{
			temp=L.gete(j);
			sub=(temp/k)%10;//第i+1位数字
			base[sub].enque(temp);//进队
		}
		L.init();//初始化顺序表
		for(j=0;j<10;j++)//出队
		{
			while(base[j].empt()==false)
				L.insertrear(base[j].dlque());
		}
	}		
}
void main()
{
	int a[10]={124,356,100,200,898,564,754,258,658,200};
	SqList<int> mylist(a,10,20);
	cout<<"排序前"<<endl;
	mylist.print();
	basesort(mylist,3);
	cout<<"基数排序"<<endl;
	mylist.print();
}
