class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ans(2, -1);
        bool flag = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (flag == false)
                    ans[0] = i;
                flag = true;
                ans[1] = i;
            }
        }
        return ans;
    }
};
