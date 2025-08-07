#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string makeFancyString(string s)
    {
        char last = 0;
        int count_c = 1;
        string ans;
        ans.reserve(s.size());

        for (const char &c : s) {
            if (c == last)
                count_c++;
            else {
                count_c = 1;
                last = c;
            }
            if (count_c <=2) 
                ans.push_back(c);
        }
        return ans;
    }
};
