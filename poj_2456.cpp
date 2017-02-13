#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int location[100010]; int N, C; int maxmin = 1 << 30;
bool search(int m){
	if (m*(C - 1) > location[N - 1] - location[0])return false;
	int base = location[0]; int n = 1;
	for (int i = 1; i < N; i++){
		if (location[i] >= (base + m)){ n++; if (n >= C)return true; base = location[i]; }
	}
	return false;
}
int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++){ cin >> location[i]; }
	sort(location, location + N);
	for (int i = 1; i < N; i++){ maxmin = min(maxmin, location[i] - location[i - 1]); }
	int l = 0; int r = location[N - 1] - location[0]; int m;
	while (l < r-maxmin){
		m = (r + l) / 2;
		if (search(m))l = m;
		else r = m;
	}
	cout << l << endl;
	return 0;
}