package main

import(
    "fmt"
    "testing"
)

func show_array(arr []int){
    fmt.Println(arr)
}

func TestBubble( T *testing.T){
    var arr =[]int{3,5,4,1,2,6};
    fmt.Printf("before standard sort: ")
    show_array(arr)
    fmt.Println("standard sort: ")
    bubble_int_standard(arr)
    fmt.Printf("after standard sort: ")
    show_array(arr)
}
