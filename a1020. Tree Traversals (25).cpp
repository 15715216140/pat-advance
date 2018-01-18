1020. Tree Traversals (25)
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
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int post[35];
int in[35];
int a[10000] = {0};
int n , cnt = 0;
void pre(int root, int begin, int end, int index) {//把空位置也留出来，标号，有数据的补上，没有的空着； 
	if(begin > end) 	return ;
	int i = begin;
	while(in[i] != post[root])	i++;
	a[index] = in[i];
	pre(root-1 + i - end, begin,i-1,2*index + 1);
	pre(root-1, i+1,end,2*index + 2);
	return ;
	
}
int main() {
//	freopen("test.txt","r",stdin);
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> post[i];
	for(int i = 0; i < n; i++) 
		cin >> in[i];
	pre(n-1,0,n-1,0);
	for(int i = 0; i < 10000; i++) {
			if(a[i]) {
				if(i != 0)	cout << ' ';
				cout << a[i];
			}	
	}
	return 0;
}


