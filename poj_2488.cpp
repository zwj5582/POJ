#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
int n; int p; int q; bool chess[27][27]; vector<string> result; vector<string> r;
int to[8][2] = { -2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1 };
bool DFS(int x, int  y,int k){
	for (int i = 0; i < 8; i++){
		int x1, y1;
		x1 = x + to[i][0]; y1 = y + to[i][1];
		if ((x1>q||x1<1)||(y1>p||y1<1)||chess[x1][y1] == true){ continue; }
		chess[x1][y1] = true; 
		if (DFS(x1, y1,k+1)){
			string str; char a = 64 + x1; char b = 48 + y1; str += a; str += b; result.push_back(str);
			return true;
		}
		chess[x1][y1] = false;
	}
	return (k == p*q) ? true : false;
}
int main()
{
	cin >> n; int m = 0;
	while (m != n){
		cin >> p >> q; memset(chess, false, sizeof(chess));
		chess[1][1] = true; result.clear();
		if (DFS(1, 1, 1)){
			result.push_back("A1");
			string str;
			for (int i = result.size() - 1; i >= 0; i--){
				str += result[i];
			}
			r.push_back(str);
		}
		else{
			r.push_back("impossible");
		}
		m++;
	}
	for (int i = 0; i < r.size(); i++){
		cout << "Scenario #" << i + 1 << ":" << endl;
		cout << r[i] << endl;
		cout<<endl;
	}
	return 0;
}