
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++14 output here. For example:cout<<____<<endl;
    char ch;
    while(cin){
        ch=cin.get()
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            cout << (char)(ch+('A' - 'a')) ;
        }else if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            cout << ch;
        }else if(ch==' '){
            cout << ch;
        }else if(ch<'a'){
            cout << (char)(ch +('a'-'A'));
        }else{
            cout << ch;
        }
    }
    return 0;
}
