
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> alphaIndexList{26, std::vector<int>(0)};
    vector<vector<int>> alphaIndexListComplementary{26,vector<int>(0)};
    void DP(string &s, string &t, int i, int &result){
        int N = s.size();
        if(i>=N) return;
        //result 添加包含s[i]的子字符串
        for(int j=0; j<=i; j++){
            //s[i-j] 与t中元素不同
            int beginI = i;
            vector<int>* todo;
            //初始化判断队列
            if(j==0){
                todo= &alphaIndexListComplementary[s[i]-'a'];
            }else{
                todo= &alphaIndexList[s[i]-'a'];
            }
            // result += (*todo).size();
            for(auto &tIndex:*todo){
                int searchSubI=0;
                while(i-searchSubI >= 0 && tIndex-searchSubI >= 0){
                    if(searchSubI==j){
                        //与t不同
                        if(s[i-searchSubI]!=t[tIndex-searchSubI]){
                            result++;
                            searchSubI+=1;
                            continue;
                        }else break;   
                    }else{
                        //与t相同
                        if(s[i-searchSubI]==t[tIndex-searchSubI]){
                            if(searchSubI > j)result++;
                            searchSubI+=1;
                            continue;
                        }else break;  
                    }
                    searchSubI+=1;
                }
                
            }
        }
        DP(s, t, i+1, result);
    }
    int countSubstrings(string s, string t) {
        
        //t < s
        if(s.size()<t.size()){
            swap(s,t);
        }
        for(int i=0; i<t.size(); i++){
            alphaIndexList[t[i]-'a'].push_back(i);
            for(int j=0; j<26; j++){
                if(j!=t[i]-'a')
                    alphaIndexListComplementary[j].push_back(i);
            }
        }
        int result = 0;
        DP(s, t, 0, result);
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.countSubstrings("abab", "aba")<<endl;
    // cout<<s.countSubstrings("abab", "bba")<<endl;
}