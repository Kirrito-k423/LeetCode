#include <vector>
#include <map>
using namespace std;

class MajorityChecker {
public:
	vector<map<int,int>> prefixShowTimes;
    MajorityChecker(vector<int>& arr) {
		//参考前缀和，维护前缀出现次数
		map<int,int> ShowTimes;
		prefixShowTimes.push_back(ShowTimes);
		for(auto &val : arr) {
			ShowTimes[val]++;
			prefixShowTimes.push_back(ShowTimes);
		}
    }
    
    int query(int left, int right, int threshold) {
		if(right + 1 - left < threshold) return -1;
		right++;
		int ans = 0;
		for(auto &candidate : prefixShowTimes[right]) {
			int candidateNum = candidate.first;
			int tailShowTimes = candidate.second;
			if(tailShowTimes>=threshold) {
				if(prefixShowTimes[left].count(candidateNum)){
					int frontShowTimes =  (prefixShowTimes[left])[candidateNum];
					if(tailShowTimes - frontShowTimes < threshold)
						continue;
					else
						return candidateNum;
				}
				return candidateNum;
				// ans++;
			}
		}
		return -1; 
    }
};

// 超时
