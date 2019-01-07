#include<iostream>
using namespace std;
//һ�ι鲢
void Merge(int r[], int r1[], int s, int m, int t)
{

	int i=s;
	int j=m+1;
	int k=s;
      
     while (i<=m && j<=t)
	 {   
         if (r[i]<=r[j]) 
			 r1[k++]=r[i++];            //ȡr[i]��r[j]�н�С�߷���r1[k]
         else 
			 r1[k++]=r[j++]; 
	 }
      if (i<=m) 
		  while (i<=m)                  //����һ��������û�����꣬�������β����         
			  r1[k++]=r[i++]; 
      else  
		  while (j<=t)                  //���ڶ���������û�����꣬�������β����        
			r1[k++]=r[j++]; 
}


//һ�˹鲢
void MergePass(int r[ ], int r1[ ], int n, int h)
{
	int i=0;
	int k;

   while (i<=n-2*h)                     //���鲢��¼��������������Ϊh��������
   {
     Merge(r, r1, i, i+h-1, i+2*h-1);
        i+=2*h;
   }
   if (i<n-h) 
	   Merge(r, r1, i, i+h-1, n);       //���鲢��������һ������С��h
   else for (k=i; k<=n; k++)            //���鲢������ֻʣһ��������
        r1[k]=r[k];
}

//�鲢����ķǵݹ��㷨
void MergeSort1(int r[ ], int r1[ ], int n )
{ 
  int h=1;
  int i;

  while (h<n)
  {
    MergePass(r, r1, n-1, h);           //�鲢
    h=2*h;
    MergePass(r1, r, n-1, h);
    h=2*h;
  }
  for(i=0;i<n;i++)
      cout<<r[i]<<" ";
  cout<<"\n";
}

//�鲢����ĵݹ��㷨
void MergeSort2(int r[], int r1[], int r2[],int s, int t)
{ 
 
	int m;
	if (s==t) 
	{
		r1[s]=r[s];

	}
    else 
	{ 
            m=(s+t)/2;
            MergeSort2(r, r2, r1, s, m);        //�鲢����ǰ���������		
            MergeSort2(r, r2, r1, m+1, t);      //�鲢�������������
            Merge(r2, r1, s, m, t);             //������������������й鲢 		
	}	 
}
int main()
{
  const int numv=11;                                //��ֵ
  int g[]={13,10,23,45,64,34,24,7,9,3,16};
  int h[]={34,23,54,76,12,13,14,11,78,8,66};
  int g1[numv];
  int h1[numv];
  int h2[numv];  
  cout << "�鲢����ǵݹ��㷨ǰ��" <<endl;
  for(int j=0;j<numv;j++)
	  cout<<g[j]<<" ";
  cout<<endl;
  cout << "�鲢����ǵݹ��㷨�Ľ��Ϊ��" << endl;
  MergeSort1(g, g1,numv );

  cout << "�鲢����ݹ��㷨ǰ��" << endl;
  for(int j=0;j<numv;j++)
	  cout<<h[j]<<" ";
   cout<<endl;
  cout << "�鲢����ݹ��㷨�Ľ��Ϊ��" << endl;
  MergeSort2(h,h1,h2, 0, numv-1);
  for(int i=0; i < numv; i++)
       cout<<h1[i]<<" ";
   cout<<endl;

  return 0;
}
