#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    // int digitSum(string num) {
    //     int sum = 0;
    //     for (char c : num) {
    //         sum += c - '0';
    //     }
    //     return sum;
    // }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int numLength = num2.length();
        vector<vector<vector<int>>> dp(numLength + 1, vector<vector<int>>(max_sum + 1, vector<int>(2)));

        // 初始化边界条件
        dp[0][0][0] = 1;

        // 计算动态规划状态
        for (int i = 1; i <= numLength; i++) {
            int digit2 = num2[numLength - i] - '0';
            int digit1 = (i <= num1.length()) ? (num1[num1.length() - i] - '0') : 0;
            for (int j = 0; j <= max_sum; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (j >= k) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - k][1]) % MOD;
                        if (k < digit2) {
                            dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - k][0]) % MOD;
                        } else if (k == digit2) {
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - k][0]) % MOD;
                        }
                    }
                }
            }
            if (digit1 > 0) {
                for (int j = 0; j <= max_sum; j++) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][1]) % MOD;
                    if (j >= digit1) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - digit1][0]) % MOD;
                    }
                }
            }
        }

        int result = dp[numLength][min_sum][1] - dp[numLength][min_sum][0];
        if (result < 0) {
            result += MOD;
        }
        return result;
    }
};

int main() {
    Solution solution;
    string num1 = "1";
    string num2 = "12";
    int min_sum = 1;
    int max_sum = 8;

    int result = solution.count(num1, num2, min_sum, max_sum);
    cout << result << endl;

    return 0;
}