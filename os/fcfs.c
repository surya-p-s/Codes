#include<stdio.h>
//  First come first serve (FCFS) Week 1
int main()
{
	float bt[10],at[10],wt=0,tt=0,awt,att,gnct[10],flag1,flag2; 
	int p[10],i,j,n,gncp[10],temp;
	printf("Enter no of Process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("Enter Burst Time and Arrival Time of Process %d :",i);
		scanf("%f%f",&bt[i],&at[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(at[j]>at[j+1])
			{
				flag1=at[j];
				at[j]=at[j+1];
				at[j+1]=flag1;				
				flag2=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=flag2;				
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	flag1=0;
	for(i=0;i<n;i++)
	{
		gncp[i]=p[i];
		flag1=flag1+bt[i];
		gnct[i]=flag1;
		tt=tt+(gnct[i]-at[i]);
		if(i!=0)
		wt=wt+(gnct[i-1]-at[i]);	
	}
	awt=wt/(float)n;
	att=tt/(float)n;
	printf("\nThe gnatt chart is:\nProcess\t\tTime\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",gncp[i]);
		printf("%f\n",gnct[i]);
	
	}
	printf("\nThe Average Waiting Time is %f",awt);
	printf("\n The Average Turnaround Time is %f",att);
    return 0;
}
