class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<int, int> map;
        // fill out map with frequency of char
        for (char c : s) {
            map[c]++;
        }
        // create vector of int pair to sort number of each element
        vector<pair<int, int>> heap;
        for (auto& entry : map) {
            heap.push_back({entry.first, entry.second});
        }
        // sort vector with compare function to compare element frequence
        sort(heap.begin(), heap.end(), [](pair<int,int>& a, pair<int,int>& b) { return a.second > b.second; });

        string ans;
        for (int i = 0; i < heap.size(); i++) {
            for (int j = 0; j < heap[i].second; j++)
                ans.push_back(heap[i].first);
        }
        return ans;
    }
};
