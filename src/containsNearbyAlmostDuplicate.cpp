class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff)
    {
        int s = 0, e = 0, n = nums.size(), res = 1e9 + 1;
        map<int, int> mp;
        while(e < n) {
            if(e - s > indexDiff) {
                mp[nums[s]]--;
                if(mp[nums[s]] == 0) mp.erase(nums[s]);
                s++;
            }

            auto it = mp.upper_bound(nums[e]);
            if(it != mp.end())
                res = min(res, abs(nums[e] - it->first));
            if(it != mp.begin())
                res = min(res, abs(nums[e] - prev(it)->first));

            mp[nums[e]]++;
            e++;
        }
        return res <= valueDiff;
    }
};
