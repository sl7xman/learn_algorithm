#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

float squareroot_no(int d){
    float r = 0;
    float low = 0.0;
    float high = d;

    while( low <=high){
        r=low +(high-low)/2;
        float r2 = r*r;
        if( r2>d-0.000001 && r2< d+0.000001){
            return r;
        } 

        if( r2 < d){
            low = r+0.000001;
        }else{
            high=r-0.000001;     
        }
    }

    return -1;    
}
float squareroot(int d, float low, float high){
    if( low >high){
        return -1;    
    }

    float r = low +(high-low)/2.0;
    float r2 = r*r;

    if( (r2<(d+0.000001)) && ((r2+0.000001)) >d ){
        return r;    
    }
    if( r2< d){
        squareroot(d, r+0.000001, high);    
    }else{
        squareroot(d, low, r-0.000001);
    }
}

int main(){
    printf("%f\n", squareroot_no(100));
    printf("%f\n", squareroot_no(10));
    printf("%f\n", squareroot_no(2));
    printf("%f\n", squareroot(100, 0.0, 100.0));
    printf("%f\n", squareroot(10, 0.0, 10.0));
    printf("%f\n", squareroot(2, 0.0, 2.0));
    return 0;    
}
