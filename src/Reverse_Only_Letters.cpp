
class Solution {
public:

    string reverseOnlyLetters(string s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (isalpha(s[left]) && isalpha(s[right])) {
                swap(s[left], s[right]);
                left++;
                right--;
            } else if (!isalpha(s[left]) && !isalpha(s[right])) {
                left++;
                right--;
            } else if (isalpha(s[left])) {
                right--;
            } else {
                left++;
            }
        } 
        return s;
    }
};

