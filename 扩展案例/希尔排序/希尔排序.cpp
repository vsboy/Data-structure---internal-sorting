#include<iostream>
#include<iomanip>
using namespace std;
void shellsort(int a[],int n,int step[],int m)
{
	int i,j,k,l,temp;
	for(i=0;i<m;i++)//���ݲ�������ȷ��ϣ�����������
	{
		for(j=0;j<step[i];j++)//һ��ϣ��������Ҫ���ֵķֶ��������е���Ŀ
		{
			for(k=j+step[i];k<n;k=k+step[i])//�Ի��ֺ��һ�����ݽ��в�������
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
	 cout<<"����ǰ"<<endl;
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 cout<<"ϣ�������"<<endl;
	 shellsort(a,16,step,3);
	 for(int i=0;i<16;i++)
		 cout<<setw(3)<<a[i];
	 cout<<endl;
	 

}
