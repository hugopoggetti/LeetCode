#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int *sort_array(int *n1, int s1, int *n2, int s2)
{
    int *array = malloc((s1 + s2) * sizeof(int));
    int xs = 0;
    int i = 0;
    int j = 0;

    while (i < s1 && j < s2) {
        if (n1[i] <= n2[j]) {
            array[xs] = n1[i];
            i++;
            xs++;
        } else {
            array[xs] = n2[j];
            j++;
            xs++;
        }
    }
    while (i < s1) {
        array[xs] = n1[i];
        i++;
        xs++;
    }
    while (j < s2) {
        array[xs] = n2[j];
        j++;
        xs++;
    }
    return array;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int *array = sort_array(nums1, nums1Size, nums2, nums2Size);
    int size = nums1Size + nums2Size;

    if (size % 2 == 0) {
        int middle1 = array[size / 2 - 1];
        int middle2 = array[size / 2];
        double value = (middle1 + middle2) / 2.0;
        free(array);
        return value;
    } else {
        double value = array[size / 2];
        free(array);
        return value;
    }
}

int main(void)
{
    int nums1[2] = {1, 3};
    int nums2[2] = {2, 7};

    double median = findMedianSortedArrays(nums1, 2, nums2, 2);
    printf("Median = %f\n", median);
}
