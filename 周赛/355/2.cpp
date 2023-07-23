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
    long long maxArrayValue(vector<int>& nums) {
        long long result = 0;
		int n = nums.size();
		vector<long long> Nums(nums.begin(),nums.end());
		for(int i = n-1; i >= 1; i--){
			if(Nums[i]>Nums[i-1]){
				Nums[i-1]+=Nums[i];
			}else{
				result = max(result,Nums[i-1]);
			}
		}
		return max(result,Nums[0]);
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }