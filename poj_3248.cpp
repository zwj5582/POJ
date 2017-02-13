#include <iostream>
#include <vector>
using namespace std;
int n1, n2;
vector<int>result;
int get_max_commom_divisor(int x, int y){
	if (x >= y){
		if (x%y == 0)return y;
		return get_max_commom_divisor(y, x%y);
	}
	else{
		if (y%x == 0)return x;
		return get_max_commom_divisor(x, y%x);
	}
}
int get_max_common_divisor_1(int x, int y){
	while (x%y != 0 && y%x != 0){
		if (x > y){
			x = x%y;
		}
		else{
			y = y%x;
		}
	}
	return (x >= y) ? y : x;
}
int main()
{
	while (cin >> n1 >> n2){
		result.push_back(get_max_common_divisor_1(n1, n2));
	}
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	return 0;
}