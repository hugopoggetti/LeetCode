class Solution {
public:
    int myAtoi(string s)
    {
        int sign = 1, result = 0;
        int index = 0;

        for (;index < s.size() && s[index] == ' '; index++);

        if (index < s.size() && s[index] == '-' || s[index] == '+') {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        while (index < s.size() && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            cout << (result) << endl;
            index++;
        }
        return sign * result;

    }
};
