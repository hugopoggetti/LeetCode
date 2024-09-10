class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            int j = 0;
            while (j < nums2.size() && nums1[i] != nums2[j]) j++;
            while (j < nums2.size() && nums2[j] < (nums1[i] + 1)) j++;
            if (nums1[i] < nums2[j])
                ans.push_back(nums2[j]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

