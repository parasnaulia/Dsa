#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, int> memo;

int solve(string &s, int i, int j, bool is_true) {
    if (i > j) return 0;
    if (i == j) {
        if (is_true == true) {
            return s[i] == 'T';
        } else {
            return s[i] == 'F';
        }
    }
    
    string temp = to_string(i) + " " + to_string(j) + " " + to_string(is_true);
    if (memo.find(temp) != memo.end()) {
        return memo[temp];
    }

    int ways = 0;
    for (int k = i + 1; k < j; k += 2) {
        int lt = solve(s, i, k - 1, true);
        int rt = solve(s, k + 1, j, true);
        int lf = solve(s, i, k - 1, false);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&') {
            if (is_true == true) {
                ways += lt * rt;
            } else {
                ways += lt * rf + lf * rt + lf * rf;
            }
        } else if (s[k] == '|') {
            if (is_true) {
                ways += lt * rt + lt * rf + lf * rt;
            } else {
                ways += lf * rf;
            }
        } else {
            if (is_true) {
                ways += lt * rf + lf * rt;
            } else {
                ways += lt * rt + lf * rf;
            }
        }
    }

    memo[temp] = ways;
    return ways;
}

int main() {
    string s = "F|T^F";
    cout << solve(s, 0, s.length() - 1, true);

    return 0;
}
