#include<bits/stdc++.h>

using namespace std;



int main(){
	int n;
	int m;
	int k;
	cin >> n >> m >> k;
	long long result = 0;
	int li,ri;
	typedef  int left;
	typedef  int right;
	vector<pair<left,right>> tofill;
	while(cin >> li >> ri){
		tofill.emplace_back(make_pair(li,ri));
		result = max(result, (long long)ri-li);
	}
	if(k <= result){
		cout << min((long long)k,result) << endl;
		return 0;
	} 
	sort(tofill.begin(), tofill.end());
	int sum_array[tofill.size()];
	for(int i = 0; i < tofill.size()-1; i++){
		sum_array[i] += tofill[i].second- tofill[i].first;
		sum_array[i+1] += sum_array[i];
	}
	int end_index = tofill.size()-1;
	sum_array[end_index] += tofill[end_index].second- tofill[end_index].first;
	for(int i=0; i<tofill.size(); i++){
		int limit_up = tofill[i].first + k;
		long long sum = 0;
		// int j = i;

		auto it = lower_bound(tofill.begin(), tofill.end(),limit_up,[](auto a, int value){
			a.first 
		});
		while(j<tofill.size() && tofill[j].first < limit_up){			
			if(limit_up<tofill[j].second){
				sum += limit_up-tofill[j].first;
				break;
			} 
			else{
				sum += tofill[j].second-tofill[j].first;
				j++;
			}
		}
		result = max(result,sum);
	}
	cout << min((long long)k,result) << endl;
}