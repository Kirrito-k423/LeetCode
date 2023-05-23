#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        string toCompare = s;
        reverse(toCompare.begin(), toCompare.end());
        int n = toCompare.size();
        for (int i = 0; i < n/2; i++) {
            if(s[i]!=toCompare[i]){
                char minVal = min(s[i],toCompare[i]);
                s[i] = minVal;
                s[n -1-i]=minVal;
            }
        }
        return s;
    }
};