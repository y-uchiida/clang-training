#include <stdio.h>

void max_min(int *arr, int *max, int *min);

int main(void){

    int i, nums[10], max, min;
    i = 0;
    while(i < 10){
        scanf("%d", &nums[i]);
        if(nums[i] <= -1){
            break;
        }
        i++;
    }

    max = 0;
    min = 100;
    max_min(nums, &max, &min);
    printf("max: %d\n", max);
    printf("min: %d\n", min);

    return 0;
}

void max_min(int *arr, int *max, int *min){
    int i;
    i = 0;
    while(i < 10){
        if(arr[i] <= -1){
            break;
        }
        if(arr[i] >= *max){
            *max = arr[i];
        }
        if(arr[i] <= *min){
            *min = arr[i];
        }
        i++;
    }
}