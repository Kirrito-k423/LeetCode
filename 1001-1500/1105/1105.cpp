#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
// const int N=1E5+10,M=210;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
		// dfs(i) 是以i新开一行的后续高度最小值
		int n = books.size();

		vector<int> memory(n,INT_MAX);
		function<int(int)> dfs = [&](int I){
			if(I == n) return 0;
			int h = 0;
			int w = shelfWidth;
			int &res = memory[I];
			if (res != INT_MAX) return res;
			for(int i=I; i<n; i++){
				int &curH = books[i][1];
				int &curW = books[i][0];
				if(w>=curW){
					h = max(h, curH);
					w -= curW;
					res = min(res, h + dfs(i+1));
				}else{
					break;
				}
			}
			return res;
		};
		return dfs(0);
    }
};
// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }