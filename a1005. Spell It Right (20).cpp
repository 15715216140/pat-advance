#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string s;
	int a[1000],cnt = 0;
	cin >> s;
	int sum = 0;
	string map[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	for(int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}
	while(sum) {
		a[cnt++] = sum % 10;
		sum /= 10;
	}
	cout << map[a[cnt-1]];
	for(int i = cnt - 2; i >= 0; i--) {
		cout << " " <<  map[a[i]];
	}
	return 0;
}


