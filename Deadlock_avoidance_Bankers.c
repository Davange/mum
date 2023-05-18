#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_RESOURCE 10

int allocation[MAX_PROCESS][MAX_RESOURCE];
int max[MAX_PROCESS][MAX_RESOURCE];
int available[MAX_RESOURCE];
int need[MAX_PROCESS][MAX_RESOURCE];
int completed[MAX_PROCESS];

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

    // Get the max matrix
    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Get the available vector
    printf("Enter the available vector:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    // Initialize the completed array to false
    for (i = 0; i < n; i++) {
        completed[i] = 0;
    }

    // Run the banker's algorithm
    int safe_sequence[n];
    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (completed[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }
                if (j == m) {
                    // Process i can be allocated resources
                    int k;
                    for (k = 0; k < m; k++) {
                        available[k] += allocation[i][k];
                    }
                    completed[i] = 1;
                    safe_sequence[count] = i;
                    count++;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            // No safe sequence exists
            printf("No safe sequence exists.\n");
            return 0;
        }
    }

    // Print the safe sequence
    printf("Safe sequence: ");
    for (i = 0; i < n; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");

    return 0;
}
