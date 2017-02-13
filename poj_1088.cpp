#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;
int R, C;
int to[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int step[110][110];
int node_h[110][110];
int maxpath = 0;
int path(int x, int y){
	int maxpath = 0;
	if (step[x][y] > 0)return step[x][y];
	for (int i = 0; i < 4; i++){
		int x1 = x + to[i][0]; int y1 = y + to[i][1];
		if (node_h[x][y] < node_h[x1][y1])
			maxpath = max(path(x1,y1), maxpath);
	}
	return step[x][y] = maxpath + 1;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> node_h[i][j];
		}
	}
	memset(step, 0, sizeof(step));
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			maxpath = max(maxpath, path(i, j));
		}
	}
	cout << maxpath << endl;
	return 0;
}