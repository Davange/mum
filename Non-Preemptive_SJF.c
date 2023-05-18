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
    int n, i, j, time = 0, total_burst_time = 0, completed = 0;
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

    // Sort the processes by arrival time
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    while(completed < n) {
        int shortest_job = -1;
        int shortest_time = total_burst_time + 1;

        // Find the process with shortest burst time
        for(i = 0; i < n; i++) {
            if(p[i].remaining_time > 0 && p[i].arrival_time <= time && p[i].burst_time < shortest_time) {
                shortest_time = p[i].burst_time;
                shortest_job = i;
            }
        }

        if(shortest_job == -1) {
            time++;
        } else {
            p[shortest_job].remaining_time--;
            time++;

            if(p[shortest_job].remaining_time == 0) {
                completed++;
                p[shortest_job].completion_time = time;
                p[shortest_job].turnaround_time = p[shortest_job].completion_time - p[shortest_job].arrival_time;
                p[shortest_job].waiting_time = p[shortest_job].turnaround_time - p[shortest_job].burst_time;
                avg_turnaround_time += p[shortest_job].turnaround_time;
                avg_waiting_time += p[shortest_job].waiting_time;
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
