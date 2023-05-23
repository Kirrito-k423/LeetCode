#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // adjList 0 代表 可以修改的边 -1 为无边

        // 图上找指定两点路径距离小于target的所有Dis， 
        // 如果集合空，无解
        //该两点间如果有不包含 0 权边的小于target的路径, 则无解
        for(auto Dist : DistSet)
            // if 经过x条 0 权边，
                int delta = Dis-target;
                if(delta < x*2*1e9){
                    return delta/(2*1e9);
                    // idea1: 增加后，怎么保证该路径还是最短的？ 增加其他的路径
                }
        } 
        
        
    }
};