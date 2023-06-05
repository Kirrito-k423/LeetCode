#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        // 如何快速寻找 同一行或同一列 严格大于的值，
        //先排序行列 m+n 然后upper_bound 查找，内容是value, indexXY
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, pair<int,int>>> lineQsort[n];
        vector<pair<int, pair<int,int>>> columnQsort[m];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                lineQsort[j].push_back({mat[i][j], {i,j}});
                columnQsort[i].push_back({mat[i][j], {i,j}});
            }
        }
        for(int i=0; i<n; i++){
            sort(lineQsort[i].begin(), lineQsort[i].end());
        }
        for(int i=0; i<m; i++){
            sort(columnQsort[i].begin(), columnQsort[i].end());
        }

        int memory[m][n];
        memset(memory,0 ,sizeof(memory));
        function<int(int,int)> dfs = [&dfs, &memory[]](int x, int y){
            int &result = memory[x][y];
            
            return 1;
        };

        int result = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result = max(result, dfs(i,j));
            }
        }
        return result;
    }
};