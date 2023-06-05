#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        //Dp dfs 前n 最大或者最小的pair
        int n = nums.size();
        map<int,int> memoryUsed;
        map<int,pair<long long,long long>> memory;
        function<pair<long long,long long>(int)> dfs = [&](int curI){
            pair<long long,long long> &cur = memory[curI];
            long long &maxV = cur.first;
            long long &minV = cur.second;
            if(memoryUsed[curI]!=0) return cur;
            if(curI<0){
                minV=1;
                maxV=1;
                return cur;
            }
            minV = LLONG_MAX; maxV = LLONG_MIN;
            long long beforeMax =  dfs(curI-1).first;
            long long beforeMin =  dfs(curI-1).second;
            minV = min(minV, beforeMin);
            maxV = max(maxV, beforeMax);

            minV = min(minV, beforeMin * nums[curI]);
            maxV = max(maxV, beforeMax * nums[curI]);
            minV = min(minV, beforeMax * nums[curI]);
            maxV = max(maxV, beforeMin * nums[curI]);
            // for (int i = 0; i < curI; i++){
            //     minV = min(minV, dfs(i).second);
            //     maxV = max(maxV, dfs(i).first);
            // }
            // if(nums[curI]>0){
            //     minV = minV * nums[curI];
            //     maxV = maxV * nums[curI];
            // }else{
            //     long long tmpMax =  minV * nums[curI];
            //     long long tmpMin =  maxV * nums[curI];
            //     maxV = tmpMax;
            //     minV = tmpMin;
            // }
            return cur;
        };
        long long result = dfs(n-1).first;
        if (*max_element(nums.begin(), nums.end())<1 && result<=1)
            return *max_element(nums.begin(), nums.end());
        else
            return result;
    }
};

//方法错了，第一个不一定有