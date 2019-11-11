#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int maxW = 0;
void dynamic_programming_recall ( int i, int cw, int arr[], int n, int w, int states[][9] ) {
    if ( cw == w || i == n ){
        if ( cw > maxW ) {
            maxW = cw;
        }
        return;
    }

    if ( states[i][cw] ){
        return;    
    }
    
    states[i][cw] = 1;
    dynamic_programming_recall ( i+1, cw, arr, n, w, states );

    if ( cw + arr[i+1] <= w ) {
        dynamic_programming_recall (i+1, cw + arr[i+1], arr, n, w, states );    
    }
}

void dynamic_programming1( int arr[], int n, int w, int states[10]) {

    states[0] = 1;
    int i = 0;
    states[arr[0]] = 1;    

    for ( i = 0; i < n; ++i ) {
        if ( arr[i] <= w ) {
            states[arr[i]] = 1;    
        }    
    }
    int j = 0;

    for ( i = 1; i < n; ++i ) {
        for ( j = 0; j < w+1; ++j ) {
            printf("i=%d j=%d\n", i, j);
            if ( states[j] == 1 ) {
                if ( j + arr[i] <= w ) {
                    states[j+arr[i]] = 1;    
                }
            }    
        }    
    }

    for ( j = 0; j < w; ++j ) {
        printf("%d ", states[j]);
    }
    printf("\n");

    for ( j = w; j >= 0; --j ) {
        if ( states[j] ) {
            maxW = j;
            return;    
        }    
    }    
}

void dynamic_programming( int arr[], int n, int w, int states[][10]) {

    states[0][0] = 1;
    int i = 0;
    states[0][arr[0]] = 1;    

    int j = 0;
    for ( i = 1; i < n; ++i ) {
        for ( j = 0; j < w ; ++j ) {
            if ( states[i-1][j] == 1 ) {
                states[i][j] = 1;//不考虑新物品
                if( j + arr[i] <= w ) {//考虑新物品
                    states[i][j+arr[i]] = 1;    
                }
            }
        }    
    }
    for ( i = 0; i < n; ++i ) {
        for ( j = 0; j < w; ++j ) {
            printf("%d ", states[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for ( i = n-1; i >= 0; --i ) {
        for ( j = w; j >= 0; --j ) {
            if ( states[i][j] ) {
                maxW = j;
                return;    
            }    
        }    
    }
}

int main (){

    int arr[] = {2,2,4,6,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int cw = 0;
    int w = 9;

    int states[n][w+1];
    int states1[w+1];

    int i, j = 0;
    for ( i = 0; i < w+1; ++i ) {
        states1[i]=0;
    } 
    for ( i = 0; i < n; ++i ) {
        for ( j = 0; j < w+1; ++j ) {
            states[i][j] = 0;
        }    
    }

    //dynamic_programming_recall ( 0, 0, arr, n, w , states);
    //dynamic_programming ( arr, n, w , states);
    dynamic_programming1 ( arr, n, w , states1);

    printf( "%d\n", maxW );    
    return 0;
}

