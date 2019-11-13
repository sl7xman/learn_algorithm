#include <iostream>
#include <vector>

#include "trap.h"

int main(){
    std::vector<int> t = {0,1,0,2,1,0,1,3,2,1,2,1}; 
    Solution s;
    int r = s.trap(t);
    std::cout << r << std::endl;  
}
