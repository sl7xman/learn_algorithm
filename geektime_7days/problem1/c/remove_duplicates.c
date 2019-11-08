#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){

    if( numsSize == 0){
        return 0;
    }

    int i = 0;
    int cur_val = nums[0];
    int next_idx = 1;
    for ( i = 1; i < numsSize; i++){
        if( nums[i] != cur_val){
            nums[next_idx]=nums[i];
            cur_val = nums[i];
            ++next_idx;
        }
    }
    return next_idx;
}

int removeDuplicates_2p(int* nums, int numsSize){
    if( numsSize == 0){
        return 0;
    }

    int slow_idx = 0;
    int i = 0;
    for ( i = 1; i<numsSize; i++){
        if( nums[slow_idx] != nums[i]){
            nums[++slow_idx]=nums[i];
        }
    }
    return slow_idx+1;
}

void showArray(int* nums, int numsSize){
    int i = 0;
    for ( i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);    
    }     
    printf("\n");
}

int main(void){
    int nums[]={1,1,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int newSize = removeDuplicates(nums, numsSize);
    showArray(nums, newSize);
}

