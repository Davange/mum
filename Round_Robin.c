#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void main() {
    int n, quantum, i, j, time = 0, total_burst_time = 0, completed = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Read process data
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i+1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].pid = i+1;
        p[i].remaining_time = p[i].burst_time;
        total_burst_time += p[i].burst_time;
    }

    printf("Enter the quantum: ");
    scanf("%d", &quantum);

    while(completed < n) {
        for(i = 0; i < n; i++) {
            if(p[i].remaining_time > 0 && p[i].arrival_time <= time) {
                if(p[i].remaining_time <= quantum) {
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    completed++;
                    p[i].completion_time = time;
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    avg_turnaround_time += p[i].turnaround_time;
                    avg_waiting_time += p[i].waiting_time;
                } else {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                }
            }
        }
    }

    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print the table of process data and the averages
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
