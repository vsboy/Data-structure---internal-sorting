#include <iostream>
using namespace std;


void InsertSort(int r[], int n);                  //直接顺序排序
void ShellSort(int r[], int n);                   //希尔排序
void BubbleSort(int r[], int n);                  //起泡排序
int Partition(int r[], int first, int end);       //快速排序一次划分
void QuickSort(int r[], int first, int end);      //快速排序
void SelectSort(int r[ ], int n);                 //简单选择排序
void Sift(int r[], int k, int m);                 //筛选法调整堆
void HeapSort(int r[ ], int n);                   //堆排序
void Merge(int r[], int r1[], int s, int m, int t);//一次归并
void MergePass(int r[ ], int r1[ ], int n, int h); //一趟归并
void MergeSort1(int r[ ], int r1[ ], int n );      //归并排序的非递归算法
void MergeSort2(int r[], int r1[], int r2[],int s, int t);//归并排序的递归算法

int main()
{
 
  const int numv=11;                                //赋值
  int a[]={0,3,56,32,78,5,24,9,64,34,7};
  int b[]={0,4,6,23,45,15,10,36,25,79,21};
  int c[]={38,23,56,2,79,42,93,29,6,5,57};
  int d[]={50,23,45,67,87,14,29,32,44,97,89};
  int e[]={8,6,1,48,37,63,39,74,52,26,49};
  int f[]={12,23,45,87,2,6,15,43,26,40,44};
  int g[]={13,10,23,45,64,34,24,7,9,3,16};
  int h[]={34,23,54,76,12,13,14,11,78,8,66};
  int g1[numv];
  int h1[numv];
  int h2[numv];  

  cout << "\n直接顺序排序前：" << "\n";
  for(int j=1;j<numv;j++)
	  cout<<a[j]<<" ";
  cout << "\n直接顺序排序结果为：" << "\n";
  InsertSort(a,numv);  

  cout << "\n希尔排序前：" << "\n";
  for(int j=1;j<numv;j++)
	  cout<<b[j]<<" ";
  cout << "\n希尔排序结果为：" << "\n";
  ShellSort(b, numv);
  
  cout << "\n起泡排序前：" << "\n";
  for(int k=0;k<numv;k++)
	  cout<<c[k]<<" ";
  cout << "\n起泡排序结果为：" << "\n";
  BubbleSort(c, numv);

  cout << "\n快速排序前：" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<d[j]<<" ";
  cout << "\n快速排序结果为：" << "\n";
  QuickSort(d,0,numv-1);  
  for(int i=0;i<numv;i++)
     cout<<d[i]<<" ";
  cout<<"\n";

  cout << "\n简单选择排序前：" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<e[j]<<" ";
  cout << "\n简单选择排序结果为：" << "\n";
  SelectSort(e,numv);

  cout << "\n堆排序前：" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<f[j]<<" ";
  cout << "\n堆排序结果为：" << "\n";
  HeapSort(f, numv);

  cout << "\n归并排序非递归算法前：" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<g[j]<<" ";
  cout << "\n归并排序非递归算法的结果为：" << "\n";
  MergeSort1(g, g1,numv );

  cout << "\n归并排序递归算法前：" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<h[j]<<" ";
  cout << "\n归并排序递归算法的结果为：" << "\n";
  MergeSort2(h,h1,h2, 0, numv-1);
  for(int i=0; i < numv; i++)
       cout<<h1[i]<<" ";
  cout<<"\n";

  return 0;
}
