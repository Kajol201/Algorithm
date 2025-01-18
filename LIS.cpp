#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int findLIS(int nums[], int size, int index, int prevIndex, vector<vector<int>> &memo) {
    if (index == size) return 0;

    if (memo[index][prevIndex + 1] != -1)
        return memo[index][prevIndex + 1];


    int skip = findLIS(nums, size, index + 1, prevIndex, memo);


    int include = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        include = 1 + findLIS(nums, size, index + 1, index, memo);
    }

    memo[index][prevIndex + 1] = max(skip, include);
    return memo[index][prevIndex + 1];
}

int longestIncreasingSubsequence(int nums[], int size) {
    vector<vector<int>> memo(size, vector<int>(size + 1, -1));
    return findLIS(nums, size, 0, -1, memo);
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << "The length of the longest increasing subsequence is "
         << longestIncreasingSubsequence(nums, size) << endl;
    return 0;
}

