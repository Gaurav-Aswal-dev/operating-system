#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("number of n");
    scanf("%d",&n);
    int at[n],bt[n],rt[n];
    int ct[n],tat[n],wt[n];
    for(int i=0;i<n;i++){
        printf("enter arrival time and burst time for p%d",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }
    int completed  = 0;
    int time  = 0;
    while(completed<n){
        int shortest = -1;
        int minRT = INT_MAX;
        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                    if(rt[i]<minRT){
                    minRT = rt[i];
                    shortest = i;
                }
            }
        }
        if(shortest ==-1){
            time++;
            continue;
        }
        rt[shortest--];
        time++;
        if(rt[shortest]==0){
            completed++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest]-at[shortest];
            wt[shortest] = tat[shortest]-bt[shortest];
        }
    }
     printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);
    }

    return 0;
  
}