#include<iostream>
template<class T>
class heap
{
	T * a;//数据成员
	int n;//元素个数
	int flag;//标识大堆或小堆
	public:
		heap(T b[],int m,int heapflag)//构造函数;数据元素从1开始存放
		{
			int lastparent,left,right,k,j;
			T temp,min,max;
			lastparent=m/2;
			n=m;
			flag=heapflag;
			a=new T[n+1];
			for(int i=1;i<=n;i++)
				a[i]=b[i-1];
			if(flag==0)//建小根堆
			{
				for(int i=lastparent;i>=1;i--)
				{
					k=i;
					left=2*k;
					right=2*k+1;
					if(right<=m)
					{
						min=a[left]<a[right]?a[left]:a[right];//左右孩子的最小值
						j=a[left]<a[right]?left:right;//最小值孩子的序号
					}
					else
					{
						min=a[left];
						j=left;
					}
						while((a[k]>min)&&(k<=lastparent))//交换
						{
							temp=a[k];
							a[k]=a[j];
							a[j]=temp;
							k=j;
							if(k<=lastparent)
							{
								left=2*k;
								right=2*k+1;
								if(right<=m)
								{
									min=a[left]<a[right]?a[left]:a[right];//左右孩子的最小值
									j=a[left]<a[right]?left:right;//最小值孩子的序号
								}
								else
								{
									min=a[left];
									j=left;
								}
							}

						}
				}
			}
			else if(flag==1)//大根堆
			{
				for(int i=lastparent;i>=1;i--)
				{
					k=i;
					left=2*k;
					right=2*k+1;
					if(right<=m)
					{
					max=a[left]>a[right]?a[left]:a[right];//左右孩子的最大值
					j=a[left]>a[right]?left:right;//最大值孩子的序号
					}
					else
					{
						max=a[left];//左右孩子的最大值
						j=left;//最大值孩子的序号
					}
						while((a[k]<max)&&(k<=lastparent))//交换
						{
							temp=a[k];
							a[k]=a[j];
							a[j]=temp;
							k=j;
							if(k<=lastparent)
							{
								left=2*k;
								right=2*k+1;
								if(right<=m)
								{
									max=a[left]>a[right]?a[left]:a[right];//左右孩子的最大值
									j=a[left]>a[right]?left:right;//最大值孩子的序号
								}
								else
								{
									max=a[left];//左右孩子的最大值
									j=left;//最大值孩子的序号
								}
							}

						}
				
				}
			}
		}
	void print()
	{
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	void Vprint(int high)//high表示堆的高度
	{
		int m;
		m=pow(2,high*1.0)-1;
		T *b;
		b=new T[m];
		for(int i=0;i<n;i++ )//复制a[]
			b[i]=a[i+1];
		for(int i=n;i<m;i++)
			b[i]=-1;
	int first,firstleft,linestep;
	//first表示每一行首元素的下标；
	//firstleft表示首元素距离屏幕左边的距离；
	//linestep表示每行元素之间的间隔
	//high表示树的层次数即高度
	for(int i=1;i<=high;i++)
		//打印首元素
	{	
		firstleft=(pow(2,(high-i)*1.0)-1)*2;//计算首元素的起始位置
		for(int j=1;j<=firstleft;j++)
			cout<<" ";
			first=pow(2,(i-1)*1.0)-1;//首元素的下标
			if(b[first]!=-1)//若结点存在
				cout<<setw(2)<<b[first];
			else//不存在
				cout<<setw(2)<<" ";
		//打印同行的其它元素
		for(int k=pow(2,(i-1)*1.0)+1;k<=pow(2,i*1.0)-1;k++)
		{
			linestep=pow(2,(high-i)*1.0)*4;//计算该行元素间隔
			if(b[k-1]!=-1)//若结点存在
				cout<<setw(linestep)<<b[k-1];
			else
				cout<<setw(linestep)<<" ";
		}
		//本行打印完毕，换行
		cout<<endl;
	}
	}

};
