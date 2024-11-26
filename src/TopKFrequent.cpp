class Solution {
public:
    bool compare_map(pair<int,int> a, pair<int,int> b) { return a.second < b.second; }

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // create map and count numbers of items
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        // create vector of int pair to sort number of each element
        vector<pair<int, int>> heap;
        for (auto& entry : counter) {
            heap.push_back({entry.first, entry.second});
        }
        // sort vector with compare function to compare element frequence
        sort(heap.begin(), heap.end(), [](pair<int,int>& a, pair<int,int>& b) { return a.second > b.second; });
        // put most frequents elements in vector
        vector<int> topK;
        for (int i = 0; i < k; i++)
            topK.push_back(heap[i].first);
        return topK;
    }
};
