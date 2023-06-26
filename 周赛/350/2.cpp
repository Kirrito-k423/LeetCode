#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        //delta num
        sort(nums.begin(),nums.end());
        int result = INT_MAX;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            result = min(result, nums[i]-nums[i-1]);
        }
        return result;
    }
};