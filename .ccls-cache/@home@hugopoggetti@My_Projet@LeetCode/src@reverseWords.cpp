class Solution {
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string w;
        vector<string> word;

        while (ss >> w) {
            word.push_back(w);
        }
        w.clear();
        for (int i = word.size() - 1; i >= 0; i--) {
            w += word[i];
            if (i != 0)
                w += " ";
        }
        return w;
    }
};
