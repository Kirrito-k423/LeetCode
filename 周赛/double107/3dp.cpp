#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int memory[n][26][26];
        memset(memory, -1, sizeof(memory));
        function<int(int,int,int)> dfs = [&](int curIndex, int frontC, int backC){
            int curSize = words[curIndex].size();
            int beginC = words[curIndex][0]-'a';
            int endC = words[curIndex][curSize-1]-'a';
            auto & curResult = memory[curIndex][frontC][backC];
            if(curResult != -1) return curResult;
            curResult = INF;
            if(frontC!=beginC && backC != endC){
                return curResult;
            }
            if(curIndex==0){
                if(frontC==beginC && endC==backC)
                    curResult = curSize;
                return curResult;
            }
            if(frontC==beginC){
                for(auto i=0; i<26; i++){
                    curResult = min(curResult, dfs(curIndex-1, i, backC)+curSize 
                                                -((i==endC)?1:0));
                }
            }
            if(endC==backC){
                for(auto i=0; i<26; i++){
                    curResult = min(curResult, dfs(curIndex-1, frontC, i)+curSize 
                                                -((i==beginC)?1:0));
                }
            }
            return curResult;
        };
        int result = INF;
        for(auto i=0; i<26; i++){
            int curIndex = n-1;
            int curSize = words[curIndex].size();
            int beginC = words[curIndex][0]-'a';
            int endC = words[curIndex][curSize-1]-'a';
            result = min(result,dfs(n-1,i,endC));
            result = min(result,dfs(n-1,beginC,i));
        }
        return result;
    }
};