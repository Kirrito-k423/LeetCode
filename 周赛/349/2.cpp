#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;

#define findingNoneA 0
#define down 1
class Solution {
public:
    string smallestString(string s) {
        //第一个非a的连续子字符串
        int status = findingNoneA;
        for(auto && c:s){
            if(status == findingNoneA){
                if( c=='a'){
                    continue;
                }else{
                    status = down;
                    c-=1;
                }
            }else if(status==down){
                if( c=='a'){
                    return s;
                }else{
                    c-=1;
                }
            }
        }
        if(status == findingNoneA){
            //last a to z
            s[s.size()-1]='z';
        }
        return s;

    }
};