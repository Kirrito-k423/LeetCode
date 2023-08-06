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
    int numberOfWays(int n, int x) {
        // 取与不取，0-1背包
        // pow(i,x) < n
        int max_i = 1;
        while(pow(max_i,x)<=n)max_i++;
        max_i--;

        vector<vector<int>> memory(max_i+1, vector<int>(n+1, -1));
        function<int(int,int)> dfs = [&](int i, int c){
            if(i<=0){
                if(c==0) return 1;
                else return 0;
            }
            if(memory[i][c]!=-1){
                return memory[i][c];
            }
            int &result = memory[i][c];
            int current_value = pow(i,x);
            if(current_value<=c){
                result = (dfs(i-1,c)+dfs(i-1,c-current_value))%((long long )1e9 + 7);
            }else{
                result = dfs(i-1,c)%((long long )1e9 + 7);
            }
            return result;
        };
        return dfs(max_i,n);      
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }