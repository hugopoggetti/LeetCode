#include <vector>
#include <iostream>
#include <ostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colIndex = col - 1;
        while(rowIndex < row && colIndex >= 0){
            int ele = matrix[rowIndex][colIndex];
            if(ele == target) return 1;
            if(ele < target) rowIndex++;  // Move downward
            else colIndex--; // Shift left
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 40;

    bool result = solution.searchMatrix(matrix, target);

    if (result) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
