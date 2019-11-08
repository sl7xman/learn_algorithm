#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binsearch( int arr[], int low, int high, int mem){
    if( high <low){
        return -1;    
    }

    int mid = low + ((high-low)>>1);
    if( mem == arr[mid]){
        return mid;
    }
    if(mem > arr[mid]){
        return binsearch(arr, mid+1,high, mem);
    }else{
        return binsearch(arr, low, mid-1, mem);    
    }
}

int binsearch_no(int arr[], int n, int mem){
    int low = 0; 
    int high = n-1;

    while( low <= high){
        int mid = low + ((high-low)>>1); 
        if( arr[mid] == mem){
            return mid;    
        }
        if( arr[mid]> mem){
            high = mid-1;    
        }else{
            low = mid+1;
        }
    }

    return -1;
}

int main(){

    int arr[]={1,7,9, 11, 23, 26,33,35,37,47,59};
    int n = sizeof(arr)/sizeof(arr[0]);

    int r = binsearch(arr, 0, n-1, 23);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch(arr, 0, n-1, 47);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch(arr, 0, n-1, 26);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch(arr, 0, n-1, 27);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch(arr, 0, n-1, 2);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch(arr, 0, n-1, 1);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch(arr, 0, n-1, 59);
    printf("find: %d %d\n", r , arr[r]);

    printf("---------------------------------\n");
    r = binsearch_no(arr,  n, 23);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch_no(arr, n, 47);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch_no(arr,  n, 26);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch_no(arr,  n, 27);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch_no(arr,  n, 2);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch_no(arr,  n, 1);
    printf("find: %d %d\n", r , arr[r]);
    r = binsearch_no(arr,  n, 59);
    printf("find: %d %d\n", r , arr[r]);
    return 0;    
}
