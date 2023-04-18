#include <stdio.h>
using namespace std;
void subFuc(int (&array)[2]){
	printf("%d\n",array[0]);
	subFuc(array);
}

int main(){
	int array[2] ={1,2};
	subFuc(array);
}