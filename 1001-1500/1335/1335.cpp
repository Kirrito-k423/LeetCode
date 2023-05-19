#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        //求解 d 个子数组的 最大值的和的最小值
        //贪心的部分：最大值尽量覆盖更远
        int n = jobDifficulty.size();
        if (n < d) { return -1; }

        //memory
        int memory[d+1][n+1];
        memset(memory, INT_MAX, sizeof(memory));
        function<int(int,int)> dfs = [&](int d, int n){
            int &result = memory[d][n];
            if( result != INT_MAX ) return result;
            if(d==1){
                return *max_element(jobDifficulty.begin(), jobDifficulty.begin()+n);
            }
            int curMax = INT_MIN;
            for(int i = n-1; i >= d-1; i--) {
                curMax = max(curMax, jobDifficulty[i]);
                result = min(result, dfs(d-1, i) + curMax);
            }
            return result;
        };
        return dfs(d, n);
    }
};