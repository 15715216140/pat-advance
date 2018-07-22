1074 Reversing Linked List (25)（25 分）
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5^) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
#
给出一段链表（里边包含干扰节点），对美每k个数翻转一次，试试最后链表的顺序
用结构体node{id,value,next}表示每个节点，用数组m记录，可以根据id查到该节点信息。
遍历链表，把有用节点存下来，翻转，并记录有用节点的个数,每k个数翻转一次用reverse函数。
输出时候输出当前节点的id和value，next为下一个节点的id
#
调试bug：
忘记记录有用节点个数，导致翻转次数错误
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct node{
	int id, value, next;
};
int main(){
	int begin, n , k, cnt = 0;
	node m[100001];
	vector<node> v;
	cin >> begin >> n >>k;
	for(int i = 0; i < n; i++) {
		int tbegin, tnum, tend;
		scanf("%d%d%d",&tbegin, &tnum, &tend);
		m[tbegin] = {tbegin, tnum, tend};
	} 
	for(int i = begin; i != -1; i = m[i].next) {
		cnt++;
		v.push_back(m[i]);
	}
	int group = cnt / k;
	for(int i = 0; i < group; i++) 
		reverse(v.begin() + i * k,v.begin() + k * i + k);
	for(int i = 0; i < v.size() - 1; i++) 
		printf("%05d %d %05d\n", v[i].id, v[i].value, v[i+1].id);
	printf("%05d %d -1\n", v[cnt-1].id, v[cnt-1].value);
	return 0;
}
