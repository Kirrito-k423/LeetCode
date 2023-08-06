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

		// int memory[n][constrain];
		// memset(memory,-1,sizeof(memory));
		vector<vector<int>> memory(n+10,vector<int>(constrain+10,-1));
		function<int(int,int)> dfs = [&](int i, int c){
			if(i==-1){
				if(c==0)
					return 1;
				else
					return 0;
			}
			if(memory[i][c]!=-1){
				return memory[i][c];
			}
			int &result = memory[i][c];
			if(c<nums[i]){
				result = dfs(i-1,c);
			}else{
				result = dfs(i-1,c) + dfs(i-1,c-nums[i]);
			}
			return result;
		};

		return dfs(n-1,constrain);
    }
};