class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int index = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[index]) {
                while (i < s1.size() && s1[i] == s2[index]) {
                    i++;
                    index++;
                    if (index == s2.size())
                        return true;
                }
            }
        }
        return false;
    }
};
