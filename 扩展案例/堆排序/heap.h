#include<iostream>
template<class T>
class heap
{
	T * a;//���ݳ�Ա
	int n;//Ԫ�ظ���
	int flag;//��ʶ��ѻ�С��
	public:
		heap(T b[],int m,int heapflag)//���캯��;����Ԫ�ش�1��ʼ���
		{
			int lastparent,left,right,k,j;
			T temp,min,max;
			lastparent=m/2;
			n=m;
			flag=heapflag;
			a=new T[n+1];
			for(int i=1;i<=n;i++)
				a[i]=b[i-1];
			if(flag==0)//��С����
			{
				for(int i=lastparent;i>=1;i--)
				{
					k=i;
					left=2*k;
					right=2*k+1;
					if(right<=m)
					{
						min=a[left]<a[right]?a[left]:a[right];//���Һ��ӵ���Сֵ
						j=a[left]<a[right]?left:right;//��Сֵ���ӵ����
					}
					else
					{
						min=a[left];
						j=left;
					}
						while((a[k]>min)&&(k<=lastparent))//����
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
									min=a[left]<a[right]?a[left]:a[right];//���Һ��ӵ���Сֵ
									j=a[left]<a[right]?left:right;//��Сֵ���ӵ����
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
			else if(flag==1)//�����
			{
				for(int i=lastparent;i>=1;i--)
				{
					k=i;
					left=2*k;
					right=2*k+1;
					if(right<=m)
					{
					max=a[left]>a[right]?a[left]:a[right];//���Һ��ӵ����ֵ
					j=a[left]>a[right]?left:right;//���ֵ���ӵ����
					}
					else
					{
						max=a[left];//���Һ��ӵ����ֵ
						j=left;//���ֵ���ӵ����
					}
						while((a[k]<max)&&(k<=lastparent))//����
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
									max=a[left]>a[right]?a[left]:a[right];//���Һ��ӵ����ֵ
									j=a[left]>a[right]?left:right;//���ֵ���ӵ����
								}
								else
								{
									max=a[left];//���Һ��ӵ����ֵ
									j=left;//���ֵ���ӵ����
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
	void Vprint(int high)//high��ʾ�ѵĸ߶�
	{
		int m;
		m=pow(2,high*1.0)-1;
		T *b;
		b=new T[m];
		for(int i=0;i<n;i++ )//����a[]
			b[i]=a[i+1];
		for(int i=n;i<m;i++)
			b[i]=-1;
	int first,firstleft,linestep;
	//first��ʾÿһ����Ԫ�ص��±ꣻ
	//firstleft��ʾ��Ԫ�ؾ�����Ļ��ߵľ��룻
	//linestep��ʾÿ��Ԫ��֮��ļ��
	//high��ʾ���Ĳ�������߶�
	for(int i=1;i<=high;i++)
		//��ӡ��Ԫ��
	{	
		firstleft=(pow(2,(high-i)*1.0)-1)*2;//������Ԫ�ص���ʼλ��
		for(int j=1;j<=firstleft;j++)
			cout<<" ";
			first=pow(2,(i-1)*1.0)-1;//��Ԫ�ص��±�
			if(b[first]!=-1)//��������
				cout<<setw(2)<<b[first];
			else//������
				cout<<setw(2)<<" ";
		//��ӡͬ�е�����Ԫ��
		for(int k=pow(2,(i-1)*1.0)+1;k<=pow(2,i*1.0)-1;k++)
		{
			linestep=pow(2,(high-i)*1.0)*4;//�������Ԫ�ؼ��
			if(b[k-1]!=-1)//��������
				cout<<setw(linestep)<<b[k-1];
			else
				cout<<setw(linestep)<<" ";
		}
		//���д�ӡ��ϣ�����
		cout<<endl;
	}
	}

};
