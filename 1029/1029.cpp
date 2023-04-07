#include <iostream>
#include <vector>
#include <cstring>
#include <string>
// #include <bits/stdc++.h>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> longestCommonSubsequence(string &text1, string &text2) {
        int n1 = text1.size(), n2 =text2.size();
        vector<vector<int>> dp(n1+1 , vector<int>(n2+1));
        for(int i=1; i<=n1; i++){
            char c1 = text1[i-1];
            for(int j=1; j<=n2; j++){
                char c2 =text2[j-1];
                if(c1==c2){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        vector<int> pool;
        int i=n1;
        int j=n2;
        for(int q=0; q<dp[n1][n2];){
            if(text2[j-1]==text1[i-1]){
                assert(text2[j-1]==text1[i-1]);
                pool.push_back(text2[j-1]);
                i--; j--;
                q++;
            }else if(dp[i][j] == dp[i-1][j]){
                i--;
            }else{
                j--;
            }
        }
        reverse(pool.begin(),pool.end());
        return pool;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        //最长公共子序列的补集
        //text2的公共index
        vector<int> str2List = longestCommonSubsequence(str1, str2);
        string result;
        int sameN = str2List.size();
        int samei = 0;
        int str2N = str2.size();
        int str2i = 0;
        for(auto & x:str1){
            if(samei < sameN && x!=str2List[samei]){
                result += x;
            }else{
                for(;str2i<str2N;str2i++){
                    if(str2[str2i]!=x){
                        result += str2[str2i];
                    }else{
                        break;
                    }
                }
                result += x; str2i++;
                samei++;
            }
        }
        for(;str2i<str2N;str2i++){
            result += str2[str2i];
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.shortestCommonSupersequence("bbbaaaba", "bbababbb") << endl;
}