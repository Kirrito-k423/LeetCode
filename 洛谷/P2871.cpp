#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
// const int N=1E5+10,M=210;

int W[4000];
int D[4000];
int f[4000];

int main(){
	int N,M;
	int answer = 0;
	cin >> N >> M;
	int i = N;
	while(i--){
		int index = N-1-i;
		cin >> W[index] >> D[index];
	}
	for(i = 0; i < N; i++){
		for(int j = M-1; j >=0 ; j--){
			if(j>=W[j])
				f[j] = max(f[j], f[j-W[i]]+D[i]);
		}
	}

	cout << f[M-1] << endl;
}