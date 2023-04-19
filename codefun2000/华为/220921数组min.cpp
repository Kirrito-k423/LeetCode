#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;


int main(){
	int N, tot;
	cin >> N >> tot;
	int i = N;
	vector<int> A(N);
	while(i--){
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<int> a(A.begin(), A.end());
	for(int i=1; i<N; i++){
		a[i]+=a[i-1];
	}
	if(a[N-1]<=tot){
		cout << "-1";
		return 0;
	}
		
	int maxIndex = N-1;
	while(maxIndex >= 0 && (a[maxIndex] + A[maxIndex]*(N-1-maxIndex)>tot)){
		maxIndex--;
	}
	if(maxIndex < 0){
		cout << tot/N;
	}else{
		cout << (tot-a[maxIndex])/(N-1-maxIndex);
	}
}