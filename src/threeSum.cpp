#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back({nums[0]});
        return res;
    }
};

int main(void)
{
    Solution Solution;
    vector<int> nums;
    nums.push_back({0});
    vector<vector<int>> res = Solution.threeSum(nums);
    printf("%d\n", res[0][0]);
    return 0;
}