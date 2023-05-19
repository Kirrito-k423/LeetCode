    #include <bits/stdc++.h>

    using namespace std;

    class Solution {
    public:
        vector<int> rearrangeBarcodes(vector<int>& barcodes) {
            sort(barcodes.begin(),barcodes.end());
            int n = barcodes.size();
            //从重复最多的开始排布
            map<int,int> num2count;
            set<int> num;
            for(auto & x:barcodes) {
                num2count[x]++;
                num.insert(x);
            }
            vector<int> sortNumByCount(num.begin(),num.end()); //单调减
            sort(sortNumByCount.begin(),sortNumByCount.end(), [&num2count](const int & a, const int & b) {
                return num2count[a] > num2count[b];
            });
            vector<int> result;
            int left = 0;
            int right = 1;
            int flag = 1;
            while(result.size()<barcodes.size()) {
                int &cur = (flag%2)?left:right;
                //check if move point
                while(cur<sortNumByCount.size() && \
                    num2count[sortNumByCount[cur]]==0||\
                    (result.size()>0 && sortNumByCount[cur]==*result.rbegin())){
                    cur++;
                }
                //push
                result.push_back(sortNumByCount[cur]);
                num2count[sortNumByCount[cur]]--;
                flag++;
            }
            return result;
        }
    };

    int main(){
        Solution solution;
        vector<int> price ={7,7,7,8,5,7,5,5,5,8};
        solution.rearrangeBarcodes(price);
    }