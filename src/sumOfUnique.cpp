class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
        unordered_map<int, int> map;
        int total = 0;

        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] += 1;

        for (auto& it: map) {
            if (it.second == 1)
                total += it.first;
        }
        return total;
    }
};
