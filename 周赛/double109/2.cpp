#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E5+10,M=210;

class Solution {
public:
	std::size_t type(char input){
		// unordered_map<char,int> alpha = {{'A',0}, {'E',1}, {'I',2}, {'O',3}, {'U',4},
		// 								{'a',5}, {'e',6}, {'i',7}, {'o',8}, {'u',9}};
		string vowel = "AEIOUaeiou";
		return vowel.find(input);
	}
    string sortVowels(string s) {
        // count 'a' ，'e' ，'i' ，'o' 和 'u' nums
		// postion to fill
		int count_alpha[10];
		memset(count_alpha, 0, sizeof(count_alpha));
		vector<int> position2fill;
		int n = s.size();
		for(int i=0; i<n; i++){
			std::size_t type0 = type(s[i]);
			if(type != std::string::npos){
				 count_alpha[type0]++;
				 position2fill.emplace_back(i);
			  }
		}
		char change[10] = {"AEIOUaeiou"};
		function<char()> pop_alpha = [&count_alpha,&change](){
			int i = 0;
			while(count_alpha[i]<=0){
				i++;
			}
			count_alpha[i]--;
			return change[i];
		};
		for(auto & change_position : position2fill){
			s[change_position] = pop_alpha();
		}
		return s;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }