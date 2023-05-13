#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = 0;
        for (string &person : details){
            int age = stoi(person.substr(11,2));
            if(age > 60) result++;
        }      
        return result;
    }
};