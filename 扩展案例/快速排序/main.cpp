#include<iostream>
using namespace std;
void quicksort(int a[],int n,int low,int high)
{
	
	int s,temp;
	s=low;
	if(low<high)
	{
		while(low<high)
		{
			if(s==low)
			{
				while(a[high]>a[s])
					high--;
				temp=a[s];
				a[s]=a[high];
				a[high]=temp;
				s=high;
				low++;
			}
			else if(s==high)
			{
				while(a[low]<a[s])
					low++;
				temp=a[s];
				a[s]=a[low];
				a[low]=temp;
				s=low;
				high--;
			}
		}
	quicksort(a,low,0,low-1);
	quicksort(a,n,high+1,n-1);
	}
}
void main()
{
	int a[15]={32,34,11,12,50,29,36,50,55,10,45,76,24,68,16};
	cout<<"排序前"<<endl;
	for(int i=0;i<15;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	quicksort(a,15,0,14);
	cout<<"快速排序后"<<endl;
	for(int i=0;i<15;i++)
		cout<<a[i]<<" ";
	cout<<endl;

}
