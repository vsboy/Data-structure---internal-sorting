template <class Telem>
class  SqList 
{
   private:
     Telem *elem;
     int curlen;
     int maxlen;
   public:
     SqList(int maxsz=100);
     SqList(Telem a[],int n,int maxsz=100);
     ~SqList(){delete[] elem;}
     void init(){ curlen=0;}
     Telem gete(int i);
     int leng(){return curlen;}
     int loct (Telem &el);
     bool inst (int loc,Telem &el);
	 bool insertrear(Telem el);
     Telem dele(int loc);
     bool full(){return curlen==maxlen;}
     bool empt(){return curlen==0;}
	 void inver();
	 void print();
	 SqList<Telem>& merg(SqList<Telem>& l2);
  };
template <class Telem> SqList<Telem>::SqList(int maxsz):maxlen(maxsz)
{      curlen=0;
       elem=new Telem[maxlen];
}
template <class Telem> SqList<Telem>::SqList(Telem a[],int n,int maxsz):maxlen(maxsz)
{      curlen=n;
       elem=new Telem[maxlen];
       for(int i=0;i<n;i++)
		   elem[i]=a[i];
}
template <class Telem> Telem SqList<Telem>::gete(int i)
{
	if(i>=1 &&i<=curlen)
		return elem[i-1];
	else
	    return NULL;
}
template <class Telem> int SqList<Telem>::loct(Telem &el)
{ 
  int i=0;
  while ((i<curlen)&&(elem[i]!=el) ) i++;
  if ( i<curlen ) return(i+1);  else return(0);
}
template <class Telem> bool SqList<Telem>::inst (int loc,Telem &el)
{ 
  int i;
  if((loc<1)||(loc>curlen+1)||(curlen==maxlen))       
    return(false);
  else  { curlen++;
          for (i=curlen-1;i>=loc;i-- ) elem[i]=elem[i-1];
          elem[loc-1]=el;
          return(true);
        }
}
template <class Telem> bool SqList<Telem>::insertrear (Telem el)
{ 
  if(curlen!=maxlen)       
  {
	  elem[curlen]=el;
	  curlen++;
	  return true;
  }
  else
	  return false;
}
template <class Telem> Telem SqList<Telem>::dele(int loc)
{ 
	int i; 
	Telem el;
  if ((loc<1)|| (loc>curlen)) return NULL;
  else { el=elem[loc-1];
         for (i=loc; i<curlen; i++)elem[i-1]=elem[i];
         curlen--;
         return(el);
        }
}
template <class Telem> void SqList<Telem>::inver( )
{ int i,m,n; Telem temp;
  n=curlen; m= n/2;
  for (i= 0;i<m; i++)
    { temp=elem[i];
      elem[i]=elem[n-1-i];
      elem[n-1-i]=temp;
    }
}
template <class Telem> 
SqList<Telem>& SqList<Telem>::merg(SqList<Telem>& l2)
{int i,m,n;
 m=curlen;n=l2.curlen;
 if(m+n<=maxlen)
   {for(i=0;i<n;i++)elem[m+i]=l2.elem[i];
    curlen=m+n;
    return *this;
   }
}
template <class Telem> void SqList<Telem>::print()
{
	int i;
	for(i=1;i<=curlen;i++)
		cout<<gete(i)<<" ";
	cout<<endl;
}

