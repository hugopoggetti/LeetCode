class Solution {
public:
    // time complexity O(m * n) -> space complexity 0(1)
    vector<int> spiralOrOder(vector<vector<int>>& matrix)
    {
        vector<int> ans;

        int left = 0;
        int right = rows;
        int top = 0;
        int bottom = cols;

        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < bottom; i++) {
                ans.push_back(matrix[i][right - 1]);
            }
            right--;
            if (!(left < right && top < bottom))
                break;
            for (int i = right - 1; i > left - 1 ; i--) {
                ans.push_back(matrix[bottom - 1][i]);
            }
            bottom--;
            for (int i = bottom - 1; i > top - 1; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return  ans;
    }
};
