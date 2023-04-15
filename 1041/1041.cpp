#include <string>
#include <iostream>
using namespace std;

static const int direction[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}};
struct status{
	int x, y;
	int direct;
	status(int x, int y) : x(x), y(y) { direct=0;}
	bool operator==(const status b) const  
    {  
        return (this->x == b.x) && (this->y == b.y) && 
				(this->direct == b.direct);  
    }  
	void forward(){//允许在结构体当中定义函数, struct中定义的函数和变量都是默认为public的
		x += direction[direct][0];
		y += direction[direct][1];
	}
	void turnRight(){
		direct = (direct+1)%4;
	}
	void turnLeft(){
		direct = (direct+3)%4;
	}

};
class Solution {
public:
	
    bool isRobotBounded(string instructions) {
		//模拟一次循环后，方向的改变
		int direct = 0;
		status cur(0,0);
		// status before(0,0);
		//status* cur = new status(0,0);
		for(auto &x:instructions){
			if(x=='G')
				cur.forward();
			else if(x=='L')
				cur.turnLeft();
			else
				cur.turnRight();
		}
		if(cur.direct==0&&(cur.x!=0||cur.y!=0))
			return false;
		else 
			return true;
    }
};

int main(){
	Solution solution;
	string input="GLGLGGLGL";
	cout << solution.isRobotBounded(input) << endl;
}