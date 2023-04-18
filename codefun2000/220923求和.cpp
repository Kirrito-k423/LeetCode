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

int N;
int A[200];
int answer = 0;
int totalSum = 0;
int halfTotalSum = 0;

void subArray(int i, int & tmpSum){
	if(tmpSum==halfTotalSum){
		answer ++;
		return;
	}else if(tmpSum>halfTotalSum || i>=N){
		return;
	}
	tmpSum += A[i];
	subArray(i+1, tmpSum);
	tmpSum -= A[i];
	subArray(i+1, tmpSum);
}

int main(){

	cin >> N;
	int i = N;
	while(i--){
		cin >> A[i];
		totalSum += A[i];
	}
	halfTotalSum = totalSum/2;
	int tmpSum = 0;
	subArray(0, tmpSum);

	cout << answer << endl;
}