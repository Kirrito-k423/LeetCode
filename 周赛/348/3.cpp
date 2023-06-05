#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        //逆序记录已经遍历的行列
        unordered_set<int> traveledLine;
        unordered_set<int> traveledColumn;
        long long result = 0;
        for(auto it = queries.rbegin(); it !=queries.rend(); it++){
            int &type = (*it)[0];
            int &index = (*it)[1];
            int &val = (*it)[2];
            if(type==1){
                if(traveledColumn.count(index)){
                    continue;
                }else{
                    traveledColumn.insert(index);
                    result += (n - traveledLine.size())*val;
                }
            }else{
                if(traveledLine.count(index)){
                    continue;
                }else{
                    traveledLine.insert(index);
                    result += (n - traveledColumn.size())*val;
                }
            }
        }
        return result;
    }
};