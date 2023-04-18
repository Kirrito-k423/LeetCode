#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
	int N;
	int AdList[50][50];
	int near[50];
	int subPath(int from, int j, int end,int (&result)[2],  int (&curPathCost)[2], vector<int>& price){
		if(j==end){
			curPathCost[0]+=((near[j]==1)?(1):(0.5))* price[j];
			curPathCost[1]+=((near[j]==1)?(0.5):(1))* price[j];
			result[0]+=curPathCost[0];
			result[1]+=curPathCost[1];
			return 1;
		}
		curPathCost[0]+=((near[j]==1)?(1):(0.5))* price[j];
		curPathCost[1]+=((near[j]==1)?(0.5):(1))* price[j];
		for(int i=0; i<N; i++){
			if(from!=i && AdList[j][i] > 0 ){
				if(subPath(j, i, end, result, curPathCost, price))
					return 1;
			}
		}
		curPathCost[0]-=((near[j]==1)?(1):(0.5))* price[j];
		curPathCost[1]-=((near[j]==1)?(0.5):(1))* price[j];
		return 0;
	}
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // 树上路径是唯一的
		//trps 经过的点的确定的，
		//只有两种情况，取最小即可
		N=n;
		memset(AdList, 0, sizeof(AdList));
		memset(near, 0, sizeof(near));
		int edgeCount = edges.size();
		for(int i = 0; i < edgeCount; i++) {
			vector<int> &edge = edges[i];
			AdList[edge[0]][edge[1]] = 1;
			AdList[edge[1]][edge[0]] = 1;
		}

		//标记邻居
		int flag = 1;
		queue<int> pass;
		queue<int> tmp;
		pass.push(0);
		while(!pass.empty()) {	
			while(!pass.empty()) {
				int cur = pass.front();
				pass.pop();
				near[cur] = flag;
				for(int i = 0; i < n; i++) {
					if(near[i] == 0 && AdList[cur][i] > 0 ){
						tmp.push(i);
					}
				}
			}
			flag = -flag; 
			swap(pass,tmp);
		}

		int result[2] = {0,0};
		for(auto &try1 :trips){
			int begin = try1[0];
			int end = try1[1];
			// vector<int> curPathCost(2,0);
			int curPathCost[2] = {0,0};
			subPath(-1, begin,end,result, curPathCost, price);
		}
		return min(result[0],result[1]);

	}

};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }