#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        size_t left = 0;
        size_t right = nums.size() - 1;
        
        vector<int> ans(nums.size(), 0);

        for (auto &x : nums) {
            if (x % 2 == 0) {
                ans[left] = x;
                left++;
            } else {
                ans[right] = x;
                right--;
            }
        }
        return ans;
    }
};
