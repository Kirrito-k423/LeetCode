#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        //二维DP，[i,j] 区间内的最大值与非叶节点的值的最小可能总和
        int n = arr.size();
        vector<vector<pair<int,int>>> memory(n, vector<pair<int,int>>(n,{0,0}));
        // memset(memory, 0, sizeof(memory)); //??

        function<pair<int,int>(int,int)> dfs = [&](int left, int right){
            pair<int,int> &curStatus = memory[left][right];
            int &subMax = curStatus.first;
            int &subSum = curStatus.second;
            if(subMax!=0) return curStatus;
            if(left==right){
                subMax = arr[left];
                subSum = 0;
            }else{
                subSum = INT_MAX;
                for(int i=left; i<right; i++){
                    auto leftNode = dfs(left,i);
                    auto rightNode = dfs(i+1, right);
                    int nonLeafSum = rightNode.second + leftNode.second + leftNode.first*rightNode.first;
                    int tmpSum = max(leftNode.first,rightNode.first);
                    if(subSum > nonLeafSum || (subSum == nonLeafSum && tmpSum<subMax)){
                        subSum = nonLeafSum;
                        subMax = tmpSum;
                    }
                }
            }
            return curStatus;
        };

        return dfs(0, n-1).second;
    }
};