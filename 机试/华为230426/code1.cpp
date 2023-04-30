#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int kMaxNumNodes = 1001;

struct EdgeTp {
	int st, ed;
};


int gDistance[kMaxNumNodes];
int gNumNodes;
int gEdgeSize = 0;
vector<EdgeTp> gEdge;

void readGraph() {
	int index;
	cin >> gNumNodes;
	std::fill(gDistance, gDistance + gNumNodes, -1);
	for (int index = 1; index <= gNumNodes; index++) {
		EdgeTp edge;
		int edge_cnt;
		cin >> edge_cnt;
		gEdgeSize += edge_cnt;
		if (edge_cnt == 0) {
			gDistance[index] = 0;
			continue;
		}

		edge.ed = index;
		for (int subindex = 0; subindex < edge_cnt; subindex++) {
			cin >> edge.st;
			gEdge.push_back(edge);
		}
	}
}

bool ReleaseGraph() {
	bool flag = false;
	for (int edge_index = 0; edge_index < gEdgeSize; edge_index++) {
		int st = gEdge[edge_index].st;
		int ed = gEdge[edge_index].ed;
		if (gDistance[st] == -1) {
			continue;
		}

		if (gDistance[ed] == -1 || gDistance[ed] < gDistance[st] + 1) {
			gDistance[ed] = gDistance[st] + 1;
			flag = true;
		}
	}
	return flag;
}

void StatDistance() {
	bool flag = false;
	for (int node_index = 1; node_index <= gNumNodes; node_index++) {
		if (gDistance[node_index] == 0)
		flag = true;
	}
	if (flag == false) {
		cout << -1 << endl;
		return;
	}
	for (int node_inedx = 0; node_inedx < gNumNodes; node_inedx++) {
		ReleaseGraph();
	}
	if (ReleaseGraph()) {
		cout << -1 << endl;
		return;
	}
	int ans = -1;
	for (int tmp = 1; tmp <= gNumNodes; tmp++) {
		ans = max(ans, gDistance[tmp]);
	}
	cout << ans + 1 << endl;
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	readGraph();
	StatDistance();
}