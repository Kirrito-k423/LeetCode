#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cstring> // memset
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <iostream> // std::cout endl
using namespace std;

int answer = 0;

int main(){
	int N;
	int W[20];
	cin >> N;
	int i=N;
	while(i--){
		cin >> W[i];
	}

	int kinds = 1<<N;
	for(i=0;i<kinds;i++){
		int Tazi = 0;
		int TaziFalse = 0;
		int kozi = 0;
		for(int j=0;j<N;j++){
			if(((i>>j)&1)==1){
				//chose Tazi
				Tazi += W[j];
				TaziFalse ^= W[j];
			}else{
				kozi ^= W[j];
			}
		}
		if(kozi!=0 && kozi == TaziFalse){
			answer = max(answer,Tazi);
		}
	}
	if (answer == 0){	
		cout << "NO" << endl;
	}else{
		cout << answer << endl;
	}
}