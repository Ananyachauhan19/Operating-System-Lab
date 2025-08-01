#include<stdio.h>
#include<stdlib.h>
typedef struct details{
    int p_id;
    int arrival_time;
    int burst_time;
    int starting_time;
    int completion_time;
    float turn_around_time;
    float waiting_time;
    int response_time;
}process;

int compare(const void *p1, const void *p2){
    int a = ((process *)p1)->arrival_time;
    int b = ((process *)p2)->arrival_time;

    if(a<b) return -1;
    else return 1;

}

int main(){
    int n;
    printf("Enter number of processes : ");
    scanf("%d", &n);

    float swt=0, stat=0, cu=0, throughput=0, atat=0, awt=0, art=0;
    int sbt=0;

    process p[n];
    for(int i=0; i<n; i++){
        p[i].p_id = i+1;
        printf("Enter the arrival time and burst time of process %d : ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    qsort((void *)p, n, sizeof(process), compare);

    for(int i=0; i<n; i++){

        if(i==0){
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        }
        else if(p[i-1].completion_time <= p[i].arrival_time){
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
        }
        else{
            p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
        }

        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;

        sbt += p[i].burst_time;
        swt += p[i].waiting_time;
        stat += p[i].turn_around_time;
        p[i].response_time = p[i].waiting_time;

    }

    awt = swt/n;
    atat = stat/n;
    float max;

    for(int i=0; i<n; i++){
        p[i].starting_time = p[i].arrival_time;
        max = 0;
        if(p[i].completion_time > max){
            max = p[i].completion_time;
        }
    }

    cu = (sbt/max)*100;
    throughput = n/max;

    printf("\nPID\tArrivalTime\tBurstTime\tStartingTime\tCompletionTime\tTurnAroundTime\tWaitingTime\tResponseTime\n");
    for(int i=0; i<n; i++){
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t%.2f\t\t%d\n",p[i].p_id,p[i].arrival_time,p[i].burst_time,p[i].starting_time,p[i].completion_time,p[i].turn_around_time,p[i].waiting_time,p[i].response_time);
        
    }
    printf("\nSum of Turn Around Time : %.2f\nAverage of Turn Around Time : %f\n",stat,atat);
        printf("Sum of Waiting Time : %.2f\nAverage of Waiting time : %f\n", swt, awt);
        printf("\nCPU Utilization : %.2f\nThroughput : %.2f\n",cu, throughput);
return 0;
}