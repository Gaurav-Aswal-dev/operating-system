#include<stdio.h>
int main(){
    int n,quant;
    printf("enter n:");
    scanf("%d",&n);
    char id[10][5];
    int arrival[10],burst[10],remain[10];
      for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("  ID: ");
        scanf("%s", id[i]);
        printf("  Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("  Burst Time: ");
        scanf("%d", &burst[i]);
        remain[i] = burst[i]; 
    }
     printf("\nQuantum: ");
    scanf("%d", &quant);
    //===========FCFS==========
    int time =0;
    for(int i=0;i<n;i++){
        if(time<arrival[i])
        time = arrival[i];
        time+=burst[i];
        printf("%s",id[i]);
    }
    printf("\n");
    //========roundrobin=======
    int queue[100];
    int front = 0,rear =0;
    int i =0;
    time = 0;
    while(i<n && arrival[i]<=time){
        queue[rear++] = i;
        i++;
    }
    
    printf("RR%d Completion Order: ", quant);
    while(front<rear){
        int idx = queue[front++];
        int run_time = (remain[idx]<quant)? remain[idx]:quant;
        time+=run_time;
        remain[idx]-=run_time;
        while(i<n&&arrival[i]<=time){
            queue[rear++] = i;
            i++;
        }
        if(remain[idx] == 0){
            printf("%s",id[idx]);
        }else{
            queue[rear++] = idx;
        }
    }
    printf("\n");
    return 0;
}