#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        for(int i = 0; i <n ; i++) {
            sort(nums[i].begin(), nums[i].end());
        }      
        int result = 0;
        for(int i = 0; i <m; i++) {
            int tmpMax = INT_MIN;
            for(int j = 0; j <n ; j++) {
                tmpMax = max(tmpMax, nums[j][i]);
            }
            result += tmpMax;

        }
        return result;
    }
};