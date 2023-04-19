#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;


int main(){
	int N;
	// int answer = 0;
	cin >> N;
	vector<int> value(N);
	vector<vector<int>> adList(N);
	int i = N;
	while(i--){
		int id;
		int parent;
		int val;
		cin >> id >> parent >> val;
		value[id]=val;
		if(parent!=-1){
			adList[parent].push_back(id);
		}
	}
	vector<int> memoryValue(N,INT_MIN);
	function<int(int)> dfs = [&](int id) {
		int &result = memoryValue[id];
		if(result!=INT_MIN) return result;
		result = value[id];
		int maxSub = 0;
		for(auto &x:adList[id]){
			int subSum = dfs(x);
			maxSub = max(maxSub,subSum);
		}
		result += maxSub;
		return result;
	};

	for(i=0; i<N; i++){
		dfs(i);
	}

	cout << *max_element(memoryValue.begin(),memoryValue.end()) << endl;
}

