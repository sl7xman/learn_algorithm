#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void rotate(int* nums, int numsSize, int k){
    if (numsSize<=0 || k <=0){
        return;
    }
    
    int actual_k = k%numsSize;
    if (actual_k == 0){
        return ;
    }
    
    int i = 0;
    int j = 0;
    int n = numsSize-1;
    
    int tmp_nums[actual_k];
    for( i = 0; i < actual_k; ++i){
        tmp_nums[i] = nums[numsSize - actual_k +i];    
    }
    
    for ( i = 0; i < actual_k; ++i){
        int tmp = nums[n];
        
        j=n;
        while( j >= 0 ){
            if( j - actual_k >=0){
                nums[ j ] = nums[ j - actual_k ];
            }
            j -= actual_k;
        }
        
        --n;
    }
    
    for ( i = 0; i< actual_k; ++i ) {
        nums[i] = tmp_nums[i];
    }
}

void show_array(int* nums, int numsSize) {
    int i =0;
    for( i = 0; i < numsSize; ++i ) {
        printf("%d ", nums[i]);    
    }    
    printf("\n");
}

int main(){
    int nums[] = {1,2,3,4,5,6,7};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 3;
    rotate(nums, n, k);
    show_array(nums, n);
    return 0;    
}
