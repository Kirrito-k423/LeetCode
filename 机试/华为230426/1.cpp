#include <bits/stdc++.h>

using namespace std;


int N;

// 双队列 BFS 
int main(){
	cin >> N;
	//each point degreeOut[N] in[N] out[N]
	vector<vector<int>> in(N,vector<int>(0));
	vector<vector<int>> out(N,vector<int>(0));
	int degreeOut[N];
	queue<int> batch;
	queue<int> tmpBatch;
	for(int i=0; i<N; i++){
		int count;
		cin >> count;
		degreeOut[i] = count;
		if(count==0)
			batch.push(i);
		while(count--){
			int tmp;
			cin >> tmp;
			tmp--;
			out[i].push_back(tmp);
			in[tmp].push_back(i);
		}
	}
	int result = 0;
	if(batch.empty()){
		cout << -1 << endl;
		return 0;
	}

	while(!batch.empty()){
		result++;
		while(!batch.empty()){
			int cur = batch.front();
			batch.pop();
			for(auto &x: in[cur]){
				degreeOut[x]--;
				if(degreeOut[x]==0)
					tmpBatch.push(x);
			}
		}
		swap(batch,tmpBatch);
	}

	// 如果有degreeOut 不等于0 有环
	cout << result << endl;
	return 0;
}