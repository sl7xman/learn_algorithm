#include <stdio.h>

void show_array(int arr[], int n){
    int i =0;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);    
    }    
    printf("\n");
}

void bubble_int(int arr[] , int n){
    int i,j=0;
    for( i=n; i>1; i--){
        for ( j=0; j<i-1; j++){
            if ( arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=tmp;
            }    
        }    
        show_array(arr, n);
    }
}

void bubble_int_optimal(int arr[], int n){
    int is_swap = 0;
    int i,j=0;
    for (i=n; i>1; i--){
        is_swap =0;
        for( j=0; j<i-1; j++){
            if(arr[j]> arr[j+1]){
                is_swap = 1;
                int tmp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=tmp;    
            }
        }
            
        if( is_swap == 0){
            return;
        }

        show_array(arr, n);
    }    
}

void bubble_int_standard(int arr[], int n){
    int is_swap =0;
    int i,j =0;
    for (i=0;i<n;i++){
        is_swap=0;
        for (j=0; j<n-i-1; j++){
            if( arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                is_swap = 1;    
            }    
        }    
        if( is_swap == 0){
            break;    
        }
    }    
}

int main(void){
    int arr[]={4,5,6,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("before sort: ");
    show_array(arr, n);
    printf("sort record:\n");
    bubble_int(arr, n);
    printf("after sort:");
    show_array(arr, n);

    int arr_opt[]={3,5,4,1,2,6};
    n=sizeof(arr_opt)/sizeof(arr_opt[0]);
    printf("before opt sort:");
    show_array(arr_opt, n);
    printf("opt sort record:\n");
    bubble_int_optimal(arr_opt, n);
    printf("afeter opt sort:");
    show_array(arr_opt, n);

    int arr_standard[]={3,5,4,1,2,6};
    n=sizeof(arr_standard)/sizeof(arr_standard[0]);
    printf("before standard sort:");
    show_array(arr_standard, n);
    printf("standard sort record:\n");
    bubble_int_optimal(arr_standard, n);
    printf("afeter standard sort:");
    show_array(arr_standard, n);
    return 0;    
}
