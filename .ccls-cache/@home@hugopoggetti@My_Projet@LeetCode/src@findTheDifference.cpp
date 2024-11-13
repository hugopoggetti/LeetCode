#include <unordered_map>
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hasmap;
        char c = '\0';

        for (int i = 0; i < s.size(); i++)
            hasmap[s[i]]++;

        for (int i = 0; i < t.size, i++) {
            if (hasmap[t[i]] < 1)
                c = t[i];
        }
        return c;
    }
};
