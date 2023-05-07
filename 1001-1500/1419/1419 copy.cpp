#include <bits/stdc++.h>

using namespace std;

#define ci 0
#define ri 1
#define oi 2
#define ai 3
#define ki 4

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // 模拟有几只青蛙在叫
        int frogs[5];
        map<char, int> preFrog = {{'c',ki},{'r',ci},{'o',ri},{'a',oi},{'k',ai}};
        map<char, int> curFrog = {{'c',ci},{'r',ri},{'o',oi},{'a',ai},{'k',ki}};
        memset(frogs, 0, sizeof(frogs));
        for(char & x : croakOfFrogs){
            if(x == 'c')
                if(frogs[preFrog[x]]==0){
                    frogs[curFrog[x]]++;
                }else{
                    frogs[preFrog[x]]--;
                    frogs[curFrog[x]]++;
                }
            else{
                if(frogs[preFrog[x]]==0){
                    return -1;
                }else{
                    frogs[preFrog[x]]--;
                    frogs[curFrog[x]]++;
                }
            }
        }
        if(frogs[0]==0 &&frogs[1]==0 &&frogs[2]==0 &&frogs[3]==0){
            return frogs[4];
        }
        return -1;
    }
};

// int main(){
// 	Solution solution;
// 	cout << solution.minNumberOfFrogs("croakcroak")<< endl;
// }