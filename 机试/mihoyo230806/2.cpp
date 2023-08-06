#include <bits/stdc++.h>
using namespace std;

int tmp_result(vector<int> &monster){
	int n = monster.size();
	int result = 0;
	int cur_heita_strike = 0;
	for(int i=0; i<n; i++){
		int drop = monster[i] - cur_heita_strike;
		if(drop <= monster[i]/2){
			monster[i] = max(0,drop);
		}else{
			result += drop - monster[i]/2;
			monster[i] = monster[i]/2;
		}
		cur_heita_strike++;
	}
	// add rest
	for(int i=0; i<n; i++){
		result += max(0, monster[i]-(n-i));
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int> input(n,0);
	for(int i=0; i<n; i++){
		cin >> input[i];
	}


	vector<int> monster(input.begin(), input.end());
	// 贪心：优先触发各位置的half效果
	sort(monster.begin(), monster.end());
	int result1 = tmp_result(monster);
	monster = vector<int>(input.begin(), input.end());
	sort(monster.begin(), monster.end(),std::greater<int>());
	int result2 = tmp_result(monster);
	cout << min(result1,result2);
}
// 64 位输出请用 printf("%lld")

// 33% pass ?