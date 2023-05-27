#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dirs[8][2] = {1, 0 , -1, 0, 0, 1, 0, -1,
                       1, 1 , -1, 1, 1, -1, -1, -1 };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int distance[n][n];
        memset(distance, -1, sizeof(distance));
        queue<pair<int,int>> curMinNode;
        queue<pair<int,int>> nextNode;
        pair<int,int> node0 = {0,0};
        if(grid[0][0]==0){
            curMinNode.push({0,0});
            distance[0][0]=1;
        }
        function<bool(int,int)> check = [&grid, &n](int x, int y){
            return x >= 0 && y >= 0 && x < n && y < n && grid[x][y]==0;
        };
        int curDis = 1;
        while(!curMinNode.empty()) {
            curDis++;
            while(!curMinNode.empty()) {
                auto node = curMinNode.front();
                curMinNode.pop();
                int curX = node.first;
                int curY = node.second;
                for(auto &[addx, addy]: dirs){
                    int nextX = curX + addx;
                    int nextY = curY + addy;
                    if(!check(nextX, nextY)) continue;
                    if(distance[nextX][nextY]==-1){
                        distance[nextX][nextY]=curDis;
                        nextNode.push({nextX,nextY});
                    }
                }
            }
            swap(curMinNode, nextNode);
        }

        if(distance[n-1][n-1] == -1){
            return -1;
        }else{
            return distance[n-1][n-1];
        }
    }
};