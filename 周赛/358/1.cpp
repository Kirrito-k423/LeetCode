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
	int max_digist(int input){
		int max_number = 0;
		while(input){
			max_number = max(max_number, input%10);
			input /= 10; 
		}
		return max_number;
	}
    int maxSum(vector<int>& nums) {
        int n = nums.size();
		vector<int> max_digist_number[10];
		for(int i=0; i<n; i++){
			max_digist_number[max_digist(nums[i])].emplace_back(nums[i]);	
		}
		int result_sum = -1;
		for(int i=0; i<10; i++){
			if(max_digist_number[i].size()>=2){

				sort(max_digist_number[i].begin(),max_digist_number[i].end(),std::greater<int>());
				result_sum = max(result_sum, max_digist_number[i][0]+max_digist_number[i][1]);
			}
		}
		return result_sum;

    }
};


// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }