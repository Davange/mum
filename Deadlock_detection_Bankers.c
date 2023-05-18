#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_RESOURCE 10

int allocation[MAX_PROCESS][MAX_RESOURCE];
int request[MAX_PROCESS][MAX_RESOURCE];
int available[MAX_RESOURCE];
int marked[MAX_PROCESS];

int main()
{
    int n, m, i, j, k;

    // Get the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Get the allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Get the request matrix
    printf("Enter the request matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Get the available vector
    printf("Enter the available vector:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    // Initialize the marked array to false
    for (i = 0; i < n; i++) {
        marked[i] = 0;
    }

    // Check for deadlock
    int deadlock = 1;
    while (deadlock) {
        deadlock = 0;
        for (i = 0; i < n; i++) {
            if (marked[i] == 0) {
                int can_run = 1;
                for (j = 0; j < m; j++) {
                    if (request[i][j] > available[j]) {
                        can_run = 0;
                        break;
                    }
                }
                if (can_run) {
                    marked[i] = 1;
                    for (j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    deadlock = 1;
                }
            }
        }
    }

    // Print the processes in deadlock
    printf("Processes in deadlock:\n");
    for (i = 0; i < n; i++) {
        if (marked[i] == 0) {
            printf("Process %d\n", i);
        }
    }

    return 0;
}
