#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums, int target, int index, vector<vector<int>> &dp) {
    if (index < 0) {
        if (target == 0) {
            return true;
        }
        return false;
    }
    if (dp[index][target] != -1) {
        return dp[index][target];
    }
    bool take = false;
    if (target >= nums[index]) {
        take = solve(nums, target - nums[index], index - 1, dp);
    }
    bool notTake = solve(nums, target, index - 1, dp);
    // Add the following return statement
    return dp[index][target] = take || notTake;
}

int main() {
    vector<int> nums = {3, 9, 7, 3};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    int n = nums.size();
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
    solve(nums, sum, nums.size() - 1, dp);
    int mini = INT_MAX;
    for (int i = 0; i < dp[0].size(); i++) {
        if (dp[n - 1][i]) {
            int s1 = i;
            int s2 = sum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    cout << "The Minimum diff is" << endl;
    cout << mini;
    return 0;
}
