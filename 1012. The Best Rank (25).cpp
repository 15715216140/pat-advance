#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool is[1000000] = {false};//标记是否有这么个人 
int a[1000000];
int c[1000000];
int m[1000000];
int e[1000000];
int main (){
//	freopen("test.txt","r",stdin);
	string ss = "0ACME";
	int be = 1000000 , end = 0;
	int nn, nm;
	cin >> nn >> nm;
	for(int i = 1; i <= nn; i++) {
		int num, t1,t2,t3;
		cin >> num >> t1 >> t2 >> t3;
		c[num] = t1; m[num] = t2; e[num] = t3;
		a[num] = (c[num] + m[num] + e[num]) / 3;
		if(num < be)	be = num;
		if(num > end)	end = num;
		is[num] = true;
	}

	for(int j = 1; j <= nm; j++) {
		int num;
		cin >> num;
		if(is[num] == false) {
			cout << "N/A\n";
		}
		else {//遍历出每门成绩中的名次 
			int r[5] = {0};
			for(int i = be; i <= end; i++) {
				if(a[num] < a[i]) {
					r[1]++;
				}
			}
			for(int i = be; i <= end; i++) {
				if(c[num] < c[i]) {
					r[2]++;
				}
			}
			for(int i = be; i <= end; i++) {
				if(m[num] < m[i]) {
					r[3]++;
				}
			}
			for(int i = be; i <= end; i++) {
				if(e[num] < e[i]) {
					r[4]++;
				}
			}
			int minn = r[1],t = 1;
			for(int i =2 ; i <= 4; i++) {//几门成绩比较并且标记位置 
				if(minn > r[i]) {
					minn = r[i];
					t = i;
				}
			}
			cout << minn+1 << ' ' << ss[t] << endl;
		}
	} 
	return 0;
}
