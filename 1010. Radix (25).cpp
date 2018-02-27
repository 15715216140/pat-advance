1010. Radix (25)
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
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:

Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:

For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2
Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
0.7.19测试点没通过 3分拿不住了 
#include <iostream>
using namespace std;
int main() {
	string a, b;
	long long t, mod, sum1 = 0, sum2 = 0;
	cin >> a >> b >> t >> mod;
	if(t == 2)	swap(a,b);
	for(int i = 0; i < a.size() ; i++) {
		int f = isdigit(a[i]) ? (a[i] - '0') : (a[i] - 'a' + 10);
		sum1  = sum1 * mod + f;
	}
	for(int j = 1; j < 500; j++) {
		sum2 = 0;
		for(int i = 0; i < b.size() ; i++) {
			int f = isdigit(b[i]) ? (b[i] - '0') : (b[i] - 'a' + 10);
			sum2  = sum2 * j + f;
		}
		if(sum1 == sum2) {
			cout << j;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}

