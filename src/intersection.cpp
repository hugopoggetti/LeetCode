#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        unordered_map<int, int> map1, map2;

        for (int i = 0; i < nums1.size(); i++)
            map1[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++)
            map2[nums2[i]]++;
        for (auto i = map1.begin(); i != map1.end(); i++) {
            if (map2.find(i->first) != map2.end())
                ans.push_back(i->first);
        }
        return ans;
    }
};
