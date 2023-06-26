#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;
const int MOD = 1000000007;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long result = 1;
        int n = nums.size();
        int tmp = 1;
        auto i = 0;
        while(i<n && nums[i]==0 ){
            i++;
        }
        if(i==n) return 0;
        for(; i<n; i++){
            if(nums[i]==1){
                result = (result * tmp) % MOD;
                tmp = 1;
            }else{
                tmp++;
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