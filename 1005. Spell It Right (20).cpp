1005 Spell It Right (20)（20 分）
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:

12345
Sample Output:

one five

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


