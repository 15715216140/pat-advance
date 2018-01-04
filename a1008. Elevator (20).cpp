#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n, f, sum = 0, now = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> f;
		if(f-now > 0) {
			sum += (f-now) * 6;
		}
		if(f-now < 0) {
			sum += (f-now) * 4 * -1;
		}
		sum += 5;
		now = f;
	} 
	cout << sum;
	return 0;
}


