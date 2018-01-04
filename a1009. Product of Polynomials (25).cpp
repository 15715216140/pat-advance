#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	float map[1005][2] = {0};
	float res[2005] = {0};
	int n, m, ex, cnt = 0;
	float co;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> ex >> co;
		map[ex][0] = co;
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ex >> co;
		map[ex][1] = co;
	}
	for(int i = 0; i <= 1000; i++) {//A中的每个元素*B中的每个元素 
		for(int j = 0; j <= 1000; j++) {
				res[i+j] += map[i][0] * map[j][1];
		}
	} 
	for(int i = 2000; i >= 0; i--) {
		if(res[i])	
		cnt++;
	} 
	cout << cnt;
	for(int i = 2000; i >= 0; i--) {
		if(res[i]) {
			cout  << ' ' << i << ' ' ;
			printf("%.1f",res[i]);
		}
	} 
	return 0;
}



