#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int ids[100000];
class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        //10^5 排序大小数组
        int n = nums.size();
        iota(ids, ids+n, 0);
        sort(ids, ids+n, [&nums](const int &a, const int &b) { 
            return nums[a] < nums[b];
        });
        long long result = 0;
        result += n + ids[0];
        for(int i = 1; i < nums.size(); i++) {
            if(ids[i] > ids[i-1]){
                result += ids[i] - ids[i-1] - i; //??
            }else{
                result += (n - i) - (ids[i-1] - ids[i]);
            }
        }
        return result;
    }
};