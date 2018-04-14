 #include<stdio.h>
 #include<conio.h>
 
 struct Process
  {
	int p_id,arrive,burst_time,priority,wait,status,copy_burst;
  }p[10];
 
  int count(int n)
   {
	 int i,cnt=0;
	 for (i=0;i<n;i++)
	  {
		cnt=cnt+p[i].burst_time;
	  }
	 return cnt;
   } 
  int minjob(int n,int ex_time)
   {
	 int i,min,pr;
	 min=10;
	 for (i=0;i<n;i++)
	  {
		if( (p[i].status!=1) && (p[i].priority<min) && (p[i].arrive<=ex_time))
	 	{
			min=p[i].copy_burst;
			pr=i;
	 	}
	  }
	  return pr;
   }
 
  void main()
   {
	 int i, n,cnt;
	 printf("\n\Enter no. of processes: ");
	 scanf("%d",&n);
	 for (i=0;i<n;i++)
	  {
		p[i].p_id=i;
		printf("\n enter information for process: %d",p[i].p_id);
	   	printf("\narrival time : ");
	   	scanf("%d",&p[i].arrive);
	 	printf("\n\nburst time : ");
	 	scanf("%d",&p[i].burst_time);
	 	printf("\npriority : ");
	 	scanf("%d",&p[i].priority);
	 	p[i].copy_burst=p[i].burst_time;
	 	p[i].status=0;
	 	p[i].wait=0;
	  }
	 cnt=count(n);
	 int j,min,pr;
	  for (i=0;i<cnt;i++)
	   {
		min=minjob(n,i);
		 p[min].copy_burst=p[min].copy_burst - 1;
		 for (j=0;j<n;j++)
	  	{
		 if( (min!=j) && (p[j].arrive<=i) && (p[j].status!=1) )
		   {
			 p[j].wait=p[j].wait+1;
		   }
	  	}
		 if(p[min].copy_burst==0)
		  {
			p[min].status=1;
		  }
	   }
	 printf("\n\n Process Id  Arrival Time    Burst Time  Priority   Waiting Time\n");
	 for (i=0;i<n;i++)
	  {
		printf("\n\t %d \t   %d    \t %d \t %d \t\t %d",p[i].p_id,p[i].arrive,p[i].burst_time,p[i].priority,p[i].wait);
	  }
	 float sum=0.0,sum2=0.0;
	 float ave, tat;
 
	 for (i=0;i<n;i++)
	  {
		sum=sum+p[i].wait;
		sum2+=p[i].wait+p[i].burst_time;
	  }
	 ave = sum/n;
	 tat=sum2/n;
	 printf("\n\n\n \t Average Waiting Time : %0.2f",ave);
	 printf("\n\n\n \t Average TurnAround Time : %0.2f",tat);
	 
   }
