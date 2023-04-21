
#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;



// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //带记忆DFS
        int n = nums.size();
        vector<int> memory(n,-1);
        
        function<int(int)> dfs = [&dfs,&memory,&nums](int i) {
            if(i<0) return 0;
            int &LIS = memory[i];
            if(LIS!=-1) return LIS;
            LIS = 1;
            int tmp = 0;
            for(int j = 0; j < i ; j++) {
                if(nums[i]>nums[j]) 
                    tmp = max(tmp,dfs(j));
            }
            LIS += tmp;
            return LIS;
        };
        int result = 0;
        for(int i = 0; i < n; i++) {
            result = max(result,dfs(i));
        }
        return result;
    }
};