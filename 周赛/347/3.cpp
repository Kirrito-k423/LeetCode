#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long all2Char(string s, char target){
        int n = s.size();
        long long result = 0;
        if(n%2==0){
            int findFlag = 0;
            for(int i=n/2-1; i>=0; i--){
                if(!findFlag){
                    if(s[i]!=target){
                        findFlag=1;
                        result+=i+1;
                    }
                }else{
                    if(s[i]!=s[i+1]){
                        result+=i+1;
                    }
                }   
            }
            findFlag = 0;
            for(int i=n/2; i<n; i++){
                if(!findFlag){
                    if(s[i]!=target){
                        findFlag=1;
                        result+=n-i;
                    }
                }else{
                    if(s[i]!=s[i-1]){
                        result+=n-i;
                    }
                }   
            }
            return result;
        }else{
            long long result1=0;
            long long result2=0;
            int findFlag = 0;
             for(int i=n/2-1; i>=0; i--){
                if(!findFlag){
                    if(s[i]!=target){
                        findFlag=1;
                        result1+=i+1;
                    }
                }else{
                    if(s[i]!=s[i+1]){
                        result1+=i+1;
                    }
                }   
            }
            findFlag = 0;
            for(int i=n/2; i<n; i++){
                if(!findFlag){
                    if(s[i]!=target){
                        findFlag=1;
                        result1+=n-i;
                    }
                }else{
                    if(s[i]!=s[i-1]){
                        result1+=n-i;
                    }
                }   
            }
            findFlag = 0;
            for(int i=n/2; i>=0; i--){
                if(!findFlag){
                    if(s[i]!=target){
                        findFlag=1;
                        result2+=i+1;
                    }
                }else{
                    if(s[i]!=s[i+1]){
                        result2+=i+1;
                    }
                }   
            }
            findFlag = 0;
            for(int i=n/2+1; i<n; i++){
                if(!findFlag){
                    if(s[i]!=target){
                        findFlag=1;
                        result2+=n-i;
                    }
                }else{
                    if(s[i]!=s[i-1]){
                        result2+=n-i;
                    }
                }   
            }
            return min(result1, result2);

        }
    }
    long long minimumCost(string s) {
        return min(all2Char(s, '1'),all2Char(s, '0'));
    }
};