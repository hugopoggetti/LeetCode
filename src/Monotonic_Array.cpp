#include <vector>

using namespace std;

class Solution {
public:

    bool isMonotonic(vector<int>& nums) 
    {
        if (nums.size() <= 1) return true;
        
        bool inc = true;
        bool dec = true;

        for (size_t i = 1; i < nums.size(); i++) {
            if (!inc && !dec)
                return false;
            if (nums[i] < nums[i - 1])
                inc = false;
            if (nums[i] > nums[i - 1])
                dec = false;
        }
        return dec || inc;
    }
};
