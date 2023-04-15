#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
		int n = queries.size();
		vector<bool> result(n,true);
		for(int i = 0; i < n; i++) {
			string& query = queries[i];
			if(query.size() < pattern.length()){
				result[i] = false;
				continue;
			}
			int index = 0; // query index
			int j = 0;
			for(;  index < query.size(); index++) {
				if(j < pattern.length() && query[index] == pattern[j]) {
					j++;
					continue;
				}
				if(query[index]  < 'a'){
					result[i] = false;
					break;
				}
			}
			if(j < pattern.size()){
				result[i] = false;
			}
		}
		return result;
    }
};

int main(){
	Solution solution;
	vector<string> queries = {"FooBar"};
	string pattern = "FB";
	solution.camelMatch(queries, pattern);
}