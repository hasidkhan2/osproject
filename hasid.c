#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
	int p_id, pri, b_t, a_t;
	struct Node* next;
};
// glboal variables to store address of front and rear nodes. 
struct Node* front1 = NULL;
struct Node* rear1 = NULL;
struct Node* front2 = NULL;
struct Node* rear2 = NULL;
struct Node* front3 = NULL;
struct Node* rear3 = NULL;

int fcfs()
{
    int n=0,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;

	struct Node* temp3 = front3;
	while(temp3 != NULL) {
		
		bt[n]=temp3->b_t;
		temp3 = temp3->next;
		
		n++;
	}
	
	 wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 
    return 0;
}

int prir()
 {

    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n=0,total=0,pos,temp,avg_wt,avg_tat;

	
		struct Node* temp2 = front2;
	while(temp2 != NULL) {
		
	
		bt[n]=temp2->b_t;
		pr[n]=temp2->pri;
		temp2 = temp2->next;
		p[n]=n+1;
	
		n++;
	}
 	
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
 
int rr() 
{ 
 	
	int count,j,n=0,time,remain,flag=0,time_quantum;
	int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
	struct Node* temp1 = front1;
	while(temp1 != NULL) 
	{
		bt[n]=temp1->b_t;
		at[n]=temp1->a_t;
		temp1 = temp1->next;
		rt[n]=bt[n];
		n++;
	}

	remain=n;

  	printf("Enter Time Quantum:\t"); 
  	scanf("%d",&time_quantum); 
  	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  	for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
void enq1(int x,int y,int z) {
	struct Node* temp1 = 
		(struct Node*)malloc(sizeof(struct Node));
	temp1->p_id =x;
	temp1->a_t=y;
	temp1->b_t=z;
	temp1->next = NULL;
	if(front1 == NULL && rear1 == NULL){
		front1 = rear1 = temp1;
		return;
	}
	rear1->next = temp1;
	rear1 = temp1;
	
}
void enq2(int x,int y,int z,int a) {
	struct Node* temp2 = 
		(struct Node*)malloc(sizeof(struct Node));
	temp2->p_id =x;
	temp2->pri =a;
	temp2->a_t=y;
	temp2->b_t=z; 
	temp2->next = NULL;
	if(front2 == NULL && rear2 == NULL){
		front2 = rear2 = temp2;
		return;
	}
	rear2->next = temp2;
	rear2 = temp2;
}
void enq3(int x, int y, int z) {
	struct Node* temp3 = 
		(struct Node*)malloc(sizeof(struct Node));
	temp3->p_id =x;
	temp3->a_t=y;
	temp3->b_t=z;
	temp3->next = NULL;
	if(front3 == NULL && rear3 == NULL){
		front3 = rear3 = temp3;
		return;
	}
	rear3->next = temp3;
	rear3 = temp3;
}

void print1() {
	struct Node* temp1 = front1;
	while(temp1 != NULL) {
		printf("p_id:: %d ",temp1->p_id);
			printf("at:: %d ",temp1->a_t);
			printf("bt:: %d ",temp1->b_t);
		temp1 = temp1->next;
	}
	printf("\n");
}
void print2() {
	struct Node* temp2 = front2;
	while(temp2 != NULL) {
		printf("p_id::%d ",temp2->p_id);
		printf("pri:: %d ",temp2->pri);
			printf("at:: %d ",temp2->a_t);
			printf("bt:: %d ",temp2->b_t);
		temp2 = temp2->next;
	}
	printf("\n");
}
void print3() {
	struct Node* temp3 = front3;
	while(temp3 != NULL) {
	printf("p_id:: %d ",temp3->p_id);
			printf("at:: %d ",temp3->a_t);
			printf("bt:: %d ",temp3->b_t);
		temp3 = temp3->next;
	}
	printf("\n");
}

int main(){
	int i,n,p,at,bt,pp;
	printf("Enter number of process::");
	scanf("%d",&n);
	for(i=0;i<n;i++){
flag:		printf("Enter the priority of the process for Queue:1,2,3:");
		scanf("%d",&p);
		switch(p){
			case 3: {
				printf("Enter Arrival Time:");
				scanf("%d",&at);
				printf("Enter Burst Time:");
				scanf("%d",&bt);
				enq3(i,at,bt);
				break;
			}
			case 2: {
				printf("Enter Arrival Time:");
				scanf("%d",&at);
				printf("Enter Burst Time:");
				scanf("%d",&bt);
				printf("Enter Priority:");
				scanf("%d",&pp);
				enq2(i,pp,at,bt);
				break;
			}
			case 1: {
				printf("Enter Arrival Time:");
				scanf("%d",&at);
				printf("Enter Burst Time:");
				scanf("%d",&bt);
				enq1(i,at,bt);
				break;
			}
			default:{
				printf("Wrong Choice");
				goto flag;
			}
	}		
	}
fcfs();
prir();
rr();
}
