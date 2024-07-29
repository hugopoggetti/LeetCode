#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    for(int i = 0; i < numRows; i++){
        (*returnColumnSizes)[i] = i+1;
        triangle[i] = (int*)malloc( (i+1) * sizeof(int));
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                triangle[i][j] = 1;
            }else{
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }
    return triangle;
}
