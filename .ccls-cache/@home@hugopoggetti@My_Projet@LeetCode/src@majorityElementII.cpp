class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> map; // create hashmap
        vector<int> ans; // create the answer
        int mini = (nums.size() / 3) + 1; // determine all elements that appear more than ⌊ n/3 ⌋ times.

        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] += 1; // increment the value of the key
        for (auto it = map.begin(); it != map.end(); ++it)
            if (it->second >= mini) // check if the value of the key is >= n/3
                ans.push_back(it->first); // add it to answer
        return ans;
    }
};
