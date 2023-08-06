#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int main() {
	int n;
	cin >> n;
	vector<int> w(n,0);
	vector<vector<int>> adj(n,vector<int>(0));
	for(int i=0; i<n; i++){
		cin >> w[i];
	}
	int a,b;
	while(cin >> a >> b){
		adj[a-1].emplace_back(b-1);
		adj[b-1].emplace_back(a-1);
	}
	//memory
	
	map<pii,int> memory;
	int max_delta = 0;
	function<int(int,int,int)> weight_tree = [&](int tree_index, int depth, int father_index){
		if(memory.count({tree_index,depth})){
			return memory[{tree_index,depth}];
		}
		int &tmp =  memory[{tree_index,depth}];
		tmp = w[tree_index] * depth;
		for(auto & neighbor: adj[tree_index]){
			if(neighbor!=father_index)
				tmp+=weight_tree(neighbor,depth+1,tree_index);
		}
		if(depth>2)
			max_delta = max(tmp - weight_tree(tree_index,2,father_index),max_delta);
		return tmp;
	};
	int root_full = weight_tree(0,1,0);

	// bfs all node


	cout << root_full-max_delta;

}
// 64 位输出请用 printf("%lld")

// 5% pass ?