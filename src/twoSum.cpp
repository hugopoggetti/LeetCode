#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// brut force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum(2);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    sum[0] = i;
                    sum[1] = j;
                    return sum;
                }
            }
        }
        return {};
    }
};

// Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};