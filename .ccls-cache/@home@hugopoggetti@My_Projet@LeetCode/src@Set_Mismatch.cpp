class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        unordered_map<int, int> map;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        for (auto &it : map)
            if (it.second == 2)
                ans.push_back(it.first);
        int total_sum = n*(n+1)/2;
        int sum = 0;

        for(auto &it: map)
            sum += it.first;
        ans.push_back(total_sum - sum);
        return ans;
    }
};
