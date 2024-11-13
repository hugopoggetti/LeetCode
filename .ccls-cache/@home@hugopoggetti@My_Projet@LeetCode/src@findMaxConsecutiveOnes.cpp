#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int max = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count = 0;
                while (i < nums.size() && nums[i] == 1) {
                    count++;
                    i++;
                }
            }
            if (count > max)
                max = count;
        }
        return max;
    }
};

