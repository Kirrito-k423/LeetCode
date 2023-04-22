#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;

class Solution {
public:
    vector<int> supplyWagon(vector<int>& supplies) {
		int n = supplies.size();
		//前缀和表示区间和
		vector<int> prefixSum(supplies.begin(),supplies.end());
		for(int i=1;i<n;i++){
			prefixSum[i] += prefixSum[i-1];
		}
		while(prefixSum.size()>n/2){
			//candidate
			vector<int> delta;
			delta.push_back(prefixSum[1]);
			for(int i=2; i<prefixSum.size(); i++){
				delta.push_back(prefixSum[i]-prefixSum[i-2]);
			}
			vector<int>::iterator it = min_element(delta.begin(),delta.end());
			prefixSum.erase(prefixSum.begin()+(it-delta.begin()));
		}
		for(int i=prefixSum.size()-1; i>0; i--){
			prefixSum[i] -= prefixSum[i-1];
		}
		return prefixSum;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }