#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "merge_two_sortlist.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode  head ;
    struct ListNode* tail;
    head.next = NULL;
    tail = &head;

    struct ListNode* h1, *h2;
    h1 = l1;
    h2 = l2;

    while(h1 && h2){
        int v1 = h1 -> val;
        int v2 = h2 -> val;
        if ( v1 < v2 ){
            tail -> next = h1;
            h1 = h1 -> next;
        }else{
            tail -> next = h2;
            h2 = h2 -> next;
        }
        tail = tail -> next;
    }

    while ( h1 ) {
        tail -> next = h1;
        tail = tail -> next;
        h1 = h1->next;
    }

    while ( h2 ) {
        tail -> next = h2;
        tail = tail -> next;
        h2 = h2->next;
    }

    return head.next;
}

void show_list( struct ListNode* l ) {
    struct ListNode* mit=l;
    
    while(mit){
        printf("%d ", mit -> val );
        mit = mit -> next;    
    }    
    printf("\n");
}


struct ListNode* create_list(int arr[], int n) {
    struct ListNode* h;
    struct ListNode l;
    l.next = NULL;
    h = &l;
    int ssiz = sizeof( struct ListNode );
    int i = 0;
    for ( i = 0; i < n; ++i ) {
        struct ListNode* tl = ( struct ListNode* )malloc( ssiz );
        tl -> val = arr[i];
        tl -> next = NULL;
        h->next = tl; 
        h = h->next;
    }
    return l.next;
}

void free_list( struct ListNode* l ) {
    struct ListNode* it = l;
    while( l ){
        it = it -> next;
        free(l);
        l = it;    
    }    
}

int main(){
    int arr1[] = {1,3,5,7,8};
    int arr2[] = {2,3,6,8,9,11};
    
    int n1 = sizeof( arr1 )/sizeof( arr1[0] );   
    int n2 = sizeof( arr2 )/sizeof( arr2[0] );   

    struct ListNode* l1 = create_list( arr1, n1 );
    struct ListNode* l2 = create_list( arr2, n2 );
    
    struct ListNode* res = mergeTwoLists(l1, l2);

    show_list( res);

    free_list( l1 );
    free_list( l2 );
    return 0;    
}
