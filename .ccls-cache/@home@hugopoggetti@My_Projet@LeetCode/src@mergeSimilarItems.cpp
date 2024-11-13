#include <unordered_map>
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < items1.size(); i++)
            map[items1[i][0]] = items1[i][1];
        for (int i = 0; i < items2.size(); i++)
            map[items2[i][0]] += items2[i][1];

        vector<vector<int>> ans;
        for (const auto& it : map) {
            ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
