#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<int> gResource;
vector<int> gUsed;
vector<int> gResourceCount(100000, -1);
vector<int> gUsedCount(100000, -1);

int main() {
	freopen("input.txt", "r", stdin);
	int l, r, m;
	cin >> l >> r >> m;
	int head = 0;
	gResource.resize(r - l + 1);

	for (int i = l; i <= r; i++) {
		gResource[i - l] = i;
		gResourceCount[i] = i - l;
	}

	int op, x;
	int cnt = r - l + 1;
	for (int t = 0; t < m; t++) {
		cin >> op >> x;

		if (op == 1) {
			if (cnt < x) {
				continue;
			}
			int i = 0;
			while (i < x) {
				if(gResource[head] == -1) {
					head++;
					if (head == gResource.size())
						break;
					continue;
				}
				gUsed.push_back(gResource[head]);
				gUsedCount[gResource[head]] = gUsed.size() - 1;
				gResourceCount[gResource[head]] = -1;
				gResource[head] = -1;
				i++;
			}
			cnt -= x;
		}
		else if (op == 2) {
			if(gResourceCount[x] != -1) {
				int index = gResourceCount[x];
				gUsed.push_back(gResourceCount[index]);
				gUsedCount[gResource[index]] = gUsed.size() - 1;
				gResource[index] = -1;
				gResourceCount[x] = -1;	
				cnt -= 1;
			}
		}
		else if (op == 3) {
			if (gUsedCount[x] != -1) {
				int index = gUsedCount[x];
				gResource.push_back(x);
				gResourceCount[x] = gResource.size() - 1;
				gUsed[index] = -1;
				gUsedCount[x] = -1;
				cnt += 1;
			}
		}
	}

	while(gResource[head] == -1) {
		head++;
	}
	cout << gResource[head] << endl;
	return 0;
}