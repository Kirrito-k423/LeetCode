#include <vector>
#include <algorithm>
#include <string>
#include <math>
using namespace std;
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result(m);
        for (int i = 0; i < m; i++) {
            int len = 0;
            for (int j = 0; j < n; j++) {
                len = max(len, (grid[j][i]>=0?(0):(1))+(int)to_string(abs(grid[j][i])).size());
            }
            result[i]=len;
        }
        return result;
    }
};