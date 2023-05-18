/*The SCAN algorithm, also known as the elevator algorithm, is a disk scheduling algorithm used to decide the order in which read and write operations are performed on a hard disk drive.

In the SCAN algorithm, the disk arm starts at one end of the disk and moves towards the other end, servicing requests in its path. When it reaches the other end, it immediately returns to the starting end and starts servicing requests again. This movement is similar to an elevator moving up and down a building, hence the name "elevator algorithm".

The SCAN algorithm ensures that requests closer to the current position of the disk arm are serviced first, minimizing the average seek time and improving disk performance. However, it may result in some requests experiencing longer wait times if they are located in the opposite direction of the disk arm's movement.

Overall, the SCAN algorithm is a commonly used disk scheduling algorithm due to its effectiveness in reducing seek times and its simplicity to implement.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int queue[100], head, n, i, j, seek_time = 0, diff, max, temp, queue1[100], queue2[100], temp1 = 0, temp2 = 0;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    printf("Enter the queue: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (temp >= 0 && temp <= 199)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }

    // sort both queues
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }

    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // calculate seek time for the right direction
    for (i = 0; i < temp2; i++)
    {
        queue[n] = queue2[i];
        n++;
    }

    max = queue1[temp1 - 1];
    queue1[temp1] = head;
    for (i = 0; i < temp1 + 1; i++)
    {
        for (j = i; j < temp1 + 1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                diff = queue1[i] - queue1[j];
            }
            else
            {
                diff = queue1[j] - queue1[i];
            }
            seek_time += diff;
        }
    }

    // calculate seek time for the left direction
    seek_time += head - 0;
    head = 0;
    seek_time += max - queue2[0];

    for (i = 1; i < temp2; i++)
    {
        diff = queue[n - i] - head;
        seek_time += diff;
        head = queue[n - i];
    }

    printf("Total seek time: %d\n", seek_time);

    return 0;
}
