#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, size_t> um;

        for (int i = 0; i < nums.size(); i++) {
            // check if the element is ont the map
            if (um.count(nums[i])) {
                // if i see it check if the condition abs(i - j) <= k
                if (i - um[nums[i]] <= k)
                    return true;
            }
            // insert the number with its position
            um[nums[i]] = i;
        }
        return false;
    }
};