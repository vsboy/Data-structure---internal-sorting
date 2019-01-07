#include<iostream>
#include<iomanip>
using namespace std;
void floatsort(int a[],int n)//¸Ä½øµÄÃ°ÅÝÅÅÐò
{
	int i,j,flag,temp;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
void main()
{
	 int a[16]={32,34,11,12,50,29,36,50,55,10,45,76,24,68,16,99};
	 cout<<"ÅÅÐòÇ°"<<endl;
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 cout<<"Ã°ÅÝÅÅÐòºó"<<endl;
	 floatsort(a,16);
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 

}