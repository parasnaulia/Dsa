#include <iostream>
#include <vector>
using namespace std;

int knapsackRecursive(vector<int>& weights, vector<int>& values, int capacity, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (weights[n - 1] > capacity) {
        return knapsackRecursive(weights, values, capacity, n - 1);
    } else {
        int include_item = values[n - 1] + knapsackRecursive(weights, values, capacity - weights[n - 1], n - 1);
        int exclude_item = knapsackRecursive(weights, values, capacity, n - 1);
        return max(include_item, exclude_item);
    }
}

int main() {
       vector<int> weights={1,2,3};
      vector<int> values={4,5,6};
    int capacity = 3;
    int n = weights.size();
    
    cout << "Maximum value: " << knapsackRecursive(weights, values, capacity, n) << endl;
    
    return 0;
}
