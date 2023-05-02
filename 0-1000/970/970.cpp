#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
		set<int> result;
		int Y = 1;
		for(; Y + 1 <= bound; Y *= y){
			int X = 1;
			for(; X + Y <= bound; X *= x){
				result.insert(X+Y);
				if(x==1) break;
			}
			if(y==1) break;

		}
		return vector<int>(result.begin(), result.end());
    }
};