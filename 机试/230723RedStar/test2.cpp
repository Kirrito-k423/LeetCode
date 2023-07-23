#include <bits/stdc++.h>

using namespace std;

bool flower_num(int i){
	int sum = 0;
	int target = i;
	while(i>0){
		int lower_num = i%10;
		sum += pow(lower_num,3);
		i = i/10;
	}
	return sum == target;
}

int main(){
	int begin, end;
	while(cin >> begin >> end) {
		bool have_flower_num = false;
		for(int i = begin; i <=end; i++){
			if(flower_num(i)){
				have_flower_num = true;
				cout << i << " ";
			}
				
		}
		if(!have_flower_num)  cout << "no";
		cout << endl;
	}
	return 0;
}