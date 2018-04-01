#include<conio.h>
#include<stdio.h>
int arr[10],arr1[10],arr2[10],k=0,tot;
void distinct();
int remove1();
struct process
{
char name;
int arrive_t,burst_t,wait_t,turn_t,remain,prt;
int complete;
}prs[10];


int main()
{
int i,j,time=0,sum_bt=0,n,tq;
char c;
        float avg_wt=0;
        float avg_tt=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 prs[i].name=c;
 printf("Enter priority of process %c",prs[i].name);
 scanf("%d",&prs[i].prt);
 printf("\nEnter the arrival time and burst time of process %c: ",prs[i].name);
 scanf("%d%d",&prs[i].arrive_t,&prs[i].burst_t);
 prs[i].remain=prs[i].burst_t;
 prs[i].complete=0;
 sum_bt+=prs[i].burst_t;
 
}

printf("\nEnter the time quantum:");
scanf("%d",&tq);


}

