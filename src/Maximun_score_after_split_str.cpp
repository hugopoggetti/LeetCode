class Solution {

private:
    int max_split(string left, string right)
    {
        int zero = 0;
        int one = 0;

        for (int i = 0; i < left.size(); i++)
            if (left[i] == '0')
                zero++;
        for (int i = 0; i < right.size(); i++)
            if (right[i] == '1')
                one++;
        return zero + one;
    }

public:
    int maxScore(string s)
    {
        int ans = 0;

        for (int i = 1; i < s.size(); i++) {
            ans = max(ans, max_split(s.substr(0, i), s.substr(i)));
        }
        return ans;
    }
};
