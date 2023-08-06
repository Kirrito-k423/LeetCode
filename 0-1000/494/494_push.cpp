#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //chose + ,default = -
        int sum = accumulate(nums.begin(), nums.end(), 0);
		if ((sum+target)%2==1 || sum+target<0) return 0;
		int constrain = (sum+target)/2;
		int n = nums.size();

		// int dp[n+1][constrain+1];
		// memset(dp, 0, sizeof(dp));
		// dp[0][0] = 1;
		// for(int i=1; i<=n; i++){
		// 	for(int j=constrain; j>=0; j--)
		// 		if(j-nums[i-1]>=0)
		// 			dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
		// 		else{
		// 			dp[i][j] = dp[i-1][j];
		// 		}
		// }

		// return dp[n][constrain];

		int dp[constrain+1];
		memset(dp, 0, sizeof(dp));
		dp[0]=1;
		for(int i=1; i<=n; i++){
			for(int j=constrain; j>=nums[i-1]; j--)
				dp[j] = dp[j] + dp[j-nums[i-1]];
				
		}
		return dp[constrain];
    }
};