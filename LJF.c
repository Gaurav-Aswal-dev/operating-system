#include<stdio.h>
int main(){
    int n;
    printf("enter n");
    scanf("%d",&n);
    int bt[n],wt[n],tat[n],p[n];
    for(int i=0;i<n;i++){
        p[i] = i+1;
        printf("enter burst time of p%d:",i+1);
        scanf("%d",bt[i]);
    } 
    for(int i=0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(bt[i]<bt[j]){
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1]+bt[i-1];

    }
    for(int i=0;i<n;i++){
        tat[i] = wt[i]+bt[i];
    }

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}