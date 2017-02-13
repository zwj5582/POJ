#include <iostream>
#include <vector>
using namespace std;
int all_cover_num[16]; int n; vector<int>result;
int main()
{
	all_cover_num[0] = 1; all_cover_num[1] = 3;
	for (int i = 2; i <= 15; i++){
		all_cover_num[i] = all_cover_num[i - 1] * 4 - all_cover_num[i - 2];
	}
	while (1){
		cin >> n; if (n == -1)break;
		if (n % 2 == 0){
			result.push_back(all_cover_num[n / 2]);
		}
		else{
			result.push_back(0);
		}
	}
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	return 0;
}