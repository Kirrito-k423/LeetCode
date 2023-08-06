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
    long long countPalindromePaths(vector<int>& parent, string s) {
        //树上任意两点间的信息怎么存储，除开距离
        //重排回文串 -> 至多一个奇数，其余偶数
        //字母计数奇偶问题 -> 二进制状态压缩 -> 特殊数字
        //两点间关系 -> 由于最小公共祖先，变成与根节点的关系
        //最终变成n-1 个值用hash存储，然后寻找 0 2^k 的数，和两两异或为这些的值的对。
        //可以变成动态的，tql 
        int n = parent.size();
        vector<vector<pair<int,int>>> adjoint(n);
        for(int i=1; i<n; i++){
            adjoint[parent[i]].push_back({i,1<<(s[i]-'a')});
        }
        long long  ans=0;
        unordered_map<int,int> cnt = {{0,1}};
        function<void(int,int)> dfs = [&](int cur_point,int weight){
            for(auto &[neighbor, w]:adjoint[cur_point]){
                int new_w = weight ^ w;
                ans += cnt[new_w];
                for(int i=0; i<26; i++){
                    ans += cnt[new_w ^ (1<<i)];
                }
                cnt[new_w]++;
                dfs(neighbor,new_w);
            }
        };


        dfs(0,0);

        return ans;

    }
};
// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }