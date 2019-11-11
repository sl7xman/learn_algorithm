#include <iostream>
typedef struct DequeData DequeData_t ;
struct DequeData {
    int val;
    DequeData_t* next;
    DequeData_t* prev;
};

class MyCircularDeque {
private:
    int size;
    int nums;
    DequeData_t* data;
    DequeData_t* head;
    DequeData_t* tail;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;   
        nums = 0;
        data = nullptr; 
        head = nullptr;
        tail = nullptr;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if ( isFull() ){
            return false;
        }

        DequeData_t* n  = new DequeData_t;
        if ( n == nullptr ){
            return false;
        }
        
        ++nums;
        n->val = value;
        if( head == nullptr ){
            n->next = nullptr;
            n->prev = nullptr;
            head = n;
            tail = n;
            return true;
        }

        n->next = head;
        n->prev = nullptr;
        head->prev = n;
        head = n;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if ( isFull() ){
            return false;
        }

        DequeData_t* n = new DequeData_t;
        if ( n == nullptr ){
            return false;
        }
        n->val = value;
        ++nums;
        if ( tail == nullptr ){
            n->next = nullptr;
            n->prev = nullptr;
            head = n;
            tail = n;
            return true;
        }
        
        n->next = nullptr;
        n->prev = tail;
        tail->next = n;
        tail = n;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if ( isEmpty() ){
            return false;
        }
        DequeData_t* t = head->next;
        if ( t ){
            t -> prev = nullptr;
        }else {
            tail = nullptr;
        }
        --nums;
        delete head;
        head = t;
        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if ( isEmpty() ){
            return false;
        }
        DequeData_t* t = tail->prev;
        if ( t ){
            t->next = nullptr;
        }else {
            head = nullptr;
        }
        
        --nums;
        delete tail;
        tail = t;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if( isEmpty() ){
            return -1;
        }
        return head -> val; 
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if ( isEmpty() ){
            return -1;
        }
        return tail -> val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return nums == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return nums == size;
    }
};


