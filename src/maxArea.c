#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int min_value(int first, int second)
{
    return (first < second) ? first : second;
}

void check_Area(int left, int right, int *max_water, int i, int j)
{
    int min = min_value(left, right);
    int lenght = j - i;
    if ((min * lenght) > (*max_water))
        (*max_water) = (min * lenght);
}

int maxArea(int* height, int heightSize)
{
    int max_water = 0;
    for (int i = 0; i < heightSize; i++)
        for (int j = heightSize - 1; j > 0; j--)
            check_Area(height[i], height[j], &max_water, i, j);
    return max_water;
}

// optimisate version 
int maxArea(int* height, int heightSize)
{
    int left = 0, right = heightSize - 1, maxArea = 0;

    while(left < right) {
        int Area = (right - left) * (height[left] < height[right] ? height[left++] : height[right--]);
        maxArea = Area > maxArea ? Area : maxArea;
    }
    return maxArea;
}
