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
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        //原来是+，看错了 k权重最高，优先选k
		sort(items.begin(), items.end(),[](auto a, auto b) {
			return a[0]>a[1];
		});
		long long cur_sum = 0;
		long long cur_k = 0;
		int n = items.size();
		unordered_set<int> unique_k;
		vector<bool> get_flag(n,false);
		for(int i = 0; i<n; i++){
			int &to_add =items[i][0];
			int &tmp_k = items[i][1];
			
			if(unique_k.count(items[i][1])) continue;
			get_flag[i]=true;
			unique_k.insert(tmp_k);
			cur_sum += to_add;
			cur_k++;
			if(cur_k == k) return cur_sum+cur_k*cur_k;
		}
		for(int i = 0; i<n; i++){
			if(get_flag[i]) continue;
			int &to_add =items[i][0];
			int &tmp_k = items[i][1];
			unique_k.insert(tmp_k);
			cur_sum += to_add;
			cur_k++;
			if(cur_k == k) return cur_sum*cur_k*cur_k;
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