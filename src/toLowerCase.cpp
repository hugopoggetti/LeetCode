#include <cstddef>
#include <string>

using namespace std;

class Solution {
public:
    size_t i = 0;
    string toLwerCase(string s)
    {
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] + 32);
     return s;
    }
};

