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
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i+1]==nums[i]+1){
                int j = i;
                for(; j<n; j++){
                    if(nums[j]==
                        (nums[i]+(j-i)%2)){
                        continue;
                    }else{
                        break;
                    }
                }
                result=max(result,j-i);
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