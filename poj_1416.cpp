#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cstdlib>
using namespace std;
int target; bool flag = false; int path; vector<int>result_1; vector<string>result_2; int maxnum; int totsum; int spilt;
int get_digit_num(int n){
	if (n < 10)return 1;
	else if (n < 100)return 2;
	else if (n < 1000)return 3;
	else if (n < 10000)return 4;
	else if (n < 100000)return 5;
	else return 6;
}
int get_num_head(int n, int i){
	int l = get_digit_num(n);
	if (l <= i)return n;
	return n / (int)pow(10.0, (double)(l - i));
}
int get_num_tail(int n, int i){
	return n % (int)(pow(10.0, (double)(i)));
}
int get_num_smallest(int n){
	int sum = 0;
	while (n != 0){ sum += (n % 10); n /= 10; }
	return sum;
}
string get_num_to_str(int n){
	string str;
	if (n == 0)str = "0";
	while (n !=0 ){
		int i = n % 10; n /= 10; char a = 48 + i; str = a + str;
	}
	return str;
}
void DFS(string s, int len){
	if (len == 0){
		if (totsum>=maxnum&&totsum<=target){
			if (totsum == maxnum){
				flag = true;
			}
			else{
				flag = false;
			}
			maxnum = totsum; path = spilt;
		}
		return;
	}
	for (int i = 1; i <= len; i++){
		string ss;
		int head = atoi(ss.assign(s, 0, i).c_str());
		totsum += head; if (totsum > target){ totsum-=head; continue; }
		spilt = spilt * 10 + i;
		string after; after.assign(s, i, s.size());
		DFS(after, len - i); totsum -= head; spilt = spilt / 10;
	}
	return;
}
int main()
{
	while (true){
		string line; getline(cin, line); string des, strnum; istringstream in(line); in >> des >> strnum;
		target = atoi(des.c_str());
		int num = atoi(strnum.c_str());
		if (target == 0 && num == 0)break;
		int n = get_num_smallest(num);
		if (n > target){ result_1.push_back(-1); result_2.push_back("error"); continue; }
		if (num == target){ result_1.push_back(num); result_2.push_back(strnum); continue; }
		flag = false; maxnum = -1; path = 0; totsum = 0; spilt = 0;
		DFS(strnum, strnum.size());
		if (flag == true){ result_1.push_back(-1); result_2.push_back("rejected"); continue; }
		result_1.push_back(maxnum);
		int l = get_digit_num(path); int leng = strnum.size(); string result;
		for (int i = 1; i <= l; i++){
			int k = get_num_head(path, 1);
			int head = get_num_head(num, k);
			string str = get_num_to_str(head); result += str; if (i != l){ result += " "; }
			path = get_num_tail(path, l - i); num = get_num_tail(num, leng -= k);
		}
		result_2.push_back(result);
	}
	for (int i = 0; i < result_1.size(); i++){
		if (result_1[i] != -1){
			cout << result_1[i] << " " << result_2[i] << endl;
		}
		else{
			cout << result_2[i] << endl;
		}
	}
	return 0;
}