package main

import(
    "testing"
)

func TestRemoveDuplicates ( T *testing.T ) {
    var nums = []int{1,1,1,1,2,2,2,3,3,3,4,4,5,6,7}
    new_siz := removeDuplicates(nums)
    show_array(nums, new_siz)
}

func TestRemoveDuplicates2p ( T *testing.T ) {
    var nums = []int{1,1,1,1,2,2,2,3,3,3,4,4,5,6,7}
    new_siz := removeDuplicates_2p(nums)
    show_array(nums, new_siz)
}
