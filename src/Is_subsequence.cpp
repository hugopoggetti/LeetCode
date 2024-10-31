class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int indexs = 0;
        int indext = 0;

        while (indexs < s.size() && indext < t.size()) {
            if (s[indexs] == t[indext])
                indexs++;
            indext++;
        }
        return indexs == s.size();
    }
};
