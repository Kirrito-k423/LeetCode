#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        int countZeroEnd = 0;
        int n = num.length();
        for(int i = n-1 ; i >= 0 ; i--){
            if(num[i] != '0') break;
            else countZeroEnd++;
        }
        return num.substr(0, n-countZeroEnd);
    }
};