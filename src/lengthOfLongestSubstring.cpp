class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<int> charSet;
        int prev = 0;

        for(int i = 0; i < n; i++) {
            if(charSet.count(s[i]) == 0) {
                charSet.insert(s[i]);
                maxLength = max(maxLength, i - prev + 1);
            } else {
                while(charSet.count(s[i])) {
                    charSet.erase(s[prev]);
                    prev++;
                }
                charSet.insert(s[i]);
            }
        }
        return maxLength;
    }
};
