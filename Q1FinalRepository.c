#include<stdio.h>
struct data
{
	int burst;
}d[50];

main()
	{
		FILE *f;
		int i, n=11;	
		f=fopen("CPU_BRUST.txt","r");
		for(i=0;i<n;i++)
			{
				fscanf(f,"%d",&d[i].burst);	
			}
		fclose(f);
	int  wTime=0, tAT=0;
	int j, temp;
	float aWT,_aWT=0,aTAT,_aTAT=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(d[i].burst< d[j].burst)
			{
			  temp = d[i].burst;
			  d[i].burst = d[j].burst;
			  d[j].burst = temp;	
			}
		}
	}
	printf("\nPid\t\tBT\t\tWT\t\tTAT");
	for(i=0; i<n; i++)
	{
		tAT=d[i].burst+wTime;
		printf("\n%d \t\t %d \t\t %d \t\t %d",i+1, d[i].burst, wTime, tAT);
		_aWT +=wTime;
		_aTAT +=tAT;
		wTime +=d[i].burst;
	}
	aWT=_aWT/n;
	aTAT=_aTAT/n;
	printf("\nAverage waiting time :%f",aWT);
	printf("\nAverage turn around time : %f",aTAT);
    getch();
}
