#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int *mode_str_hash= NULL;
int *suffix=NULL;
int *prefix=NULL;

int max_c = 256;
void show_mode_str_hash( ){
    int i = 0;
    for ( i =0; i<max_c; i++) {
        if ( mode_str_hash[i] != -1 ) {
            printf("[%d]:%d\n",i, mode_str_hash[i]);
        }
    }    
    printf("\n");
}

int generate_mode_str_hash(char* s, int m){
    
    if( mode_str_hash != NULL){
        free(mode_str_hash);
        mode_str_hash = NULL;    
    }

    mode_str_hash = malloc(sizeof(int)*max_c);

    int i =0;
    for ( i=0; i<max_c; i++ ) {
        mode_str_hash[i]=-1;    
    }

    for ( i=0; i<m; i++){
        int c_to_i =(int)s[i];
        mode_str_hash[c_to_i] = i;    
    }
    
    return 0;    
}

void generateGS(char* sm, int m){
    if(!suffix){
        suffix = (int*)malloc(sizeof(int)*m);
    }    

    if (!prefix) {
        prefix = (int*)malloc(sizeof(int)*m);    
    }

    int i =0;
    for( i =0; i<m; i++){
        suffix[i]=-1;
        prefix[i]=0;    
    }

    for ( i = 0; i< m - 1; ++i){
        int j = i;
        int k = 0;
        while( j >=0 && sm[j] == sm[m-1-k]){
            --j;
            ++k;
            suffix[k]=j+1;    
        }
        if( j == -1 ) {
            prefix[k]=1;
        }
    }
}

int mymax(int x, int y){
    return x>y? x:y;    
}

int moveByGS(int j, int m){
    int k = m - 1 - j;
    if ( suffix[k] != -1){
        return j - suffix[k] + 1;    
    }

    int r = 0;
    for( r = j+2; r<=m-1; ++r){
        if(prefix[m-r] == 1){
            return r;    
        }    
    }
    return m;
}

int bm(char* s, int n, char* sm, int m){

    int i = 0;
    while( i <= n-m){
        printf("i:%d\n", i);
        int j;
        for( j = m-1; j>=0; --j) {
            if (s[i+j] != sm[j]){
                break;
            }
        }    
        if(j < 0) {
            return i;    
        }
        int x = j - mode_str_hash[(int)s[i+j]];
        
        int y = 0;
        if( j < m-1 ) {
            y = moveByGS(j, m);    
        }
        
        i = i+ mymax(x,y);
    }
    return -1;    
}

int main(){
    
    char *s ="abcacabcbcbacabc";
    char *sm ="cbacabc"; 
    int sl = strlen(s);
    int sml = strlen(sm);
    generate_mode_str_hash(sm, sml);
    generateGS(sm,sml);

    show_mode_str_hash();
    int r = bm(s, sl, sm, sml);
    printf("%d\n", r);
    return 0;    
}
