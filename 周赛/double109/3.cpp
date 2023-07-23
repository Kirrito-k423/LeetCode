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
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();

		long long memory[n];
		long long result = LONG_MIN;
		memset(memory,128,sizeof(memory));

		// for(int i=0; i<n; i++){
		// 	memory[i] = LONG_MIN;
		// }
		memory[0] = nums[0];
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if((nums[j]-nums[i])%2==0){
					memory[j] = max(memory[j], memory[i]+nums[j]);
				}else{
					memory[j] = max(memory[j], memory[i]+nums[j]-x);
				}
			}
			result = max(result,memory[i]);
		}
		return result;
    }
};


int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	vector<int> price ={9,58,17,54};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	cout << solution.maxScore(price, 90)<< endl;
}