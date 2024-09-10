#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

*/

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int get_profit(int min, int *prices, int size)
{
    int index_min = 0;
    for (size_t i = 0; i < size; i++) {
        if (prices[i] == min) {
            index_min = i;
            break;
        }
    }
    int max = 0;
    for (int i = index_min + 1; i < size; i++) {
        if (prices[i] > max)
            max = prices[i];
    }
    return (max - min);
}

int maxProfit(int* prices, int pricesSize) 
{
    int max_profit = 0;
    int *sort = malloc(sizeof(int) * pricesSize);

    memcpy(sort, prices, sizeof(int) * pricesSize); // cpy prices array 
    qsort(sort, pricesSize, sizeof(int), compare);  // sort cpy array to check the min value of the day

    for (size_t i = 0; i < pricesSize; i++) { // for loop to compare profit
        int min = sort[i];
        int profit = get_profit(min, prices, pricesSize);
        if (profit > max_profit)
            max_profit = profit;
    }
    if (max_profit >= 0)
        return max_profit;
    return 0;
}
