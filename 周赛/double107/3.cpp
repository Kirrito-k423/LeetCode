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
    int minimizeConcatenatedLength(vector<string>& words) {
        //看错题目了：以为成是任意顺序
        map<char,int> headCout;
        map<char,int> tailCout;
        map<char,int> tmpCout;
        set<pair<char,char>> loopPair;
        set<char> showed;
        int result = 0;
        for(auto &word:words){
            int endi = word.size()-1;
            if(word[0]==word[endi]){
                tmpCout[word[0]]++;
                showed.insert(word[0]);
            }else if(loopPair.count(make_pair(word[endi],word[0]))){
                headCout[word[endi]]--;
                tailCout[word[0]]--;
                if(tmpCout[word[0]]>=tmpCout[word[endi]]){
                    tmpCout[word[0]]++;
                }else{
                    tmpCout[word[endi]]++;
                }
                loopPair.erase(make_pair(word[endi],word[0]));
                result--;
            }else{
                headCout[word[0]]++;
                tailCout[word[endi]]++;
                showed.insert(word[0]);
                showed.insert(word[endi]);
                loopPair.insert(make_pair(word[0],word[endi]));
            }
            result += word.size();
        }
        for(auto &tmpChar:showed){
            int pair3 = min(min(headCout[tmpChar],tailCout[tmpChar]),tmpCout[tmpChar]);
            headCout[tmpChar]-=pair3;
            tailCout[tmpChar]-=pair3;
            tmpCout[tmpChar]-=pair3;
            result -= 2*pair3;
            int delpair = min(headCout[tmpChar],tailCout[tmpChar]);
            int remain2pair = max(headCout[tmpChar],tailCout[tmpChar])-delpair;
            int adddelpair = min(tmpCout[tmpChar],remain2pair);
            int addadd = (tmpCout[tmpChar]-adddelpair)/2;
            result -= (delpair+
                    max(adddelpair+addadd, 
                    tmpCout[tmpChar]/2+min(remain2pair,tmpCout[tmpChar]-tmpCout[tmpChar]/2)));
        }
        return result;

    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }