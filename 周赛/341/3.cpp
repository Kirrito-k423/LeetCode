#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        string tmp;
		int result = 0;
		for(auto single:word){
			if(tmp==""){
				tmp+=single;
			}else if(tmp=="a"){
				if(single=='a'){
					result+=2;
					tmp=single;
				}else if(single=='b'){
					tmp+=single;
				}else{
					result+=1;
					tmp="";
				}
			}else if(tmp=="ab"){
				if(single=='c'){
					tmp="";
				}else{
					result++;
					tmp=single;
				}
			}else if(tmp=="b"){
				if(single=='c'){
					result++;
					tmp="";
				}else{
					result+=2;
					tmp=single;
				}
			}else if(tmp=="c"){
				result+=2;
				tmp=single;
			}
		}
		if(tmp=="a"){
			result+=2;
		}else if(tmp=="ab"){

			result++;

		}else if(tmp=="b"){

			result+=2;

		}else if(tmp=="c"){
			result+=2;

		}
		return result;
    }
};