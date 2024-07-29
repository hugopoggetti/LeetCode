
/*

Write a function that takes the binary representation
of a positive integer and returns the number of 
set bits
it has (also known as the Hamming weight).


Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

*/

int hammingWeight(int n)
{
    int count = 0;
    while (n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;   
}