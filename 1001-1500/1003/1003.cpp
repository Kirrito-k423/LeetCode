#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> prefix;
		function<bool(char)> popTarget = [&prefix](char c) {
			if(prefix.empty()) return false;
			if(prefix.top() == c){
				prefix.pop();
				return true;
			} 
			return false;
		};
		for(auto &x : s){
			if(x=='a'||x=='b'){
				prefix.push(x);
			}else if(x=='c'){
				if(popTarget('b') && popTarget('a')){
					continue;
				}else{
					return false;
				}
			}
		}
		if(prefix.empty())
			return true;
		else return false;
    }
};