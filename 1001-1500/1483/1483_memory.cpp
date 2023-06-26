#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
public:
    vector<int> saved;
    map<pair<int,int>,int> visited;
    int N;
    TreeAncestor(int n, vector<int>& parent) {
        saved = parent;
        visited.clear();
        N=n;
    }
    
    int getKthAncestor(int node, int k) {
        cout << " " << node << " " << k << endl;
        if(k>N) return -1;
        if(k==0) return node;
        if(node<0){
            return -1;
        }
        pair<int,int> search = make_pair(node,k);
        if(visited.count(search)){
            return visited[search];
        }else{
            cout << node << " " << saved[node] << endl;
            int tmp = getKthAncestor(saved[node],--k);
            cout << " " << tmp << endl;
            visited[search]=tmp;
            return tmp;
        }
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

// 简单的记忆化还是会超时 8/16