template <class Telem>
class  SqQueue 
  {  Telem *elem;
     int front,rear;
     int len;
   public:
     SqQueue(int maxsz=100):len(maxsz)
         {elem=new Telem[len];
          front=rear=0;
         };
     ~SqQueue() {delete []elem; };
     void init(){front=rear=0;};
     int  leng(){ return (rear - front + len) % len;};
     bool empt(){return (front == rear);};
     bool full(){return ((rear+1)% len == front );};
     bool  enque (Telem& el);
     Telem dlque();
	 void prnt()
	 {
		 int i,n;
		 n=leng();
		 for(i=0;i<n;i++)
			 cout<<elem[i]<<"  ";
		 cout<<endl;
	 }
  };
template <class Telem> 
bool SqQueue <Telem>::enque (Telem& el)
{ if ( (rear+1)% len == front ) return(false);
  else { elem[rear]=el;
         rear= (rear+1)% len;
         return(true);
       }
}
template <class Telem> Telem SqQueue <Telem>::dlque()
{ Telem el;
  if (rear == front) return NULL;
  else { el=elem[front];
         front= (front+1)% len;
         return(el);
       }
}


