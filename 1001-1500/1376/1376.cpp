#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		vector<vector<int>> adjList(n, vector<int>(0));
		for(int i=0; i<n; i++){
			if(manager[i]!=-1)
				adjList[manager[i]].push_back(i);
		}

		queue<pair<int,int>> BFS;
		queue<pair<int,int>> tmp;
		int result = 0;
		BFS.push({headID, 0});
		while(!BFS.empty()){
			while(!BFS.empty()){
				auto it = BFS.front();
				BFS.pop();
				int time = it.second + informTime[it.first];
				result = max(result, time);
				for(auto &x: adjList[it.first]){
					tmp.push({x, time});
				}
			}
			swap(BFS,tmp);
		}
		return result;
    }
};