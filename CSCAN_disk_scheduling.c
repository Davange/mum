#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void scan(int arr[], int head, int n){
    int i, j, seek_time = 0, curr_pos, prev_pos;
    int left[n], right[n], left_size = 0, right_size = 0;
    for(i = 0; i < n; i++){
        if(arr[i] < head){
            left[left_size++] = arr[i];
        }
        else if(arr[i] > head){
            right[right_size++] = arr[i];
        }
    }
    sort(left, left_size);
    sort(right, right_size);
    printf("Sequence of head movement:\n");
    printf("%d -> ", head);
    if(right_size){
        for(i = 0; i < right_size; i++){
            curr_pos = right[i];
            printf("%d -> ", curr_pos);
            seek_time += abs(curr_pos - head);
            head = curr_pos;
        }
    }
    if(left_size){
        for(i = left_size-1; i >= 0; i--){
            curr_pos = left[i];
            printf("%d -> ", curr_pos);
            seek_time += abs(curr_pos - head);
            head = curr_pos;
        }
    }
    printf("End\n");
    printf("Total seek time = %d\n", seek_time);
}

int main(){
    int n, head, i;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the requests:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    scan(arr, head, n);
    return 0;
}
