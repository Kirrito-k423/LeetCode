#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;


class Solution {
public:
    bool isFascinating(int n) {
        int count[10];
        memset(count, 0, sizeof(count));
        function<bool(int)> fancy = [&count](int input){
            while(input!=0){
                int tmp = input % 10;
                input /= 10;
                if(tmp==0)
                    return false;
                else if(count[tmp]==0){
                    count[tmp]++;
                }else{
                    return false;
                }
            }
            return true;
        };
        if(fancy(n) && fancy(2*n) && fancy(3*n)){
            for(int i=1; i<10; i++){
                if(count[i]!=1){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};