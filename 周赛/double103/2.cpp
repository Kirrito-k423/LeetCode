#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> setA;
        set<int> setB;
        int n = A.size();
        vector<int> C(n,0);
        for(int i = 0; i < n; i++){
            setA.insert(A[i]);
            setB.insert(B[i]);
            int count = 0;
            for(auto & x : setA){
                if(setB.count(x)){
                    count++;
                }
            }
            C[i]=count;
            
        }
        return C;
    }
};