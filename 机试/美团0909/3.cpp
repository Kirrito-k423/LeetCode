	#include <iostream>
	#include <bits/stdc++.h>
	using namespace std;

	#define empty 'x'
	int main() {
		int n, k;
		cin >> n >> k;
		vector<char> rest;
		string input;
		cin >> input;
		char pre = empty;
		int i = 0;
		for(auto & tmp:input){
			if(pre == empty){
				pre = tmp;
			}else if(pre == tmp){
				if(rest.size()==0)
					pre = empty;
				else{
					pre = rest[rest.size()-1];
					rest.pop_back(); // 78.57%
				}
			}else{
				rest.push_back(pre);
				pre = tmp;
			}
		}
		// tail entry
		if(pre!=empty){
			rest.push_back(pre);
		}
		// 必须修改k个元素
		// 修改与删除 可以交换执行顺序
		// 删除后肯定是余下01交替串长度为R,
		// R > 2k: k个元素，可以额外消除2k个
		// 问题： 我可以修改同一个元素吗？0->1->0->1 这种？
		// if yes, 
		// cout << rest.size() << " ";
		if(rest.size()>=2*k){
			cout << rest.size()-2*k << endl;
		}else if(rest.size()%2==0){
			int restk = k - rest.size()/2;
			// cout << restk << " ";

			cout << ((restk%2)==0)?"0":"2"; // 100%
			if(restk%2==0){
				cout << "0";
			}else{
				cout << "2";
			}
		}else{
			// rest.size()%2==1
			int restk = k - rest.size()/2;
			// if no
			// cout << 1 + (restk%2==1)?0:2;
			// if yes
			cout << 1 ;

		}
		// 78% ??

	}
	// 64 位输出请用 printf("%lld")