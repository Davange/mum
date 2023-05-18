#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, head, i, seek_time=0, cur_track;
    printf("Enter the number of disk requests: ");
    scanf("%d",&n);
    int requests[n];
    printf("Enter the requests: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d",&head);

    cur_track = head;

    for(i=0; i<n; i++)
    {
        seek_time += abs(cur_track - requests[i]);
        cur_track = requests[i];
    }

    printf("\nTotal Seek Time: %d",seek_time);
    printf("\nAverage Seek Time: %f\n",(float)seek_time/n);

    return 0;
}
