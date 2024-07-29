#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
*
* You are given two integer arrays nums1 and nums2,
* sorted in non-decreasing order, and two integers m and n,
* representing the number of elements in nums1 and nums2 respectively.

* Merge nums1 and nums2 into a single array sorted in non-decreasing order.

* The final sorted array should not be returned by the function,
* but instead be stored inside the array nums1.
* To accommodate this, nums1 has a length of m + n,
* where the first m elements denote the elements that should be merged,
* and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*
* Example:

* Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
* Output: [1,2,2,3,5,6]
* Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
* The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int *merge = malloc(sizeof(int) * nums1Size);
    int xs = 0;         // index to acces to merge
    int count1 = 0;    // increment nums1
    int count2 = 0;    // increment nums2

    while (count1 < m && count2 < n) {
        if (nums1[count1] <= nums2[count2]) {
            merge[xs++] = nums1[count1];
            count1++;
        } else {
            merge[xs++] = nums2[count2];
            count2++;
        }
    }
    while (count1 < m) {
        merge[xs++] = nums1[count1];
        count1++;
    }
    while (count2 < n) {
        merge[xs++] = nums2[count2];
        count2++;
    }
    memcpy(nums1, merge, (sizeof(int) * nums1Size));
    free(merge);
}
