#include <iostream>
using namespace std;


void InsertSort(int r[], int n);                  //ֱ��˳������
void ShellSort(int r[], int n);                   //ϣ������
void BubbleSort(int r[], int n);                  //��������
int Partition(int r[], int first, int end);       //��������һ�λ���
void QuickSort(int r[], int first, int end);      //��������
void SelectSort(int r[ ], int n);                 //��ѡ������
void Sift(int r[], int k, int m);                 //ɸѡ��������
void HeapSort(int r[ ], int n);                   //������
void Merge(int r[], int r1[], int s, int m, int t);//һ�ι鲢
void MergePass(int r[ ], int r1[ ], int n, int h); //һ�˹鲢
void MergeSort1(int r[ ], int r1[ ], int n );      //�鲢����ķǵݹ��㷨
void MergeSort2(int r[], int r1[], int r2[],int s, int t);//�鲢����ĵݹ��㷨

int main()
{
 
  const int numv=11;                                //��ֵ
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

  cout << "\nֱ��˳������ǰ��" << "\n";
  for(int j=1;j<numv;j++)
	  cout<<a[j]<<" ";
  cout << "\nֱ��˳��������Ϊ��" << "\n";
  InsertSort(a,numv);  

  cout << "\nϣ������ǰ��" << "\n";
  for(int j=1;j<numv;j++)
	  cout<<b[j]<<" ";
  cout << "\nϣ��������Ϊ��" << "\n";
  ShellSort(b, numv);
  
  cout << "\n��������ǰ��" << "\n";
  for(int k=0;k<numv;k++)
	  cout<<c[k]<<" ";
  cout << "\n����������Ϊ��" << "\n";
  BubbleSort(c, numv);

  cout << "\n��������ǰ��" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<d[j]<<" ";
  cout << "\n����������Ϊ��" << "\n";
  QuickSort(d,0,numv-1);  
  for(int i=0;i<numv;i++)
     cout<<d[i]<<" ";
  cout<<"\n";

  cout << "\n��ѡ������ǰ��" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<e[j]<<" ";
  cout << "\n��ѡ��������Ϊ��" << "\n";
  SelectSort(e,numv);

  cout << "\n������ǰ��" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<f[j]<<" ";
  cout << "\n��������Ϊ��" << "\n";
  HeapSort(f, numv);

  cout << "\n�鲢����ǵݹ��㷨ǰ��" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<g[j]<<" ";
  cout << "\n�鲢����ǵݹ��㷨�Ľ��Ϊ��" << "\n";
  MergeSort1(g, g1,numv );

  cout << "\n�鲢����ݹ��㷨ǰ��" << "\n";
  for(int j=0;j<numv;j++)
	  cout<<h[j]<<" ";
  cout << "\n�鲢����ݹ��㷨�Ľ��Ϊ��" << "\n";
  MergeSort2(h,h1,h2, 0, numv-1);
  for(int i=0; i < numv; i++)
       cout<<h1[i]<<" ";
  cout<<"\n";

  return 0;
}
