#include <bits/stdc++.h>
using namespace std;

string longest_repeating_non_overlapping_substring(string str) {
    int n = str.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    int max_len = 0, end_index = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (str[i - 1] == str[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end_index = i - 1;
                }
            }
        }
    }
    return str.substr(end_index - max_len + 1, max_len);
}

int main() {
    string str;
    cin >> str;
    cout << longest_repeating_non_overlapping_substring(str) << endl;
    return 0;
}
