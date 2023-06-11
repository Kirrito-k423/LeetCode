#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        map<vector<int>, int> gridMap;
        for (int i = 0; i < m; i++) {
            gridMap[grid[i]] = i;
        }
        int mm = gridMap.size();
        

        vector<int> rows(m);
        for (int i = 0; i < m; i++) {
            rows[i] = i;
        }
        vector<int> goodSubset;
        // 调用回溯函数开始生成所有子集
        vector<int> subset;
        
        // 判断子集是否是好子集的函数
        function<bool()> isGoodSubset = [&]() {
            vector<int> colSums(n, 0);
            for (int row : subset) {
                auto it = gridMap.begin();
                advance(it, row);  // 将迭代器移动到第三个位置
                for (int col = 0; col < n; col++) {       
                    colSums[col] += (it->first)[col];
                    if (colSums[col] > subset.size() / 2) {
                        return false;
                    }
                }
            }
            if(!subset.empty())return true;
            return false;
        };
        
        // 回溯函数，生成所有可能的子集
        function<bool(int)> backtrack = [&](int start) {
            if (isGoodSubset()) {
                goodSubset = subset;
                return true;
            }
            for (int i = start; i < mm; i++) {
                subset.push_back(i);
                if(backtrack(i + 1))
                    return true;
                subset.pop_back();
            }
            return false;
        };
        
        
        backtrack(0);
        vector<int> result;
        for(auto & index: goodSubset){
            auto it = gridMap.begin();
            advance(it, index);
            result.push_back(it->second);
        }
        
        return goodSubset;
    }
};

int main(){
	Solution solution;
	vector<vector<int>> edges = {{0,1},{0,1},{0,1},{1,1},{1,1},{0,0},{1,1},{1,1} };

	solution.goodSubsetofBinaryMatrix(edges);
}