#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    int target = 3;
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Writing the base case
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool take = false;
            if (j >= nums[i]) {
                take = (i > 0 ? dp[i - 1][j - nums[i]] : false);
            }
            bool notTake = (i > 0 ? dp[i - 1][j] : false);
            dp[i][j] = take || notTake;
        }
    }

    cout << "Printing the dp" << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
