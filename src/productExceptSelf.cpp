class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> ans(nums.size(), 1);
        size_t index = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (j != i)
                    ans[index] *= nums[j];
            }
            index++;
        }
        return ans;
    }
};

