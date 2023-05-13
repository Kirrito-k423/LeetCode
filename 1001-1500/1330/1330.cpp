#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int result = 0;
        int bonus = 0;
        int n = nums.size();
        int absCut[30000];
        for (int i = 0; i < n-1; ++i) {
            int cur = abs(nums[i] - nums[i+1]);
            absCut[i] = cur;
            result += cur;
            int delta = abs( nums[i+1] - nums[0]) - cur;
            if(delta > bonus) bonus = delta;
            delta = abs( nums[i] - nums[n-1]) - cur;
            if(delta > bonus) bonus = delta;
        }
        // for (int i = 1; i < n-1; ++i) {
        //     for (int j = i+1; j < n-1; ++j) {
        //         // int cur = abs(nums[i] - nums[i-1]) + abs(nums[j] - nums[j+1]);
        //         int cur = absCut[i-1] + absCut[j];
        //         int delta = abs(nums[j] - nums[i-1]) + abs(nums[i] - nums[j+1]);
        //         if(delta-cur > bonus) bonus = delta-cur;
        //     }
        // }
        int mx2 = INT_MIN, mn2 = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i], y = nums[i + 1];
            mx2 = max(mx2, min(x, y));
            mn2 = min(mn2, max(x, y));
        }
        return result + max(bonus, 2* (mx2 - mn2));
    }
};