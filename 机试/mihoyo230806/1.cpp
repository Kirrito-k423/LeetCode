#include <bits/stdc++.h>
using namespace std;

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }
	int t;
	cin >> t;
	int result = 0;
	while(t--){
		int word_num;
		cin >> word_num;
		vector<string> input;
		for(int i = 0; i < word_num; i++){
			string tmp;
			cin >> tmp;
			input.emplace_back(tmp);
		}
		//check response
		int score = 0;
		bool flag = true;
		for(int i = 0; i < word_num; i++){
			string tmp;
			cin >> tmp;
			if(tmp != input[i]){
				score--;
				// cout << "score:" << score << endl;
			}else{
				//==
				score++;
				// cout << "score:" << score << endl;
			}
			if(score<0){
				flag = false;
				// break;
			}
		}
		if(flag) result++;
		// cout << "result:" << result << endl;

	}
	cout << result;
}
// 64 位输出请用 printf("%lld")