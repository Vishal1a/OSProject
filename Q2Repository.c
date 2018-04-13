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
