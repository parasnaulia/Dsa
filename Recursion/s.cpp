#include <iostream>
using namespace std;

int countSubsets(int arr[], int n, int index, int targetSum) {
    // Base case: If the target sum becomes 0, we've found a valid subset
    if (targetSum == 0) {
        return 1;
    }

    // Base case: If we've reached the end of the array
    if (index == n) {
        return 0;
    }

    // Recursive case 1: Include the current element in the subset
    int includeCount = countSubsets(arr, n, index + 1, targetSum - arr[index]);

    // Recursive case 2: Exclude the current element from the subset
    int excludeCount = countSubsets(arr, n, index + 1, targetSum);

    // Total count is the sum of includeCount and excludeCount
    return includeCount + excludeCount;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 3;

    int result = countSubsets(arr, n, 0, targetSum);
    cout << "Total subsets with sum " << targetSum << " starting from index 0: " << result << endl;

    return 0;
}
