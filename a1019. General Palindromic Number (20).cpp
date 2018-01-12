#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n, d, cnt = 0;
	int s[50] = {0};
	cin >> n >> d;
	while(n) {
		s[cnt++] = n % d;
		n = n / d; 
	} 
	if(cnt == 0) {
		cout << "Yes\n";
		cout << 0;
		return 0 ;
	}
	for(int i = 0; i <= cnt/2 - 1; i++) {
		if(s[i] != s[cnt-1-i]) {
			cout << "No\n";
			cout << s[cnt-1];
			for(int i = cnt-2; i >= 0; i--) {
				cout <<  ' ' << s[i];
			}
			return 0;
		}
	}
	cout << "Yes\n";
	cout << s[cnt-1];
	for(int i = cnt-2; i >= 0; i--) {
		cout <<  ' ' << s[i];
	}
	return 0;
}


