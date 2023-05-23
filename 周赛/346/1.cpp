#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> restS;
        vector<char> toErase(s.begin(),s.end());
        int flag = 1;
        while(flag>0){
            for(char &x : toErase){
                if(!restS.empty()){
                    char topVal = restS.top();
                    if(x=='B' && topVal=='A'){
                        flag++;
                        restS.pop();
                    }else if(x=='D' && topVal=='C'){
                        flag++;
                        restS.pop();
                    }else{
                        restS.push(x);
                    }
                }else{
                    restS.push(x);
                }
            }
            toErase.clear();
            while(!restS.empty()){
                toErase.push_back(restS.top());
                restS.pop();
            }
            reverse(toErase.begin(), toErase.end());
            flag = 0;
        }
        return toErase.size();
    }
};