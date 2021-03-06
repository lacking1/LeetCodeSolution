#include "../solution.h"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        for(int i=0; i<32; i++){
            if((n ^ (1 << i)) == 0)
                return true;
        }
        return false;
    }
};
