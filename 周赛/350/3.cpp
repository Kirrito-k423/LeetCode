#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        //1. 转换：将数字变成无向图的点，图中的边代表两者有整除关系
        //2. 计算：无向图上一笔画通过所有点的总画法，
        //图中没有边的点，否则return 0
        //边数为1边的点不超过3 个，否则return 0
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int graph[14][14];
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i != j && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)) {
                    graph[i][j]=1;
                    graph[j][i]=1;
                }
            }
        }

    }
};