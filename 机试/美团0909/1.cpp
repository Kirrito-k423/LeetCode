#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	string input;
    int k;
	cin >> input;
	cin >> k;
	// k <= 5
	vector<string> aTo(5);
	vector<string> bTo(5);
	vector<string> cTo(5);

	string pre = "a";
	for(int i=0; i<5; i++ ){
		string toWidth;
		for(auto c : pre){
			if(c=='a'){
				toWidth += "bc";
			}else if (c=='b'){
				toWidth += "ca";
			}else{
				toWidth += "ab";
			}
		}
		aTo[i]=toWidth;
		pre = toWidth;
	}

	pre = "b";
	for(int i=0; i<5; i++ ){
		string toWidth;
		for(auto c : pre){
			if(c=='a'){
				toWidth += "bc";
			}else if (c=='b'){
				toWidth += "ca";
			}else{
				toWidth += "ab";
			}
		}
		bTo[i]=toWidth;
		pre = toWidth;
	}

	pre = "c";
	for(int i=0; i<5; i++ ){
		string toWidth;
		for(auto c : pre){
			if(c=='a'){
				toWidth += "bc";
			}else if (c=='b'){
				toWidth += "ca";
			}else{
				toWidth += "ab";
			}
		}
		cTo[i]=toWidth;
		pre = toWidth;
	}

	string answer;
	for(auto &c: input){
		if(c=='a'){
			answer += aTo[k-1];
		}else if (c=='b'){
			answer += bTo[k-1];
		}else{
			answer += cTo[k-1];
		}
	}
	cout << answer << endl;
}
// 64 位输出请用 printf("%lld")