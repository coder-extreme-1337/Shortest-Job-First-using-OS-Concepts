#include<stdio.h>
 
int main()
{
    int burst_time[20],B[20],C[20],D[20] ,i ,j ,size,total=0,pos,temp;
    float avg_C,avg_D;
    printf("Enter number of process:");
    scanf("%d",&size);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<size;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        B[i]=i+1;           
    }

    for(i=0;i<size;i++)
    {
        pos=i;
        for(j=i+1;j<size;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp=burst_time[i];
        B[i]=B[pos];
        B[pos]=temp;
    }
 
    C[0] = 0;
    for(i=1;i<size;i++)
    {
        C[i]=0;
        for(j=0;j<i;j++)
            C[i]+=burst_time[j];
 
        total+=C[i];
    }
  avg_C=(float)total/size;      
     total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<size;i++)
    {
        D[i]=burst_time[i]+C[i];     //calculate turnaround time
        total+=D[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", B[i],burst_time[i],C[i],D[i]);
    }
 
    avg_D=(float)total/size;     
    printf("\n\nAverage Waiting Time=%f",avg_C);
    printf("\nAverage Turnaround Time=%f\n",avg_D);
    return 0;
}
