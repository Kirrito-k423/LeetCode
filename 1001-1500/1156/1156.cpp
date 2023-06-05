#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        //交换字符肯定是不同的字符
        int alphaCount[27];
        memset(alphaCount, 0, sizeof(alphaCount));
        for(char & c :text){
            alphaCount[c-'a']++;
        }
        int n = text.size();
        int result = INT_MIN;
        alphaCount[26]=INT_MAX;
        char curChar = 'z'+1;
        char changeChar = 'a';
        int nextI = 0;
        int curCount = 0;
        int status = 0; //0 is do nothing; 1 is exchanged
        int i;
        for(i=0; i<n; i++){
            if(curChar!=text[i]){
                if(status==0){
                    if(curCount < alphaCount[curChar-'a']){
                        status = 1;
                        nextI = i;
                        result = max(result,curCount+status);
                    }else{
                        // none 2 change
                        result = max(result,curCount+status);
                        curChar=text[i];
                        curCount=1;
                        status=0;
                    }
                }else{
                    i=nextI;
                    curChar=text[i];
                    curCount=1;
                    status=0;
                }
            }else{
                curCount++;
                if(curCount+status<=alphaCount[curChar-'a']){
                    result = max(result,curCount+status);
                }
            }
        }
        if(curCount<alphaCount[curChar-'a'] && status==0){
            result = max(result,curCount+1);
        }
        return result;
    }
};