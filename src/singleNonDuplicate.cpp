class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        if (nums.size() == 0)
            return -1;
        for (int i = 1; i < nums.size(); i++) {
            if (i < (nums.size() - 1) && nums[i - 1] != nums[i] && nums[i + 1] != nums[i])
                return nums[i];
            if (i > 1 && i == (nums.size() - 1) && nums[i - 1] != nums[i])
                return nums[i];
        }
        return nums[0];
    }
};
