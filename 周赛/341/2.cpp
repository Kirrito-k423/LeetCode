#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
		int answer = 0;
		int result = 0;
		for(int j = 0; j < divisors.size(); j++) {
			int & div = divisors[j];
			int tmp = 0;
			for(int i = 0; i < nums.size(); i++){
				if(nums[i] % div == 0){
					tmp++;
				}
			}
			if(tmp > answer){
				answer = tmp;
				result = j;
			}else if(answer == tmp) {
				if(divisors[j]<divisors[result])
					result = j;
			}
		}
		return divisors[result];
    }
};