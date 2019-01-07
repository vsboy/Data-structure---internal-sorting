#include<iostream>
#include<iomanip>
using namespace std;
void insertsort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void main()
{
	 int a[16]={32,34,11,12,50,29,36,50,55,10,45,76,24,68,16,99};
	 cout<<"排序前"<<endl;
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 cout<<"直接插入排序后"<<endl;
	 insertsort(a,16);
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 

}