
#include <iostream>
#include <vector>
using namespace std;
int bottom_up(vector<int> &weight, vector<int> &value, int sum, int W, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    
    // Base case initialization
    for (int i = 0; i <= W; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            int take = 0;
            if (j >= weight[i - 1]) {
                take = dp[i - 1][j - weight[i - 1]] + value[i - 1];
            }
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    
    return dp[N][W];
}

int main() {
    vector<int> weight = {4,5,1};
    vector<int> value = {1,2,3};
    int capacity = 3;
    int numItems = weight.size();
    
    cout << "Maximum value: " << bottom_up(weight, value, capacity, capacity, numItems) << endl;
    
    return 0;
}
