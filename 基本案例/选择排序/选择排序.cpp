#include<iostream>
#include<iomanip>
using namespace std;
void selectsort(int a[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
				k=j;
		}
		if(k!=i)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
}
void main()
{
	 int a[16]={32,34,11,12,50,29,36,50,55,10,45,76,24,68,16,99};
	 cout<<"排序前"<<endl;
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 cout<<"直接选择排序后"<<endl;
	 selectsort(a,16);
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 

}