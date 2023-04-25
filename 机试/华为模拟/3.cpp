#include <bits/stdc++.h>

using namespace std;


// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

long long factorial(int k){
    long long result = 1;
    k = k+1;
    while(--k){
        result *= k;
    }
    return result;
}
int main()
{
    // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++14 output here. For example:cout<<____<<endl;
    string A;
    cin >> A;
    map<char, int> count;
    
    for(auto & a : A){
        count[a]++;
    }
    long long result = factorial(A.size());
    for(auto & c : count){
        result /= factorial(c.second);
    }
    cout << result;
    return 0;
}
