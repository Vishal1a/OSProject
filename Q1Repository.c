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
				printf("%d ", d[i].burst);
			}
		fclose(f);
}
