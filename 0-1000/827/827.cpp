#include<bits/stdc++.h>

using namespace std;



const vector<int> d = {0, -1, 0, 1, 0};

class Solution {
public:
    bool valid(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    int dfs(const vector<vector<int>> &grid, int x, int y, vector<vector<int>> &tag, int t) {
        int n = grid.size(), res = 1;
        tag[x][y] = t;
        for (int i = 0; i < 4; i++) {
            int x1 = x + d[i], y1 = y + d[i + 1];
            if (valid(n, x1, y1) && grid[x1][y1] == 1 && tag[x1][y1] == 0) {
                res += dfs(grid, x1, y1, tag, t);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        // 是否被遍历，指向root
        vector<vector<int>> tag(n, vector<int>(n));
        // tag(i,j) , 相邻岛面积 
        unordered_map<int, int> area;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && tag[i][j] == 0) {
                    int t = i * n + j + 1;
                    area[t] = dfs(grid, i, j, tag, t);
                    res = max(res, area[t]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int z = 1;
                    unordered_set<int> connected;
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k], y = j + d[k + 1];
                        if (!valid(n, x, y) || tag[x][y] == 0 || connected.count(tag[x][y]) > 0) {
                            continue;
                        }
                        z += area[tag[x][y]];
                        connected.insert(tag[x][y]);
                    }
                    res = max(res, z);
                }
            }
        }
        return res;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/making-a-large-island/solutions/1828969/zui-da-ren-gong-dao-by-leetcode-solution-lehy/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。