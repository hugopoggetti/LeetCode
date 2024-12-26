class Solution {
public:
    string removeStars(string s)
    {
        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*')
                ans.pop_back();
            else
                ans += s[i];
        }
        return ans;
    }
};
