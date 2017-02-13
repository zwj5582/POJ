#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
int n, k; bool check_row[9]; int num; bool check[9][9]; vector<int>result;
void DFS(int x,int kk){
	for (int i = 1; i <= n; i++){
		if (check[x][i] == true || check_row[i] == true)continue;
		if (kk == 1){ num++; continue; }
		check_row[i] = true;
		for (int j = x + 1; j <= n - kk + 2; j++){
			DFS(j, kk - 1); 
		}
		check_row[i] = false;
	}
}
int main()
{
	while (true){
		num = 0; cin >> n >> k;
		if (n == -1 && k == -1)break;
		memset(check, true, sizeof(check));
		memset(check_row, false, sizeof(check_row));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				char a; cin >> a; if (a == '#')check[i][j] = false;
			}
		}
		for (int i = 1; i <= n - k + 1; i++){
			DFS(i, k);
		}
		result.push_back(num);
	}
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	return 0;
}