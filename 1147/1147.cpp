#include <string>

using namespace std;
class Solution {
public:
    int longestDecomposition(string text) {
		int n = text.size();
		int k = 0;
		int pair_head = 0;
		int pair_tail = n-1-0;
		for(int i=0; i<n/2; i++){
			//cur pointer 
			//暴力匹配
			bool bingo = true;
			for(int j=0; j<=i-pair_head; j++){
				if(text[pair_head+j]!=text[pair_tail-(i-pair_head)+j]){
					bingo = false;
					break;
				}
			}
			if(bingo){
				k++;
				pair_head = i+1;
				pair_tail = n-1-(pair_head);
			}
		}
		if(pair_head<=pair_tail)
			return 2*k+1;
		else
			return 2*k;
    }
};