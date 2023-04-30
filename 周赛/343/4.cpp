#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> subLoopStr;
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
		//判断出s中是否有回文子串，要优先消除
		//利用桶加速寻找字串
		vector<vector<int>> alphaBucket(26,vector<int>(0));
		int n = s.length();
		for(int i = 0; i < n; i++){
			char &x = s[i];
			alphaBucket[x-'a'].push_back(i);
		}
		//寻找子回文串
		for(int i = 0; i < n; i++){
			char &x = s[i];
			int beginI = i;
			for(auto  endIndex : alphaBucket[x-'a']){
				if(endIndex > beginI){
					while(endIndex > i){
						if(s[beginI] == s[endIndex]){
							beginI++;
							endIndex--;
						}else{
							break;
						}
					}
					if(i<=endIndex){
						//finded
						
					}
				}
			}
		}

		//没有就消除末尾
    }
};