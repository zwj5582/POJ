#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;
long long dou[260][260]; vector<int>num; int maxnum = 0;
int main()
{
	while (true){
		int n; cin >> n; if (n == 0)break; maxnum = max(n, maxnum); num.push_back(n);
	}
	memset(dou, 0, sizeof(dou)); int size = num.size();
	for (int i = 0; i <= maxnum; i++){ dou[0][i] = 1; }
	for (int i = 1; i <= maxnum; i++){ for (int j = i; j > i / 2; j--){ dou[i][j] = 1; } }
	for (int i = 2; i <= maxnum; i++){
		for (int j = i / 2; j >= 1; j--){
			dou[i][j] = dou[i - 2 * j][j] + dou[i][j + 1];
		}
	}
	for (int i = 0; i < size; i++){
		cout << num[i]<<" "<<dou[num[i]][1] << endl;
	}
	return 0;
}