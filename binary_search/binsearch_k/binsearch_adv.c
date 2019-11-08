#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int find_first_element(int arr[], int n, int elm){
    int low = 0;
    int high = n-1;
    
    while( low <=high){
        int mid = low + ((high - low)>>1);
        if( arr[mid] == elm){
            int first = mid;
            while( mid>low){
                mid--;
                printf("%d\n", mid);
                if( arr[mid]== elm){
                    first = mid;
                }
            }
            return first;  
        }    

        if( arr[mid] < elm ){
            low = mid+1;  
        }else{
            high = mid-1;
        }
    }

    return -1;    
}

int find_last_element(int arr[], int n, int elm){
    int low = 0;
    int high = n-1;
    
    while( low <=high){
        int mid = low + ((high - low)>>1);
        if( arr[mid] == elm){
            int last = mid;
            while( mid<high){
                mid++;
                printf("%d\n", mid);
                if( arr[mid]== elm){
                    last = mid;
                }
            }
            return last;  
        }    

        if( arr[mid] < elm ){
            low = mid+1;  
        }else{
            high = mid-1;
        }
    }

    return -1;    
}

int find_first_great_element(int arr[], int n, int elm){
    int low = 0;
    int high = n-1;
    
    while( low <=high){
        int mid = low + ((high - low)>>1);
        if( arr[mid] == elm){
            int last = mid;
            while( mid<high){
                mid++;
                printf("%d\n", mid);
                if( arr[mid]== elm){
                    last = mid;
                }
            }
            return last;  
        }    

        if( arr[mid] < elm ){
            low = mid+1;  
        }else{
            high = mid-1;
        }
    }
    printf("low=%d %d high=%d %d\n", low, arr[low], high, arr[high]);
    return low;
}

int find_last_small_element(int arr[], int n, int elm){
    int low = 0;
    int high = n-1;
    
    while( low <=high){
        int mid = low + ((high - low)>>1);
        if( arr[mid] == elm){
            int last = mid;
            while( mid<high){
                mid++;
                printf("%d\n", mid);
                if( arr[mid]== elm){
                    last = mid;
                }
            }
            return last;  
        }    

        if( arr[mid] < elm ){
            low = mid+1;  
        }else{
            high = mid-1;
        }
    }
    printf("low=%d %d high=%d %d\n", low, arr[low], high, arr[high]);
    return high;
}
int main(){
    int arr[]={1,3,5,7,9,11,11,11,11,14,16,18,20,22,24,25,29,29,29,29,29,29,29,29,29,29,29,29,33,47,59,69};

    int n = sizeof(arr)/ sizeof( arr[0]);
    int r = find_last_small_element(arr, n, -2);
    printf("find: %d %d\n",r,  arr[r]);
    return 0;    
}
