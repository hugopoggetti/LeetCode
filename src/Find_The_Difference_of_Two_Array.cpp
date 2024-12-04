
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for (int i = 0; i < nums1.size(); i++)
            map1[nums1[i]] += 1;
        for (int j = 0; j < nums2.size(); j++)
            map2[nums2[j]] += 1;

        vector<vector<int>> answer(2);

        for (int i = 0; i < nums1.size(); i++) {
            auto it = map2.find(nums1[i]);
            if (it == map2.end()) {
                answer[0].push_back(nums1[i]);
                map2[nums1[i]] += 1;
            }
        }

        for (int j = 0; j < nums2.size(); j++) {
            auto it = map1.find(nums2[j]);
            if (it == map1.end()) {
                answer[1].push_back(nums2[j]);
                map1[nums2[j]] += 1;
            }
        }
        return  answer;
    }
};
