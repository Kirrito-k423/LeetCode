#include <bits/stdc++.h>

using namespace std;

#define Dynamic 1
#define Allocate 2
#define Release 3

int N;
// 既要首尾操作，又要改变中间元素，只能在vector上构造
// 辅助数据结构， 总数， 是否出队，和现在的位置
int main(){
	int begin, end;
	cin >> begin >> end;
	N = end - begin + 1;
	int array[N];
	iota(array, array + N, 0);
	vector<int> resource(array, array + N);
	// vector<int> resourceSuffix;
	int opNum;
	cin >> opNum;
	long long frontIndex = 0;
	// function<bool(int)> less = [&frontIndex, &resource](int threshold){
	// 	int count = 0;
	// 	for(int i = frontIndex; i < resource.size(); ++i){
	// 		if(resource[i]!=-1)
	// 			count++;
	// 	}
	// 	return (count < threshold) ? true:false;
	// };
	int availableNum = N;
	while(opNum--){
		int mode; int modeValue;
		cin >> mode >> modeValue;
		if(mode==Dynamic){
			// if(less(modeValue)) continue;
			if(modeValue > availableNum)	continue;
			availableNum -= modeValue;
			while(modeValue--){
				if(frontIndex < resource.size()){ 
					if(resource[frontIndex]!=-1){
						if(array[resource[frontIndex]]==-1){
							//already distributed resource
							// not triggered 
							frontIndex++;
							modeValue++;
						}else{
							array[resource[frontIndex]]=-1;
							frontIndex++;
						}
					}else{
						//already distributed resource
						frontIndex++;
						modeValue++;
					}
				}
			}
			
		}else if(mode==Allocate){
			if(modeValue >= begin && modeValue <= end){
				int delta = modeValue - begin;
				if(array[delta]!=-1){
					resource[array[delta]]=-1;
					array[delta]=-1;
					availableNum--;
				}				
			}
		}else{
			//mode release
			if(modeValue >= begin && modeValue <= end){
				int delta = modeValue - begin;
				if(array[delta]==-1){
					array[delta]=resource.size();
					resource.push_back(delta);
					availableNum++;
				}
			}
		}
	}
	while(resource[frontIndex]==-1){
		//应该保证有解 frontIndex < resource.size()
		frontIndex++;
	}
	cout << resource[frontIndex]+begin << endl;
	return 0;
}