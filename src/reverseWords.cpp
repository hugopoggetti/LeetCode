class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int i = 0;
        int n = s.size();

        while (i < n) {
            if (s[i] != ' ') {
                i++;
            } else {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
                i++;
            }
        }
        if (start < n) {
            reverse(s.begin() + start, s.end());
        }
        return s;
    }
};
