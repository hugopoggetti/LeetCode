#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>&nums)
    {
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main(void)
{
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Contains duplicate: " << (solution.containsDuplicate(nums1) ? "true" : "false") << std::endl;
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Contains duplicate: " << (solution.containsDuplicate(nums2) ? "true" : "false") << std::endl;
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Contains duplicate: " << (solution.containsDuplicate(nums3) ? "true" : "false") << std::endl;
    return 0;
}