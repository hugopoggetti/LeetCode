#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        string first="qwertyuiopQWERTYUIOP";
        string second="asdfghjklASDFGHJKL";
        string third="zxcvbnmZXCVBNM";

        vector<string> ans;
        int f = 0;
        int s = 0;
        int t = 0;

        for (int i = 0; i < words.size(); i++) {
            f = 0, s = 0, t = 0;
            for (int j = 0; j < words[i].size(); j++) {
                if(first.find(words[i][j])!=string::npos)
                   f++;
                else if(second.find(words[i][j])!=string::npos)
                   s++;
                else if(third.find(words[i][j])!=string::npos)
                   t++;
            }
            if(f==words[i].length()||s==words[i].length()||t==words[i].length())
               ans.push_back(words[i]);
        }
        return ans;
    }
};
