package main

func bubble_int_standard(arr []int){
   var n=len(arr)
   var is_swap=false
   for i:=0; i<n; i++{
       is_swap=false
       for j:=0; j < n-i-1; j++{
           if(arr[j] > arr[j+1]){
               tmp := arr[j]
               arr[j]=arr[j+1]
               arr[j+1]=tmp
               is_swap=true
            }
        }
        if(is_swap == false){
            break
        }
   }
}

