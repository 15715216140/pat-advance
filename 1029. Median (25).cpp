
1029. Median (25)

Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, m, t;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> t;
		v.push_back(t);
	}
	nth_element(v.begin(),v.begin() + ((m+n-1) /2 ),v.end());
	cout << v[(m+n-1)/2];
	return 0;
}

·¨¶þ
#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main() {
	queue<int> a, b;
	int n, m, t, ans;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a.push(t); 
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> t;
		b.push(t); 
	}
	a.push(INT_MAX); 
	b.push(INT_MAX);  
	for(int i = 0; i < (n+m+1) / 2; i++) {
		ans = min(a.front() , b.front() );
		if(a.front() < b.front())	a.pop() ;
		else						b.pop() ;	
	}
	cout << ans;
return 0;
} 
