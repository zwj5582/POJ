#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, n;
int s; 
vector<int> result;
int main()
{
	cin >> n; int k = 0;
	while (k != n){
		cin >> s;
		cin >> a;
		vector<int>a1;
		vector<int>b1;
		for (int i = 0; i < a; i++){
			int num; cin >> num; a1.push_back(num);
		}
		cin >> b;
		for (int i = 0; i < b; i++){
			int num; cin >> num; b1.push_back(num);
		}
		result.push_back(0);
		sort(a1.begin(), a1.end()); sort(b1.begin(), b1.end());
		vector<int>::iterator ita_head = a1.begin();
		vector<int>::iterator ita_tail = a1.end();
		vector<int>::iterator itb_head = b1.begin();
		vector<int>::iterator itb_tail = b1.end();
		while (ita_head != ita_tail&&itb_head != itb_tail){
			if ((*ita_head + *(itb_tail-1)) == s){ 
				vector<int>::iterator pre_ita_head = ita_head;
				vector<int>::iterator pre_itb_tail = itb_tail;
				++pre_ita_head; --pre_itb_tail; int m = 1; int n = 1;
				while (pre_ita_head != ita_tail&&*pre_ita_head == *ita_head){
					++pre_ita_head; m++;
				}
				while (pre_itb_tail != itb_head&&*(pre_itb_tail - 1) == *(itb_tail - 1)){
					--pre_itb_tail; n++;
				}
				result[k] += m*n;
				ita_head = pre_ita_head; itb_tail = pre_itb_tail;
			}
			else if ((*ita_head + *(itb_tail - 1)) < s){
				++ita_head;
			}
			else{
				--itb_tail;
			}
		}
		k++;
	}
	for (int i = 0; i < n;i++){
		cout << result[i] << endl;
	}
	return 0;
}