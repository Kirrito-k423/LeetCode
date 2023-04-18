
#include "../tsjCommonFunc.h"
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //将N1，N2大小的数组更大的一个变成set， 查找 N1 log(N2)
        vector<int>* setV = &nums1;
        vector<int>* searchV =&nums2;
        // if(nums1.size() > nums2.size()){
        //     setV = nums1;
        //     searchV = nums2;
        // }else{
            setV = &nums2;
            searchV = &nums1;
        // }

        //构建set
        unordered_set<int> search_set;
        for(const auto & x : *setV){
             cout << x << "-";
            search_set.insert(x);
        }
        cout << endl;
        unordered_set<int> result_set;
        //查找相同元素
        for(const auto & x : *searchV){
            if(search_set.count(x)){
                cout << x << "~";
                result_set.insert(x);
            }
        }
        cout << endl;

        //set 变成 vector
        vector<int> result;
        for(auto i=result_set.begin(); i!=result_set.end(); ++i){
            result.push_back(*i);
            cout << *i << " ";
        }
        return result;
    }
};

int main(){
	Solution Solution;
    vector<int> input1 = {4,9,5};
    vector<int> input2 = {9,4,9,8,4};
	// cout << 
    Solution.intersection(input1,input2);
    //  << endl;
}
