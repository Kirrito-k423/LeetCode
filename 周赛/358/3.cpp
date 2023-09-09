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
    int minAbsoluteDifference(vector<int>& nums, int x) {
		// falied for which case ?
		int n = nums.size();
		vector<PII> to_search;
		for(int i=0; i<n; i++){
			to_search.emplace_back(make_pair(nums[i],i));
		}
		sort(to_search.begin(),to_search.end());
		int result = abs(nums[0]-nums[n-1]);
		int n2 = to_search.size();
		for(int i=0; i<n2; i++){
			for(int j=i+1; j<n2 && to_search[j].first-to_search[i].first<result; j++){
				PII & near = to_search[j];
				if(abs(near.second-to_search[i].second)>=x){
					result = min(result,to_search[j].first-to_search[i].first);
				}
			}
		}
		return result;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }