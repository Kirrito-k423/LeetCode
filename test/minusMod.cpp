#include <iostream>

using namespace std;

int main(){
    int i[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    for(int j = 0; j < 10; j++){
        cout << i[j] % 5 << " "<< i[j] / 5<< endl;
    }
}