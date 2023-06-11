#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;


class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        //dp[i][2]    以i结尾的最长半重复 子字符串 , 第二维度记录是否已经重复

        function<int(int,bool)> dfs = [&](int index, bool isRepeat){
            if(index == 0) return 1;
            if(s[index]!=s[index-1]) return dfs(index-1,isRepeat)+1;
            else{
                //s[index]==s[index-1]
                if(isRepeat) return 1;
                else{
                    dfs(index-1,true)+1;
                }
            }
            return dfs(index-1,true)+1;
        };
        int n = s.size();
        int result = INT_MIN;
        for(int i=0; i<n; i++) {
            // result = max(result,dfs(i,true));
            result = max(result,dfs(i,false));
        }
        return result;
    }
};