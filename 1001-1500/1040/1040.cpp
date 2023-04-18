#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int getValueIndex(vector<int> & stones, int value){
        //return i in stones value <= stones[i]
        int right = 0; int left = stones.size() - 1;
        while(right + 1 < left){
            int mid = (right + left) / 2;
            if(value <= stones[mid]){
                left = mid;
            }else{
                right = mid;
            }
        }
        return left;
    }
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        vector<int> ans(2,0);
        if(stones[n-1]-stones[0] == n-1) return ans;
        ans[1] = max(stones[n-2]-stones[0]+1-(n-1), stones[n-1]-stones[1]+1-(n-1));
        ans[0] = n;//min
        for(int left = 0, right = 0; left < n && right+1 < n; left++){
            while(right+1 < n && stones[right+1] - stones[left] <= n-1){
                ++right;
            }
            if(right - left +1 ==n-1 && stones[right-1] - stones[left] + 1== n-1){
                ans[0] = min(ans[0], 2); //情况1的第二种
            }else{
                ans[0] = max(ans[0],n - (right - left +1));
            }
        }
        return ans;
    }
};