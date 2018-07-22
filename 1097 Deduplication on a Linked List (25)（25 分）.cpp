1097 Deduplication on a Linked List (25)（25 分）
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 10^5^) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4^, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:

00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:

00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
#
给出一串链表，认定键值的绝对值相等则这两个节点相同，移除所有相同节点，只保留第一个节点。
依次输出剩下的节点，在此输出移除的节点。
#
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
	int id, value, next;
} a[100001];
int main() {
	int begin, n, isappear[100001] = {0};
	vector<node> v1, v2;
	cin >> begin >> n;
	for(int i = 0; i < n; i++) {
		int tid, tvalue, tnext;
		scanf("%d%d%d", &tid, &tvalue, &tnext);
		a[tid] = {tid,tvalue,tnext};
	}
	for(int i = begin; i != -1; i = a[i].next) {
		if(isappear[abs(a[i].value)] == 0)	{
			v1.push_back(a[i]);
			isappear[abs(a[i].value)] = 1;
		} else {
			v2.push_back(a[i]);
		}
	}
	for(int i = 0; i < v1.size(); i++) {
		if(i != v1.size() - 1)
			printf("%05d %d %05d\n",v1[i].id, v1[i].value, v1[i+1].id);
		else
			printf("%05d %d -1\n",v1[i].id, v1[i].value);
	}
	for(int i = 0; i < v2.size(); i++) {
		if(i != v2.size() - 1)
			printf("%05d %d %05d\n",v2[i].id, v2[i].value, v2[i+1].id);
		else
			printf("%05d %d -1\n",v2[i].id, v2[i].value);
	}
	return 0;
}
