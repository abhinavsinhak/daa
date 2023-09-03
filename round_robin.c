#include<stdio.h>
#include<stdlib.h>

//struct process to store process information

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int priority;
    int flag;
};
//round robin function
void round_robin(struct process p[],int n,int tq)
{
    int i,j,time=0,sum_bt=0;
    int remain=n;
    int flag=0;
    int wait_time=0,turnaround_time=0;
    for(i=0;i<n;i++)
    {
        p[i].remaining_time=p[i].burst_time;
    }
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(time=0,i=0;remain!=0;)
    {
        if(p[i].remaining_time<=tq && p[i].remaining_time>0)
        {
            time+=p[i].remaining_time;
            p[i].remaining_time=0;
            flag=1;
        }
        else if(p[i].remaining_time>tq)
        {
            p[i].remaining_time-=tq;
            time+=tq;
        }
        if(p[i].remaining_time==0 && flag==1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n",p[i].pid,time-p[i].arrival_time,time-p[i].arrival_time-p[i].burst_time);
            wait_time+=time-p[i].arrival_time-p[i].burst_time;
            turnaround_time+=time-p[i].arrival_time;
            flag=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(p[i+1].arrival_time<=time)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    printf("\nAverage waiting time = %f\n",wait_time*1.0/n);
    printf("Average Turnaround time = %f\n",turnaround_time*1.0/n);
}
//main function
int main()
{
    int i,j,n,tq;
    struct process p[100],temp;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of process %d: ",i+1);
        scanf("%d",&p[i].arrival_time);
        printf("Enter the burst time of process %d: ",i+1);
        scanf("%d",&p[i].burst_time);
        p[i].pid=i+1;
    }
    round_robin(p,n,tq);
    return 0;
}