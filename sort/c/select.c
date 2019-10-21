#include <stdio.h>

void show_array(int arr[], int n){
    int i =0;
    for(i=0;i<n; i++){
        printf("%d ", arr[i]);    
    }
    printf("\n");
}

void sort_int(int arr[], int n){
    int i, j=0;

    for(i =0; i< n; i++){
        int midx = i;
        int mini=arr[i];
        for(j=i+1; j<n; j++){
            if(arr[j] < mini){
                mini=arr[j];
                midx=j;    
            }
        }    
        arr[midx]=arr[i];
        arr[i]=mini;
    }
}

int main(){
    int arr[]={4,5,6,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("before sort:");
    show_array(arr, n);
    sort_int(arr, n);
    printf("afeter sort:");
    show_array(arr, n);
}
