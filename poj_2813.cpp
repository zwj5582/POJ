#include <memory.h>
#include <iostream>
using namespace std;
int pictrue[20][20]; int press[20][20]; int n;
bool guess(){
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n; j++){
			press[i][j] = (pictrue[i - 1][j] + press[i - 1][j] + press[i - 1][j - 1] + press[i - 1][j + 1] + press[i - 2][j]) % 2;
		}
	}
	for (int i = 1; i <= n; i++){
		if ((pictrue[n][i] + press[n][i] + press[n - 1][i] + press[n][i - 1] + press[n][i + 1]) % 2 != 0)return false;
	}
	return true;
}
int power_2(){
	int num = 1;
	for (int i = 0; i < n; i++){ num *= 2; }
	return num;
}
int main()
{
	char a; 
	cin >> n; int minstep = 0;
	memset(pictrue, 0, sizeof(pictrue)); memset(press, 0, sizeof(press));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a;
			if (a == 'y'){ pictrue[i][j] = 0; }
			else { pictrue[i][j] = 1; }
		}
	}
	int m = power_2(); int i;
	for (i = 0; i < m; i++){
		if (guess())break; ++press[1][1];
		for (int j = 1; j <= n; j++){
			if (press[1][j] == 2){ press[1][j] = 0; ++press[1][j + 1]; }
		}
	}
	if (m == i) cout << "inf" << endl;
	else{
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (press[i][j] == 1)minstep++;
			}
		}
		cout << minstep << endl;
	}
	return 0;
}