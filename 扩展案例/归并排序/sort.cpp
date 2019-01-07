#include<iostream>
using namespace std;
//一次归并
void Merge(int r[], int r1[], int s, int m, int t)
{

	int i=s;
	int j=m+1;
	int k=s;
      
     while (i<=m && j<=t)
	 {   
         if (r[i]<=r[j]) 
			 r1[k++]=r[i++];            //取r[i]和r[j]中较小者放入r1[k]
         else 
			 r1[k++]=r[j++]; 
	 }
      if (i<=m) 
		  while (i<=m)                  //若第一个子序列没处理完，则进行收尾处理         
			  r1[k++]=r[i++]; 
      else  
		  while (j<=t)                  //若第二个子序列没处理完，则进行收尾处理        
			r1[k++]=r[j++]; 
}


//一趟归并
void MergePass(int r[ ], int r1[ ], int n, int h)
{
	int i=0;
	int k;

   while (i<=n-2*h)                     //待归并记录至少有两个长度为h的子序列
   {
     Merge(r, r1, i, i+h-1, i+2*h-1);
        i+=2*h;
   }
   if (i<n-h) 
	   Merge(r, r1, i, i+h-1, n);       //待归并序列中有一个长度小于h
   else for (k=i; k<=n; k++)            //待归并序列中只剩一个子序列
        r1[k]=r[k];
}

//归并排序的非递归算法
void MergeSort1(int r[ ], int r1[ ], int n )
{ 
  int h=1;
  int i;

  while (h<n)
  {
    MergePass(r, r1, n-1, h);           //归并
    h=2*h;
    MergePass(r1, r, n-1, h);
    h=2*h;
  }
  for(i=0;i<n;i++)
      cout<<r[i]<<" ";
  cout<<"\n";
}

//归并排序的递归算法
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
            MergeSort2(r, r2, r1, s, m);        //归并排序前半个子序列		
            MergeSort2(r, r2, r1, m+1, t);      //归并排序后半个子序列
            Merge(r2, r1, s, m, t);             //将两个已排序的子序列归并 		
	}	 
}
int main()
{
  const int numv=11;                                //赋值
  int g[]={13,10,23,45,64,34,24,7,9,3,16};
  int h[]={34,23,54,76,12,13,14,11,78,8,66};
  int g1[numv];
  int h1[numv];
  int h2[numv];  
  cout << "归并排序非递归算法前：" <<endl;
  for(int j=0;j<numv;j++)
	  cout<<g[j]<<" ";
  cout<<endl;
  cout << "归并排序非递归算法的结果为：" << endl;
  MergeSort1(g, g1,numv );

  cout << "归并排序递归算法前：" << endl;
  for(int j=0;j<numv;j++)
	  cout<<h[j]<<" ";
   cout<<endl;
  cout << "归并排序递归算法的结果为：" << endl;
  MergeSort2(h,h1,h2, 0, numv-1);
  for(int i=0; i < numv; i++)
       cout<<h1[i]<<" ";
   cout<<endl;

  return 0;
}
