//Shortest Seek time first

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int abs(int x){
    if(x<0) return -x;
    else return x;
}
void sstf(int arr[], int head, int size){
    int visited[size], ans[size], seek=0, current=head;
    for(int i=0;i<size;i++){
        visited[i]=0;
    }
    for(int i=0;i<size;i++){
        int min=INT_MAX, index=-1;
        for(int j=0;j<size;j++){
            if(!visited[j] && abs(arr[j]-current)<min){
                min=abs(arr[j]-current);
                index=j;
            }
        }
        visited[index]=1;
        ans[i]=arr[index];
        current=arr[index];
        seek+=min;
    }
    printf("Seek Time: %d\n",seek);
    printf("Sequence: ");
    for(int i=0;i<size;i++){
        printf("%d ",ans[i]);
    }
}
int main(){
    int n, head;
    printf("Enter the size of the queue: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the queue:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    sstf(arr, head, n);
    return 0;
}
