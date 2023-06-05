#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int index1 = 0;
        int indexN = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                index1=i;
            }
            if(nums[i]==n){
                indexN = i;
            }
        }
        return index1 + n-1 - indexN - max(0, index1>indexN?1:0);
    }
};