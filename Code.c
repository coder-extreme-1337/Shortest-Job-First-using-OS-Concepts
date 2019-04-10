#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
sem_t semaphore;
int size;
pthread_mutex_t mutex;
pthread_mutex_t mutex1;
void main()
{
    int A[20],B[20],C[20],D[20] ,i ,j ,n  , total=0,pos,temp;
    float avg_C,avg_D;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&A[i]);
        B[i]=i+1;           
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[pos])
                pos=j;
        }
 
        temp=A[i];
        A[i]=A[pos];
        A[pos]=temp;
 
        temp=B[i];
        B [i]=B[pos];
        B [pos]=temp;
    }
 
    C[0] = 0;
    for(i=1;i<n;i++)
    {
        C[i]=0;
        for(j=0;j<i;j++)
            C[i]+=A[j];
 
        total+=C[i];
    }
  avg_C=(float)total/n;      
     total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        D[i]=A[i]+C[i];     //calculate turnaround time
        total+=D[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", B[i],A[i],C[i],D[i]);
    }

    avg_D=(float)total/n;     
    printf("\n\nAverage Waiting Time=%f",avg_C);
    printf("\nAverage Turnaround Time=%f\n",avg_D);
}

