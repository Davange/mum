#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int remaining_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void main() {
    int n, i, j, time = 0, total_burst_time = 0, completed = 0, current = -1;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Read process data
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority for Process %d: ", i+1);
        scanf("%d %d %d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
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
        int highest_priority = -1;
        int index = -1;

        // Find the process with highest priority
        for(i = 0; i < n; i++) {
            if(p[i].remaining_time > 0 && p[i].arrival_time <= time && p[i].priority > highest_priority) {
                highest_priority = p[i].priority;
                index = i;
            }
        }

        if(index == -1) {
            time++;
        } else {
            if(current != index) {
                printf("Process %d started execution at time %d\n", p[index].pid, time);
            }

            p[index].remaining_time--;
            time++;

            if(p[index].remaining_time == 0) {
                completed++;
                p[index].completion_time = time;
                p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
                p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
                avg_turnaround_time += p[index].turnaround_time;
                avg_waiting_time += p[index].waiting_time;
                printf("Process %d completed execution at time %d\n", p[index].pid, time);
                current = -1;
            } else {
                current = index;
            }
        }
    }

    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print the table of process data and the averages
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}
