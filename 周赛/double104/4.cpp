#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        // 带记忆化搜索 max 子序列(排序)
        // 
        // c31 + c32 + c33 = 7
        sort(nums.begin(), nums.end());
        map<int, int> value2times;
        for(int i = 0; i < nums.size(); i++){
            value2times[nums[i]]++;
        }
        int result = 0;
        for(auto it = value2times.begin(); it != value2times.end(); it++) {
            auto it2 = it;
            //deal with equal numbers
            int subResult = it->first * it->first * it->first;
            result += subResult * Times(it,it);
            for(it2++; it2 != value2times.end() ;it2++){
                subResult = it->first * it2->first * it2->first;
                result += subResult * Times(it,it2);
            }
            result = result % int(1e9 + 7);
        }
        return result;
    }
};