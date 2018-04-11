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
int n;
int que[10];  
int front=-1,rear=-1;
void insert(int i)
{
if(rear==100)
printf("overflow");
rear++;
que[rear]=i;
if(front==-1)
front=0;

}


int remove1()
{
if(front==-1)
printf("underflow");
int temp=que[front];
if(front==rear)
front=rear=-1;
else
front++;
return temp;
}
int arrived(int i)
{int k;
for(k=front;k<=rear;k++)
{
if(que[k]==i)
return 1;
}
return 0;

}void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
if(prs[i].arrive_t>prs[j].arrive_t)
{
temp=prs[i];
prs[i]=prs[j];
prs[j]=temp;
}
}
}

void sortByPriority()
{
struct process temp;
int i,j;
	for(i=1;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
		if(prs[i].prt<prs[j].prt)
		{
			temp=prs[i];
			prs[i]=prs[j];
			prs[j]=temp;
		}
	}	
	}
}

void arrived_sort()
{
	int i,j;
	for(i=0;arr[i]!='\0';i++)
	{
		for(j=i+1;arr[j]!='\0';j++)
		{
			if(arr[i]<arr[j])
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=arr[i];
			}
		}
	}
}

void arrange()
{
	int i,j;
	
	for(i=0;arr[i]!='\0';i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i]==prs[j].prt)
			{
				arr1[i]=j;
			}
		}
	}
}

void distinct()
{
	int i,j;
	for(i=0;arr[i]!='\0';i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]==arr[j])
			{
			goto B;
			}
		}
		B:
		if(i==j)
		{
			arr2[i]=arr[j];
		}
	}
}

void age()
{
	int i,z;
	if(tot>0 && tot%2==0)
	{
		for(z=0;z<n;z++)
		{
			if(prs[i].prt==arr1[z])
			{
				prs[i].prt+1;
			}
		}
	}
}

int main()
{
int i,j,time=0,sum_bt=0,tq;
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
sortByArrival();
insert(0);          
for(time=prs[0].arrive_t;time<sum_bt;)
{   i=remove1();

if(prs[i].remain<=tq)
{                          
                       
time+=prs[i].remain;
prs[i].remain=0;
prs[i].complete=1;          
            prs[i].wait_t=time-prs[i].arrive_t-prs[i].burst_t;
            prs[i].turn_t=time-prs[i].arrive_t;       
            for(j=0;j<n;j++)                
            {
            if(prs[j].arrive_t<=time && prs[j].complete!=1&& arrived(j)!=1)
            {
            	arr[k]=prs[j].prt;
            	k++;
            }
           }
           arrived_sort();
           arrange();
           for(k=0;arr1[k]!='\0';k++)
           {
           	insert(arr1[k]);
		   }
		   
        }
    else            
    {
    time+=tq;
    prs[i].remain-=tq;
    for(j=0;j<n;j++)    
            {
            if(prs[j].arrive_t<=time && prs[j].complete!=1 && i!=j &&arrived(j)!=1)
             {
             	
             	arr[k]=prs[j].prt;
            	k++;
            }
           }
           arrived_sort();
           arrange();
           for(k=0;arr1[k]!='\0';k++)
           {
           	insert(arr1[k]);
		   }
           insert(i);       
    }   
}
printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
for(i=0;i<n;i++)
{avg_wt+=prs[i].wait_t;
avg_tt+=prs[i].turn_t;
printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d",prs[i].name,prs[i].arrive_t,prs[i].burst_t,prs[i].wait_t,prs[i].turn_t);
}
printf("\nAverage waiting time:%f\n",avg_wt/n);
printf("\nAverage waiting time:%f\n",avg_tt/n);
}

