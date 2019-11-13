#ifndef TRAP_H
#define TRAP_H
#include <algorithm>
#include <vector>
using namespace std;
class Solution {

public:
    Solution(){}
    ~Solution(){}

    int trap(vector<int>& height) {
        int i,j = 0;

        int pillar_vulume = 0;
        for ( i = 0; i < height.size(); ++i ){
            pillar_vulume += height[i];
        }

        int l_high = 0;
        int max_high = 0;
        int max_high_idx = 0;
        int r_high = 0;
        int layer = 0;
        int total_vulume = 0;
        std::cout<< "i=" << i << " j=" << j <<std::endl; 
        i = 0;
        j = height.size() - 1;
        while ( i < j ) {
            std::cout<< "i=" << i << " j=" << j <<std::endl; 
            int l = height[i];
            int r = height[j];
            
            if ( l > l_high ) {
                l_high = l;
            }
            if ( r > r_high ) {
                r_high = r;
            }

            if ( max_high < l ) {
                max_high = l;
                max_high_idx = i;
            }

            if ( max_high < r ) {
                max_high = r; 
                max_high_idx = j;
            }

            if ( r_high > layer && l_high > layer ) {
                int n_high = std::min(r_high, l_high);
                total_vulume += (j-i) * ( n_high - layer );
                layer = n_high;
            }
            ++i;
            --j;
        }
            
        total_vulume += height[max_high_idx] - layer;

        return total_vulume;
    }
};

#endif

