#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> countMap;
        set<char> uniqueSet;
        for(char & x: tiles){
            countMap[x]++;
            uniqueSet.insert(x);
        }
        int n = tiles.size();

        function<int(int)> dfs = [&dfs, &n, &countMap, &uniqueSet](int i){
            int res = 1;
            if(i==n) return res;
            for(auto & x : uniqueSet){
                if(countMap[x]>0){
                    countMap[x]--;
                    res += dfs(i+1);
                    countMap[x]++;
                }
            }
            return res;
        };
        return dfs(0)-1;
    }
};