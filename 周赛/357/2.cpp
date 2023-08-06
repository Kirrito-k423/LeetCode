#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E5+10,M=210;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
		int pre = nums[0];
		int n = nums.size();
		if(n<=2) return true;
        for(int i = 1; i < n; i++) {
			if(nums[i]+nums[i-1]>=m){
				return true;
			}
		}
		return false;


		// function<bool(int,int)> dfs = [&](int begin_index, int end_index) {

		// };

		// return dfs(0,nums.size()-1);
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }