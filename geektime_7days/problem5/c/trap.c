#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int trap(int* height, int heightSize){
    int total_volume = 0;
    int l, r = 0;
    int l_maxh = 0;
    int r_maxh = 0;
    int layer = 0;

    r = heightSize - 1;
    int pillor_volume = 0;
    int i = 0;
    for ( i = 0; i < heightSize; ++i ) {
        pillor_volume += height[i];
    }

    while ( l < r ) {
        if ( l_maxh == 0 && height[l] == 0 ){
            ++l;
            continue;
        }

        if ( r_maxh == 0 && height[r] == 0 ){
            --r;
            continue;
        }

        if ( l_maxh < height[l] ) {
            l_maxh = height[l];
        }

        if ( r_maxh < height[r] ) {
            r_maxh = height[r];
        }

        int mlayer = r_maxh > l_maxh ? l_maxh: r_maxh;
        if ( mlayer > layer ){
            total_volume = (l-r+1) * (mlayer - layer);
            layer = mlayer;
        }
        total_volume += height[l] +height[r];

        if ( l_maxh > r_maxh ) {
            --r;
        }else if ( l_maxh < r_maxh ){
            ++l;
        }else{
            --r;
            ++l;
        }
    }

    return total_volume;
}

int main() {
    //int height[] ={0,1,0,2,1,0,1,3,2,1,2,1};
    int height[] ={4,2,3};
    int n = sizeof(height)/sizeof(height[0]);

    int r = trap( height , n );
    printf("%d \n", r);
    return 0;    
}

