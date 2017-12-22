#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	float a[1001] = {0};
	float co;
	int ex;
	int n, count = 0, t;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ex >> co;
		a[ex] += co;
	}
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> ex >> co;
		a[ex] += co;
	}
	for(int i = 0; i <= 1000; i++) {
		if(a[i])
			count++;
	}
 	cout << count ;
	for(int i = 1000; i >= 0; i--) {
		if(a[i])
		printf(" %d %.1f",i,a[i]);
	}
	return 0;
}


