1051 Pop Sequence (25)（25 分）
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:

5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:

YES
NO
NO
YES
NO
# *****************满意 
模拟进栈出栈，把要查询的出栈顺序放进一个待出栈队列中，每次入栈，在栈不空的情况下，若栈顶和队头相等，出栈出队列。
如果能正常运转，最后队列和栈都空了，则是合法序列。注意：每次入栈检查是否栈溢出，若溢出可提前判断不合法并退出。 
#
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(){
	int m, n, k, num;
	cin >> m >> n >> k;
	while(k--) {
		stack<int> s;
		queue<int> q;
		for(int i = 0; i < n; i++) {
			cin >> num;
			q.push(num);
		}
		for(int i = 1; i <= n; i++) {
			s.push(i);
			if(s.size() > m) 	break;
			while(!s.empty() && s.top() == q.front()) {
				s.pop();
				q.pop();
			} 
		}
		if(s.empty())	cout << "YES\n";
		else		cout << "NO\n";
	} 
	return 0;
}