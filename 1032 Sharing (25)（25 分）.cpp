1032 Sharing (25)（25 分）
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.

\ Figure 1

You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).

Input Specification:

Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 10^5^), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.

Output Specification:

For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.

Sample Input 1:

11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
Sample Output 1:

67890
Sample Input 2:

00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
Sample Output 2:
-1
#
用链表存单词，要求判断两个单词是否出现尾部完全相同的情况，如果出现的话输出相同尾部的第一个字母的地址，否则输出-1。
***	链表题
建立节点结构体数组node, 下标i表示地址，value代表字母，next表示下一个地址，flag表示是否此地址在第一个单词中出现。
遍历第一个单词，把flag标记为true。然后遍历第二个单词，如果有某个地址是true，则找到了，输出。否则不存在。
#
#include <iostream>
using namespace std;
struct node{
	int value;
	int next;
	bool flag;
}a[100010]; 
int main() {
	int begin1, begin2, n;
	cin >> begin1 >> begin2 >> n;
	for(int i = 0; i < n; i++) {
		int now, post;
		char ch;
		scanf("%d %c %d",&now, &ch, &post);
		a[now] = {ch,post,false};
	}
	for(int i = begin1; i != -1; i = a[i].next)
		a[i].flag = true;
	for(int i = begin2; i != -1; i = a[i].next ){
		if(a[i].flag) {
			printf("%05d",i);
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
