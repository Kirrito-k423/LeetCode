#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int kMaxNumNodes = 1001;

struct GrassTp {
	int x, y;
	int dist;

	bool operator < (const GrassTp& other) const {
		if (dist == other.dist) {
			if (x == other.x)
				return x < other.x;
			else
				return y < other.y;
		}
		return dist < other.dist;
	}
};

struct SegmentTp {
	int x1, y1;
	int x2, y2;
};

const int kMaxGrassType = 100;
int gM, gN;
int gMaxDist;
GrassTp gGrass[kMaxGrassType];

int Dist(GrassTp a, GrassTp b) {
	return max(abs(a.x - b.x), abs(a.y - b.y));
}

void ReadData() {
	cin >> gM;
	cin >> gN;
	int xmin, ymin, xmax, ymax;
	for (int index = 0; index < gN; index++) {
		cin >> gGrass[index].x >> gGrass[index].y;
		xmin = min(xmin, gGrass[index].x);
		ymin = min(ymin, gGrass[index].y);
		xmax = max(xmax, gGrass[index].x);
		ymax = max(ymax, gGrass[index].y);
	}
	gMaxDist = max(ymax - ymin, xmax - xmin);
}

int CountGrass(int day) {
	vector<SegmentTp> vertical_segs;
	vector<SegmentTp> horizontal_segs;
	for (int index = 0; index < gN; index++) {
		int midx = gGrass[index].x;
		int midy = gGrass[index].y;
		SegmentTp segment1 = (SegmentTp){midx - day, midy - day, midx - day, midy + day};
		SegmentTp segment2 = (SegmentTp){midx + day, midy - day, midx + day, midy + day};
		SegmentTp segment3 = (SegmentTp){midx - day, midy - day, midx + day, midy - day};
		SegmentTp segment4 = (SegmentTp){midx - day, midy + day, midx + day, midy + day};
		vertical_segs.push_back(segment1);
		vertical_segs.push_back(segment2);
		horizontal_segs.push_back(segment3);
		horizontal_segs.push_back(segment4);
	}
	vector<GrassTp> points;
	for (int vertical_index = 0; vertical_index < vertical_segs.size(); vertical_index++) {
		for (int horizontal_index = 0; horizontal_index < horizontal_segs.size(); horizontal_index++) {
			SegmentTp segment1 = vertical_segs[vertical_index];
			SegmentTp segment2 = horizontal_segs[horizontal_index];
			if (segment1.x1 >= segment2.x1 && segment1.x1 <= segment2.x2 &&
				segment2.y1 >= segment1.y1 && segment2.y1 <= segment1.y2) {
					GrassTp newpoint;
					newpoint.x = segment1.x1;
					newpoint.y = segment2.y1;
					points.push_back(newpoint);
				}
		}
	}
	int count = -1;
	for (int point_index = 0; point_index < points.size(); point_index++) {
		int current_count = 0;
		for (int grass_index = 0; grass_index < gN; grass_index++) {
			if (Dist(points[point_index], gGrass[grass_index]) <= day) {
				current_count++;
			}
		}
		count = max(count, current_count);
	}
	return count;
}

int BinarySearch() {
	int lb = 0;
	int rb = gMaxDist;
	if (CountGrass(lb) > gM || CountGrass(rb) < gM || gM > gN) {
		cout << 0 << endl;
		return 0;
	}
	while (rb > lb) {
		int mid = (lb + rb) >> 1;
		int max_types = CountGrass(mid);
		if (max_types >= gM) {
			rb = mid;
		}
		else {
			lb = mid + 1;
		}
	}
    int max_types = CountGrass(rb);
    if (max_types == gM)
	    cout << rb << endl;
    else
        cout << 0 << endl;
}

int main() {
	ReadData();
	BinarySearch();
	return 0;
}