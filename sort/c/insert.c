#include <stdio.h>

void show_array(int arr[], int n){
    int i =0;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);    
    }    
    printf("\n");
}

int insert_int(int arr[], int n){
    int i,j,k=0;
    
    for (i=1; i<n ; i++){
        for(j=0; j<i; j++){
            if (arr[j] > arr[i]){
                int ti = arr[i];
                for (k=i;k>j; k--){
                    arr[k]= arr[k-1];
                }       
                arr[j]=ti;
            }
        }
    }    
}

int insert_int_standard( int arr[], int n){
    int i,j =0;
    for(i =1; i<n; i++){
        int ti = arr[i];
        j=i-1;
        for ( ; j>=0; j--){
            if( arr[j]> ti){
                arr[j+1]=arr[j];  
            }else{
                break;
            }
        }    
        arr[j+1]=ti;
    }    
}

int main(void){
    int arr[]={4,5,6,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("before sort:");
    show_array(arr, n);
    insert_int_standard(arr, n);
    printf("after sort:");
    show_array(arr, n);
    return 0;    
}
