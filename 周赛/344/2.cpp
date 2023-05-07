#include <bits/stdc++.h>

using namespace std;

class FrequencyTracker {
public:
    map<int,int> n2f; // number 2 frequency
    map<int, set<int>> f2n;//frequency 2 numberSet
    FrequencyTracker() {

    }
    
    void add(int number) {
        if(n2f.count(number)){
            f2n[n2f[number]].erase(number);
            n2f[number]++;
            f2n[n2f[number]].insert(number);
        }else{
            n2f[number]=1;
            f2n[1].insert(number);
        }
    }
    
    void deleteOne(int number) {
        if(n2f.count(number)){
            if(n2f[number]==1){
                f2n[1].erase(number);
                n2f.erase(number);
            }else{
                f2n[n2f[number]].erase(number);
                n2f[number]--;
                f2n[n2f[number]].insert(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        if(f2n.count(frequency)){
            if(f2n[frequency].empty()){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */