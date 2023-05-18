#include<stdio.h>

struct process{
    int pid;
    int burst_time;
    int priority;
};

void main() {
    int n, i, j;
    struct process p[20], temp;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Read process data
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for Process %d: ", i+1);
        scanf("%d %d", &p[i].burst_time, &p[i].priority);
        p[i].pid = i+1;
    }

    // Sort the processes by priority
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i].priority < p[j].priority) 
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int completion_time[n], turnaround_time[n], waiting_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Calculate completion, turnaround and waiting times for each process
    for(i = 0; i < n; i++) {
        completion_time[i] = p[i].burst_time + (i == 0 ? 0 : completion_time[i-1]);
        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - p[i].burst_time;
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Print the table of process data and the averages
    printf("\nPID\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    avg_waiting_time = total_waiting_time / n;
    avg_turnaround_time = total_turnaround_time / n;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
