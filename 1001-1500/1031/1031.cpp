#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        //子数组转化为前缀和
        int n = nums.size();
        vector<int> prefixSum(nums.begin(),nums.end());
        for(int i=1; i<n; i++){
            prefixSum[i] += prefixSum[i-1];
        }
        int result = 0;
        // 暴力
        for(int i=0; i+firstLen-1<n; i++){
            int sum1 = prefixSum[i+firstLen-1] - prefixSum[i] + nums[i];
            int maxSum2 = 0;
            for(int j=0; j+secondLen-1<i; j++){
                maxSum2 = max(maxSum2,prefixSum[j+secondLen-1] - prefixSum[j] + nums[j]);
            }
            for(int j=i+firstLen;  j+secondLen-1<n; j++){
                maxSum2 = max(maxSum2,prefixSum[j+secondLen-1] - prefixSum[j] + nums[j]);
            }
            result = max(result,sum1+maxSum2);
        }
        return result;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	vector<int> price ={0,6,5,2,2,5,1,9,4};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	cout << solution.maxSumTwoNoOverlap(price, 1, 2)<< endl;
}