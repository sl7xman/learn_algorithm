package main

import (
    "fmt"
)

func binsearch(arr []int, low, high, mem int) int{
    if  low > high {
        return -1
    }

    mid := low + ((high-low)>>1)

    if mem == arr[mid]{
        return mid
    }

    if( mem < arr[mid]){
        return binsearch(arr, low, mid-1, mem)
    }else{
        return binsearch(arr, mid+1, high, mem)
    }
}

func binsearch_no(arr []int, n, mem int) int{
    low:=0
    high:=n-1

    for {
        if( low > high){
            break
        }
        mid:= low+((high-low)>>1)
        if( mem == arr[mid]){
            return mid;
        }

        if( mem < arr[mid]){
            high = mid-1
        }else{
            low = mid+1
        }
    }
    return -1 
}
func main(){
    var arr=[]int{1,3,5,7,9,11,23,25, 27,30,47,55}
    r := binsearch(arr, 0, len(arr), 11)
    fmt.Println("find: ", r, arr[r])
    r = binsearch_no(arr,  len(arr), 11)
    fmt.Println("find: ", r, arr[r])

}
