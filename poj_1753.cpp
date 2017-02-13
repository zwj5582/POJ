#include <iostream>
#include <memory.h>
using namespace std;
int checkerboard[6][6]; int press[6][6]; int min_press_num = 1 << 30; int min_round; int min_press = 0; bool flag;
bool BFS(){
	for (int i = 0; i < 16; i++){
		min_press = 0; flag = true;
		for (int j = 1; j <= 4; j++){
			if (press[1][j] == 2){
				press[1][j] = 0; press[1][j + 1]++;
			}
			else{
				break;
			}
		}
		for (int n = 2; n <= 4; n++){
			for (int k = 1; k <= 4; k++){
				press[n][k] =
					(press[n - 1][k] + checkerboard[n - 1][k] + press[n - 1][k - 1] + press[n - 1][k + 1] + press[n - 2][k]) % 2;
			}
		}
		for (int m = 1; m <= 4; m++){
			if ((press[4][m] + checkerboard[4][m] + press[4][m - 1] + press[4][m + 1] + press[3][m] + press[4][m + 1]) % 2 != 0){
				flag = false; break;
			}
		}
		if (flag){
			for (int i = 1; i <= 4; i++){
				for (int j = 1; j <= 4; j++){
					if (press[i][j] == 1)min_press++;
				}
			}
			return true;
		}
		press[1][1]++;
	}
	return false;
}
int main()
{
	memset(checkerboard, 0, sizeof(checkerboard)); memset(press, 0, sizeof(press));
	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 4; j++){
			char c; cin >> c; if (c == 'b')checkerboard[i][j] = 1;
		}
	}
	if (BFS()){ min_press_num = min_press; }
	for (int i = 1; i <= 4; i++){
		for (int j = 1; j <= 4; j++){
			checkerboard[i][j]++; if (checkerboard[i][j] == 2)checkerboard[i][j] = 0;
		}
	}
	memset(press, 0, sizeof(press));
	if (BFS()){if (min_press < min_press_num)min_press_num = min_press; }
	if (min_press_num == 1 << 30){
		cout << "Impossible" << endl;
	}
	else{
		cout << min_press_num << endl;
	}
	return 0;
}