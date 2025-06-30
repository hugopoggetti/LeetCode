class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        stringstream words1(s1);
        stringstream words2(s2);

        unordered_map<string, size_t> uncommon;

        string word;
        while (words1 >> word)
            uncommon[word] += 1;
        while (words2 >> word)
            uncommon[word] += 1;

        vector<string> ans;
        for (auto &it : uncommon) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

