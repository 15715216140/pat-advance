
1024. Palindromic Number (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool is(string s) {
	string res = s;
	reverse(s.begin() ,s.end() );
	return s == res;
}
string  add(string a, string b) {
	string s = a;
	int car = 0;
	for(int i = s.size() - 1; i >= 0 ; i--) {
		s[i] = (a[i] + b[i] - '0' - '0' + car) % 10 + '0';
		car = (a[i] + b[i] - '0' - '0' + car) / 10;
	}
	if(car) 	s = '1' + s;
	return s ;
}
int main() {
	string s, res, fin;
	int k;
	cin >> s >> k;
	if(is(s))  {
		cout << s << endl << 0;
		return 0;
	}
	for(int i = 1; i <= k; i++) {
		res = s;
		reverse(s.begin() , s.end() );
		fin = add(s,res);
		if(is(fin)) {
			cout << fin << endl <<  i;
			return 0;
		}
		s = fin;
	}
	cout << fin << endl <<  k;
	return 0;
}

