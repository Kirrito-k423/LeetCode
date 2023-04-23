#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool check_overlap(vector<int> &a, vector<int> &b){
    //     return 2*abs(a[0] - b[0]) <= a[2] + b[2] && \
    //         2*abs(a[1] - b[1]) <= a[2] + b[2];
    // }
    bool check_point_in_square(pair<double, double> point, vector<int> &a){
        return fabs(point.first - a[0]) <= (a[2]+1e-3)/2 && \
            fabs(point.second - a[1]) <= (a[2]+1E-3)/2;
    }
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        int n = forceField.size();
        
        vector<pair<double, double>> points;//one square have four point
        for(int i=0; i<n; i++){
            vector<int> &field = forceField[i];
            double d = field[2]/2.0;
            points.push_back(make_pair(field[0]-d, field[1]-d));
            points.push_back(make_pair(field[0]-d, field[1]+d));
            points.push_back(make_pair(field[0]+d, field[1]-d));
            points.push_back(make_pair(field[0]+d, field[1]+d));
        }
        vector<int> counter(points.size(), 0); //count number of overlap square for each point
        for(int i=0; i<points.size(); i++){
            for(int j=0; j<n; j++){
                if(i/4!=j)
                    if(check_point_in_square(points[i], forceField[j])){
                        counter[i]++;
                    }
            }
        }
        return *(max_element(counter.begin(), counter.end()))+1;
    }
    // int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
    //     int n = forceField.size();
    //     vector<vector<double>> x_axis(n);
    //     for(auto field: forceField){
    //         vector<double> sec;
    //         sec.push_back(field[0] - field[2]/2);
    //         sec.push_back(field[1] + field[2]/2);
    //         x_axis.push_back(sec);
    //     }
        
    // }
};

// int main(){
//     // vector<vector<int>> forceField = {{4,4,6},{7,5,3},{1,6,2},{5,6,3}};
//     // vector<vector<int>> forceField = {{0,0,1},{1, 0, 1}};
//     vector<vector<int>> forceField = {{565,34,242},{299,628,870},{724,673,221},{128,267,917},{561,488,696},{341,71,604},{835,92,846},{945,696,973},{554,776,430},{209,134,594},{987,898,282},{819,154,462},{618,946,505},{561,40,677},{602,863,657},{295,83,718},{456,920,939},{94,717,813},{611,946,366},{818,850,85},{395,554,333},{325,700,628},{590,401,119},{248,858,499},{298,723,602},{189,538,646},{194,283,344},{842,535,866},{192,832,195}};

//     Solution s;
//     int res = s.fieldOfGreatestBlessing(forceField);
//     cout << res << endl;

//     return 0;
// }