#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        };

        vector<int> ans;
        for (int i = 1; i <= nums.size(); i++) {
            if (mp.find(i) == mp.end)
                ans.push_back(i);
        }
        return ans;
    }
};
