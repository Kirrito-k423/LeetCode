#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n);
        original[0]=0;
        for (int i = 0; i < n-1; ++i) {
            original[i+1]=original[i]^derived[i];
        }
        if(original[n-1]^derived[n-1]==0){
            return true;
        }else{
            return false;
        }
    
    }
};