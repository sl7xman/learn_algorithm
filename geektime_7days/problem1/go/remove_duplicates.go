package main

import (
    "fmt"
)

func show_array(nums []int, n int) {
    for i := 0; i < n; i++ {
        fmt.Printf("%d ",nums[i])
    }
    fmt.Println("")
}
func removeDuplicates_2p(nums []int) int {
    if len(nums) == 0 {
        return 0
    }

    cur_val := nums[0]
    next_idx := 1
    for i := range nums {
        if nums[i] != cur_val {
            nums[next_idx] = nums[i]
            cur_val=nums[i]
            next_idx++
        }
    }

    return next_idx
}

func removeDuplicates(nums []int) int {
    siz := len(nums);
    if siz == 0 {
        return 0
    }

    slow_idx :=0

    for i := range nums {
        if nums[slow_idx] != nums[i] {
            slow_idx++
            nums[slow_idx] = nums[i]
        }
    }

    return slow_idx+1
}

