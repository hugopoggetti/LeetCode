#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        size_t odd = 0;
        size_t even = 1;

        while (odd < nums.size() && even < nums.size()) {
            if (nums[odd] % 2 == 0)
                odd += 2;
            else if (nums[even] % 2 != 0)
                even += 2;
            else
             swap(nums[odd], nums[even]);
        }
        return nums;
    }
};
