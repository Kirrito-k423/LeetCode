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
    int minimumIndex(vector<int>& nums) {
        int freq_value = 0;
		int n = nums.size();
		unordered_map<int,int> count;
		for (int i = 0; i < n;i++){
			count[nums[i]]++;
			if(count[nums[i]] > n/2){
				freq_value = nums[i];
				break;
			}
		}

		// int countFreq[n+1];
		// memset(countFreq,0,sizeof(countFreq));
		int total = 0;
		for (int i = 0; i < n;i++){
			if(nums[i] == freq_value){
				total++;
			}
		}

		int countPrefix = 0;
		for (int i = 0; i <n-1; i++){
			if(nums[i] == freq_value){
				countPrefix++;
				if(countPrefix *2 > i+1 && (total-countPrefix)*2> n - (i+1)){
					return i;
				}
			}
		}
		return -1;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }