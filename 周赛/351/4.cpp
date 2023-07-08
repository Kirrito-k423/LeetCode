#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;

// struct robot{
//     int labelNum;
//     // int pos;
//     // int health;
//     // char direct;
// };
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> R(n);
        iota(R.begin(),R.end(),0);
        sort(R.begin(),R.end(),[&positions](const int A, const int B){
            return positions[A] < positions[B];
        });
        stack<int> line;
        for(int &i:R){
            if(directions[i]=='R'){
                line.push(i);
            }else{
                int remaini = i;
                while(remaini>0 && healths[remaini] > 0 && !line.empty()){
                    int ri = line.top();
                    if(healths[ri]==healths[remaini]){
                        healths[ri]=healths[remaini]=0;
                        remaini = -1;
                        line.pop();
                    }else if(healths[ri]>healths[remaini]){
                        healths[ri]-=1;
                        healths[remaini]=0;
                        remaini = -1;
                    }else{
                        healths[remaini]-=1;
                        healths[ri]=0;
                        line.pop();
                    }
                }
            }
        }
        // print as followed
        vector<int> result;
        for(auto &health : healths){
            if(health!=0){
                result.push_back(health);
            }
        }
        return result;

    }
};


int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	vector<int> price ={13,3};
	vector<int> price2 ={17,2};
	// vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	solution.survivedRobotsHealths(price,price2,"LR");
}