class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        // sort in decreasing order
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        // return the index of kth largest elements
        return nums[k-1];
    }
};
