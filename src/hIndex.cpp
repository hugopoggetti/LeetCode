// TIME COMPLEXITY : Sorting is O(nlogn)O(nlogn). Looping h is O(n)O(n). So the time complexity is O(nlog)O(nlogn).
// SPACE COMPLEXITY : The only memory we allocate is the integer h, so the space complexity is O(1)O(1).


class Solution {
    public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0; // initalise index

        while (h < citations.size() && citations[h] >= h + 1) h++;
        return h;
    }
};
