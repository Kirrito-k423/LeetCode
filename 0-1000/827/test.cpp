#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    const vector<vector<int>> drc = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    void dfs(int x, int y, int mark, vector<vector<int>>& grid, int& count) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return;
        if (grid[x][y] != 1) return;
        grid[x][y] = mark;
        ++count;
        for (int i = 0; i < 4; ++i) {
            dfs(x + drc[i][0], y + drc[i][1], mark, grid, count);
        }
    }
    int color(vector<vector<int>>& grid, unordered_map<int, int>& record) {
        int N = grid.size(), M = grid[0].size(), mark = 2;
        int count, zeroCount = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) {
                    count = 0;
                    dfs(i, j, mark, grid, count);
                    record[mark++] = count;
                }
                else if (grid[i][j] == 0) {
                    ++zeroCount;
                }
            }
        }
        return zeroCount;
    }
    void bt(int x, int y, int num, vector<vector<int>>& grid,
        unordered_map<int, int>& record, unordered_set<int>& used, int& answer) {
        if (num == 0) return;
        for (int i = x, j = y; i < grid.size(); ++i) {
            for (; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) continue;
                vector<int> contribute;
                int newI, newJ;
                // 该点四个方向探索, 记录是否有贡献, 使得连接了额外的连通域
                for (int k = 0; k < 4; ++k) {
                    newI = i + drc[k][0]; newJ = j + drc[k][1];
                    if (newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size())
                        continue;
                    if (grid[newI][newJ] != 0 && used.count(grid[newI][newJ]) == 0) {
                        contribute.emplace_back(grid[newI][newJ]);
                        used.insert(grid[newI][newJ]);
                    }
                }
                // 如果贡献为0, 则没有在这个点展开往下搜索的价值
                if (contribute.size() != 0) {
                    int ret = 0; for (auto& mark : used) ret += record[mark];
                    answer = max(answer, ret);
                    bt(i, j + 1, num - 1, grid, record, used, answer);
                    for (auto& mark : contribute) used.erase(mark);
                }
            }
            j = 0;
        }
    }
    int largestIslandGivenChangeNum(vector<vector<int>>& grid, int ChangeNum) {
        unordered_map<int, int> record;
        int zeroCount = color(grid, record);
        //display(grid);
        //for (auto& data : record) cout << data.first << ' ' << data.second << endl;
        if (zeroCount <= ChangeNum) return grid.size() * grid[0].size();
        unordered_set<int> used;
        int answer = 0;
        bt(0, 0, ChangeNum, grid, record, used, answer);
        return answer + ChangeNum;
    }
    int largestIsland(vector<vector<int>>& grid) {
        // 本题中传入1, 因为只有一次变更机会
        return largestIslandGivenChangeNum(grid, 1);
        // 华为笔试题中传入2, 因为有两次变更机会
        //return largestIslandGivenChangeNum(grid, 2);
    }
    void display(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) cout << grid[i][j] << ' ';
            cout << endl;
        }
    }
};

// 作者：wwhatever
// 链接：https://leetcode.cn/problems/making-a-large-island/solutions/1834732/hua-wei-by-hungry-diracrge-muyr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。