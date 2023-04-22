#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;


class Solution {
public:
    int adventureCamp(vector<string>& expeditions) {

		unordered_set<string> passed;
		function<int(int)> subCampus = [&passed, &expeditions](int p) {
			int newCount = 0;
			int begin = 0;
			string &toCutString = expeditions[p];
			for(int i=0; i< toCutString.length(); i++){
				if(toCutString[i]=='-'){
					string cut = toCutString.substr(begin, i-begin);
					begin = i+2; i++;
					if(!passed.count(cut)){
						passed.insert(cut);
						newCount++;
					}
				}else if(i==toCutString.length()-1){
					string cut = toCutString.substr(begin, i-begin+1);
					// begin = i+2; i++;
					if(!passed.count(cut)){
						passed.insert(cut);
						newCount++;
					}
				}
			}
			return newCount;
		};
		int n = expeditions.size();
		subCampus(0);
		int maxCount = 0;
		int resultIndex = 0;
		for(int i=1; i<n; i++){
			int countI = subCampus(i);
			if(countI>maxCount){
				maxCount = countI;
				resultIndex = i;
			} 
		}
		if(maxCount==0)
			return -1;
		else
			return resultIndex;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }