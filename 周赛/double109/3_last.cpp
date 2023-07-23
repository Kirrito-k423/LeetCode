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
		// memset(memory,0x80000000,sizeof(memory));

		vector<int> even_position;
		vector<int> odd_position;
		for(int i=0; i<n; i++){
			memory[i] = LONG_MIN;
			if(nums[i]%2==0){
				even_position.emplace_back(i);
			}else{
				odd_position.emplace_back(i);
			}
			// 偶数链，奇数链
		}
		memory[0] = nums[0];
		int even_i = 0;
		int odd_i = 0;
		for(int i=0; i<n; i++){
			//change next
			if(nums[i]%2==0){
				if((++even_i)<even_position.size()){
					int & next_even = even_position[even_i];
					memory[next_even] = max(memory[next_even], memory[i] + nums[next_even]);
				}
				if(odd_i<odd_position.size()){
					int & next_odd = odd_position[odd_i];
					memory[next_odd] = max(memory[next_odd], memory[i] + nums[next_odd] - x);
				}
			}else{
				if((even_i)<even_position.size()){
					int & next_even = even_position[even_i];
					memory[next_even] = max(memory[next_even], memory[i] + nums[next_even] - x);
				}
				if((++odd_i)<odd_position.size()){
					int & next_odd = odd_position[odd_i];
					memory[next_odd] = max(memory[next_odd], memory[i] + nums[next_odd]);
				}
			}
			result = max(result,memory[i]);
		}
		return result;
    }
};


// int main(){
// 	Solution solution;
// 	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={9,58,17,54};
// 	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.maxScore(price, 90)<< endl;
// }