#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> map_s;
        unordered_map<int, int> map_t;

        for (int i = 0; i < s.size(); i++)
            map_s[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            map_t[t[i]]++;

        if (map_s.size() != map_t.size()) return false;

        for (const auto& pair1 : map_s) {
            auto it2 = map_t.find(pair1.first);
            if (it2 == map_t.end() || pair1.second != it2->second) return false; // key-value pair not found or mismatched
        }
        return true;
    }
};
