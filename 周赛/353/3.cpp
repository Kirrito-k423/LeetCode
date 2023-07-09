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
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        //暴力是n^2
		//DP 以n结尾的最长子数组，k 选择了一还是2

		int n = nums1.size();

		map<pair<int,int>,int> memory;
		function<int(int,int&)> dfs=[&](int pos,int& threshold){
			if(pos<0){ return 0;}
			if(memory.count(make_pair(pos,threshold))){
				return memory[make_pair(pos,threshold)];
			}
			int &result = memory[make_pair(pos,threshold)];
			result = 0;
			if(nums1[pos]<=threshold){
				result = max(result,dfs(pos-1,nums1[pos])+1);
			}
			if(nums2[pos]<=threshold){
				result = max(result,dfs(pos-1,nums2[pos])+1);
			}
			return result;
		};
		int MAX = INT_MAX;
		int final = 0;
		for(int i=0;i<nums1.size();i++) {
			final = max(final,dfs(i,MAX));
		}
		return final;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }