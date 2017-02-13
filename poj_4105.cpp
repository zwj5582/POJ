#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int t; int r; int c; int k; int result[10];
char maze[210][210]; bool mark[210][210][1 << 5]; int num_door; int min_path;
int to[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
struct node{
	int _x; int _y; int _s; int _time; node(int x, int y, int s, int time) :_x(x), _y(y), _s(s), _time(time){}
};
struct door{
	int _x; int _y;
}door[15];
bool check(int s, int k){
	int ss = 0;
	for (int i = 0; i <= 4; i++){ if (((s >> i) & 1) == 1)ss++; }
	return (ss >= k);
}
bool DFS(int x, int y, int e_x, int e_y){
	queue<node> q;
	q.push(node(x, y, 0, 0));
	while (!q.empty()){
		node tmp = q.front(); q.pop();
		if (tmp._x == e_x&&tmp._y == e_y&&check(tmp._s, k)){ min_path = tmp._time; return true; }
		if (maze[tmp._x][tmp._y] == '.'){
			for (int i = 0; i < 4; i++){
				int x1 = tmp._x + to[i][0]; int y1 = tmp._y + to[i][1];
				if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c && maze[x1][y1] != '#' && mark[x1][y1][tmp._s] == false){
					mark[x1][y1][tmp._s] = true; q.push(node(x1, y1, tmp._s, tmp._time + 1));
				}
				
			}
		}
		if (maze[tmp._x][tmp._y] >= '0'&&maze[tmp._x][tmp._y] <= '4'){
			int s = tmp._s | (1 << (maze[tmp._x][tmp._y] - '0'));
			for (int i = 0; i < 4; i++){
				int x1 = tmp._x + to[i][0]; int y1 = tmp._y + to[i][1];
				if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c && maze[x1][y1] != '#' && mark[x1][y1][s] == false){
					mark[x1][y1][s] = true; q.push(node(x1, y1, s, tmp._time + 1));
				}
			}
		}
		if (maze[tmp._x][tmp._y] == '$'){
			for (int i = 0; i < num_door; i++){
				for (int j = 0; j < 4; j++){
					int x1 = door[i]._x + to[j][0]; int y1 = door[i]._y + to[j][1];
					if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c && maze[x1][y1] != '#' && mark[x1][y1][tmp._s] == false){
						mark[x1][y1][tmp._s] = true; q.push(node(x1, y1, tmp._s, tmp._time + 1));
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> t; int w = 0;
	while (t--){
		cin >> r >> c >> k; int x, y, e_x, e_y;
		/*memset(maze, '#', sizeof(maze));*/ memset(mark, false, sizeof(mark)); num_door = 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				cin >> maze[i][j];
				if (maze[i][j] == '$'){ door[num_door]._x = i; door[num_door]._y = j; num_door++; }
				if (maze[i][j] == 'S'){ x = i; y = j; maze[i][j] = '.'; }
				if (maze[i][j] == 'E'){ e_x = i; e_y = j; maze[i][j] = '.'; }
			}
		}
		if (DFS(x, y, e_x, e_y)){
			result[w] = min_path;
		}
		else{
			result[w] = -1;
		}
		w++;
	}
	for (int i = 0; i < w; i++){
		if (result[i] == -1){
			cout << "oop!" << endl;
		}
		else{
			cout << result[i] << endl;
		}
	}
	return 0;
}