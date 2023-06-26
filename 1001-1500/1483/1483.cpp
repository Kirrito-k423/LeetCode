#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> pa;
    TreeAncestor(int n, vector<int>& parent) {
        // DP 或者 递推
        int m = 32 - __builtin_clz(n);
        pa.resize(n, vector<int>(m,-1));
        for(int i = 0; i <n ; ++i){
            pa[i][0]=parent[i];
        }
        for(int j = 0; j < m-1 ; ++j){
            for(int i = 0; i < n ; ++i){
                if(int fa = pa[i][j]; fa != -1){
                    pa[i][j+1]=pa[fa][j];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        //任意k能表示成二进制, 
        for(;k && node!=-1; k &= k-1){
            node = pa[node][__builtin_ctz(k)];
        }
        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */