#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		//由于是树，就是dfs，
		// dfs 输入 
		// int curNode 
		// float probability， 节点概率， 子节点平分
		// int father //子节点剔除父亲
		// int depth 深度 < t , >t 直接返回
		// if curNode == target then result = probability

		// adjList
		unordered_set<int> adjList[n+1];
		adjList[1].insert(0);
		for(auto & edge : edges){
			adjList[edge[0]].insert(edge[1]);
			adjList[edge[1]].insert(edge[0]);
		}
		double result = 0;

		function<bool(int, double, int, int)> dfs = \
			[&result, &dfs, &n, &target, &t, &adjList](int curNode, double probability,\
			int father, int depth){
				if(depth > t) return false;
				int childSize = adjList[curNode].size()-1;
				// if(adjList[curNode].count(father)){
				// 	childSize = adjList[curNode].size()-1;
				// }else{
				// 	childSize = adjList[curNode].size();
				// }
				// 由于是树，经过一次就不会回来了。
				if(curNode == target){
					if(depth == t || childSize==0){
						result = probability;
					}		
					return true;
				}
				double childProbability = probability/childSize;
				for(auto child : adjList[curNode]){
					if(child != father){
						if(dfs(child, childProbability, curNode, depth+1))
							return true;
					}
				}
				return false;
		};
		dfs(1, 1.0 , 0, 0);
		return result;
    }
};