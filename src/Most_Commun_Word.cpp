class Solution {
public:

    bool isDelim(char c)
    {
        return (c == ' ' || c == ',' || c == '.' 
            || c == '!' || c == '?' || c == ';' ||'\'');
    }
    string mostCommonWord(string paragraph, vector<string>& banned)
    {
        vector<string> words;
        unordered_map <string, bool>ban;
        unordered_map <string, int>mostCommon;
        
        for (auto &it : banned)
            ban[it] = true;
        
        string p;
        for (size_t i = 0; i < paragraph.size(); i++) {
            if (!isDelim(paragraph[i])) {
                if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
                    paragraph[i] += 32; 
                p += paragraph[i];
            }
            if ((isDelim(paragraph[i]) || i + 1 == paragraph.size()) && !p.empty() ) {
                words.push_back(p);
                p.clear();
            } 
        }
        string ans;
        int higher = 0;
        for (auto word : words) {
            if (ban.find(word) == ban.end()) {
                mostCommon[word] += 1;
                if (mostCommon[word] > higher) {
                    higher = mostCommon[word];
                    ans = word;
                }
            }
        }
        return ans;
    }
};
