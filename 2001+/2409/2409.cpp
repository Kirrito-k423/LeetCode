#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int monthDate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayFromNewyear(string date){
		int month = stoi(date.substr(0,2));
		int day = stoi(date.substr(3));
		if (month>1)
			return monthDate[month-2]+day;
		else
			return day;
		
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int prefixSum = 0;
		for(int i = 1; i < 12; i ++){
			monthDate[i] += monthDate[i-1];
		}
		int la = dayFromNewyear(leaveAlice);
		int lb = dayFromNewyear(leaveBob);
		int aa = dayFromNewyear(arriveAlice);
		int ab = dayFromNewyear(arriveBob);
		int result = min(la,lb) - max(aa, ab);
		if(result>=0)
        	return 1+result ;
		else
			return 0;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	// vector<int> price ={2,2,10,6};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	cout << solution.countDaysTogether("10-01","10-31","11-01","12-31")<< endl;
}