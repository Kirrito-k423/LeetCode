#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int score(vector<int>& player){
		int n = player.size();
		int sum = 0;
		for(int i = 0; i < 2 && i< n; i++)
			sum += player[i];
		if(n>=2){
			if(player[0]==10)
				sum += player[1];
		}

		for(int i = 2; i < n; i++){
			if(player[i-1]==10 || player[i-2]==10){
				sum += player[i]*2;

			}else{
				sum += player[i];
			}
		}
		return sum;
	}
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = score(player1);
		int score2 = score(player2);
		return score1 == score2?0:(score1 > score2? 1:2);
    }
};