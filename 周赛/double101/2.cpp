#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>

#define UP 0
#define DOWN 1
using namespace std;
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n=s.size();
        int index=0;
        //确定各字母价值
        int value[26]={0};
        for(int i=0;i<26;i++){
            value[i]=i+1;
        }
        for(int i=0;i<chars.size();i++){
            value[chars[i]-'a']=vals[i];
        }
        //去除初始0
        while(index<n && value[s[index]-'a']<=0){
            index++;
        }
        int ans = 0;
        int sum = 0;
        int downSum = 0;
        int status = UP; //0 up 1 down
        for(;index<n;index++){
            if(status==UP){
                if(value[s[index]-'a']>=0)
                    sum+=value[s[index]-'a'];
                else{
                    status=DOWN;
                    ans = max(ans, sum);
                    sum+=value[s[index]-'a'];
                }
            }else if(status==DOWN){
                if(value[s[index]-'a']>=0){
                    status=UP;
                    if(sum<0)
                        sum=0;
                    sum+=value[s[index]-'a'];
                }
                else{
                    sum+=value[s[index]-'a'];
                }
            }
        }
        ans = max(ans, sum);
        return ans; 
    }
};