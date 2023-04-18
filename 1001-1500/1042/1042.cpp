#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
class Solution {
public:
	// static set<int> color = {1,2,3,4};
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
		//turn to Adjacency List
		int AdjacencyList[n+1][3];
		int degree[n+1];
		memset(AdjacencyList, 0, sizeof(AdjacencyList));
		memset(degree, 0, sizeof(degree));
		for(auto & side: paths) {
			int &n1 = side[0];
			int &n2 = side[1];
			AdjacencyList[n1][degree[n1]] = n2; 
			AdjacencyList[n2][degree[n2]] = n1;
			degree[n1]++; degree[n2]++;
		}
		vector<int> answer(n+1,0);
		for(int i = 1; i <n+1; i++) {
			int exception = 1|(1 << answer[AdjacencyList[i][0]])|
			 (1 << answer[AdjacencyList[i][1]])|
			  (1 << answer[AdjacencyList[i][2]]);
			int choice = 0;
			while(exception % 2==1) {
				exception = exception >> 1;
				choice++;
			}
			answer[i] = choice;
		}
		return vector<int>(answer.begin()+1, answer.end());
    }
};