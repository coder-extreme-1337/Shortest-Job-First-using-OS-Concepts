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
   int i ,j  , time=0,time1=0,position,temp,*ptr;
    float average_waiting_time,average_turnaround_time;
    printf("Enter number of process:  ");
    scanf("%d",&size);
    ptr=&size;
    int burst_time[*ptr],arrival_time[*ptr],sequence[*ptr],completion_time[*ptr],turning_time[*ptr];
    for(i=0;i<size;i++)
    {
        printf("Enter Arrival Time of P%d : ",i+1);
        scanf("%d",&arrival_time[i]);
        sequence[i]=i+1;  
	        
    }
    for(i=0;i<size;i++)
    {
        printf("Enter Burst Time of P%d : ",i+1);
        scanf("%d",&burst_time[i]);          
    }
    for(i=0;i<size;i++)
    {
        position=i;
        for(j=i+1;j<size;j++)
        {
            if(burst_time[j]<burst_time[position])
                position=j;
        }
 
        temp=burst_time[i];
        burst_time[i]=burst_time[position];
    	burst_time[position]=temp;
 
        temp=sequence[i];
        sequence[i]=sequence[position];
        sequence[position]=temp;
    }
 
    completion_time[0] = 0;
    for(i=1;i<size;i++)
    {
        completion_time[i]=0;
        for(j=0;j<i;j++)
            completion_time[i]+=burst_time[j];
 
        time+=completion_time[i];
    }
  	average_waiting_time=(float)time/size;      
     time1=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<size;i++)
    {
        turning_time[i]=burst_time[i]+completion_time[i];     //calculate turnaround time
        time1+=turning_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", sequence[i],burst_time[i],completion_time[i],turning_time[i]);
    }
 
    average_turnaround_time=(float)time1/size;     
    printf("\n\nAverage Waiting Time=%f",average_waiting_time);
    printf("\nAverage Turnaround Time=%f\n",average_turnaround_time);
}

