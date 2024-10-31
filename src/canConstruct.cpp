class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<int, int> mapr;
        unordered_map<int, int> mapm;

        for (int i = 0; i < ransomNote.size(); i++) {
            mapr[ransomNote[i]] += 1;
        }
        for (int i = 0; i < magazine.size(); i++) {
            mapm[magazine[i]] += 1;
        }

        for (auto it = mapr.begin(); it != mapr.end(); ++it) {
            if (mapm[it->first] < it->second) {
                return false;
            }
        }
        return true;
        return true;
    }
};
