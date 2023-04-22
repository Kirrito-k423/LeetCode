#include <bits/stdc++.h>
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
typedef long long ll;
const int N = 1E5 + 10, M = 210;

struct point {
    int x, y;
    int width;
    point(int x, int y, int width) : x(x), y(y), width(width){};
    // friend ?
    friend bool operator-(const point &a, const point &b) {
        float max = (a.width + b.width) / 2;
        // return (abs(a.x - b.x) <= max - 1e-6) && (abs(a.y - b.y) <= max - 1e-6);
        return (abs(a.x - b.x) <= max) && (abs(a.y - b.y) <= max);
    };
    // bool minus(const point &b){
    // 	//a.minus(b);
    // 	point &a = *this;
    // 	float max = (a.width + b.width)/2;
    // 	return (abs(a.x - b.x) <= max-1e-6) && (abs(a.y - b.y) <= max-1e-6);
    // };
};

const int MAXN = 105;
class Solution {
   public:
    int g[MAXN][MAXN];
    int degree[100]; // ?
    vector<point> points;
    int n, dp[MAXN], st[MAXN][MAXN], ans;
    bool dfs(int sz, int num) {
        if (sz == 0) {
            if (num > ans) {
                ans = num;
                return true;
            }
            return false;
        }
        for (int i = 0; i < sz; i++) { // 在第num层的集合中枚举一个点i
            if (sz - i + num <= ans)
                return false; // 剪枝1
            int u = st[num][i];
            if (dp[u] + num <= ans)
                return false; // 剪枝2
            int cnt = 0;
            for (
                int j = i + 1; j < sz;
                j++) { // 在第num层遍历在i之后的且与i所相连的点，并且加入第num+1层集合
                if (g[u][st[num][j]])
                    st[num + 1][cnt++] = st[num][j];
            }
            if (dfs(cnt, num + 1))
                return true;
        }
        return false;
    }

    int solver() {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 1; i--) {
            int cnt = 0;
            for (int j = i + 1; j <= n; j++) { // 初始化第1层集合
                if (g[i][j])
                    st[1][cnt++] = j;
            }
            dfs(cnt, 1);
            dp[i] = ans;
        }
        return ans;
    }
    int fieldOfGreatestBlessing(vector<vector<int>> &forceField) {
        memset(g, 0, sizeof(g));
        // forceField抽象为点，重叠转换为点相邻, 答案N，则图中存在相邻N点，(去掉干扰节点后)每点度为N-1
        // 求解最大完全子图 最大团 最大完备子图。
        for (auto &x : forceField) {
            point a = point(x[0], x[1], x[2]);
            int pointId = points.size();
            for (int i = 0; i < pointId; i++) {
                if (a - points[i]) {
                    g[i+1][pointId+1] = 1;
                    g[pointId+1][i+1] = 1;
                }
            }
            points.push_back(a);
        }
        n = points.size();
        return solver();
    }
};

int main(){
	Solution solution;

	vector<vector<int>> trips = {{0,0,1},{1,0,1}};
	cout << solution.fieldOfGreatestBlessing( trips)<< endl;
}