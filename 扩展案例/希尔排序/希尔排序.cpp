#include<iostream>
#include<iomanip>
using namespace std;
void shellsort(int a[],int n,int step[],int m)
{
	int i,j,k,l,temp;
	for(i=0;i<m;i++)//根据步长序列确定希尔排序的趟数
	{
		for(j=0;j<step[i];j++)//一趟希尔排序需要划分的分段数据序列的数目
		{
			for(k=j+step[i];k<n;k=k+step[i])//对划分后的一段数据进行插入排序
			{
				temp=a[k];
				l=k-step[i];
				while(l>=j && a[l]>temp)
				{
					a[l+step[i]]=a[l];
					l=l-step[i];
				}
				a[l+step[i]]=temp;
			}
		}
	}
}

void main()
{
	 int a[16]={32,34,11,12,50,29,36,50,55,10,45,76,24,68,16,99};
	 int step[3]={5,3,1};
	 cout<<"排序前"<<endl;
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 cout<<"希尔排序后"<<endl;
	 shellsort(a,16,step,3);
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 

}
