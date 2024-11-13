#include <optional>
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];
        int ans = 0;

        while (left < right)
        {
            if (left_max < right_max) {
                left++;
                left_max = max(height[left], left_max);
                ans += left_max - height[left];
            } else {
                right--;
                right_max = max(height[right], right_max);
                ans += right_max - height[right];
            }
        }
        return ans;
    }
};
