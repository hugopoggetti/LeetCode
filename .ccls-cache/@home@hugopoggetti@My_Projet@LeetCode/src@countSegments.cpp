#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s)
    {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                count++;
            while (s[i] != ' ' && i < s.size()) i++;
        }
        return count;
    }
};
