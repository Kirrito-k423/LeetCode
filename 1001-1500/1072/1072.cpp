#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // 逆向，相同的行1111 1111 or 0000 0000. 反转列变成 1101 1101 and 0010 0010
        // 可以发现将第一位变成1 后，答案就是同为某序列 1101的最大个数
        unordered_map<string, int> countStr;
        int n = matrix[0].size();
        int ans = INT_MIN;
        for(auto & line : matrix) {
            string tmp(n,0);
            for(int i=0; i<n; i++) {
                tmp[i] = line[i] ^ line[0];
            }
            ans = max(ans,++countStr[tmp]);
        }
        return ans;
    }
};