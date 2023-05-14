#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int memory[m][n];
        memset(memory, 0 , m * n * sizeof(int));
        for (int i = n-2; i>=0; i--) {
            for (int j = 0; j < m; j++) {
                int tmpMax = -1;
                if(j-1>=0 && grid[j][i] < grid[j-1][i+1]){
                    tmpMax = max(tmpMax, memory[j-1][i+1]);
                }
                if(grid[j][i] < grid[j][i+1]){
                    tmpMax = max(tmpMax, memory[j][i+1]);
                }
                if(j+1<m && grid[j][i] < grid[j+1][i+1]){
                    tmpMax = max(tmpMax, memory[j+1][i+1]);
                }
                memory[j][i] = tmpMax + 1;
            }
        }
        int result = 0;
        for(int i = 0; i < m; i++) {
            result = max(result, memory[i][0]);
        }
        return result;
    }
};