#include <string>
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        return to_string(atoi(num1) + atoi(num2));
    }
};
