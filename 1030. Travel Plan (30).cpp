1030. Travel Plan (30)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40  
���������·�������ж������·����������ٻ��ѵ��Ǹ�(�������·����·�����ȣ�����) 
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack<int> st1, st2, stans;
int mp[510][510] = {0}, sum = 0, n, m, be, endd, ans = 99999999;
bool vis[510] = {false};
void dfs(int begin) {
	if(begin == endd) {
		if(sum < ans) {
			ans = sum;//sum/100000��ʾ·�����ȣ� sum/100000��ʾ����; 
			st2 = st1;//�ҵ����ŵ�·���Ͱ���·������(·����ջ�洢�� 
		}
		return ;
	}
	for(int i = 0; i < n; i++) 
		if(vis[i] == false && mp[begin][i]) {
			sum += mp[begin][i];
			vis[i] = true;
			st1.push(i);
			dfs(i);
			st1.pop();
			vis[i] = false;
			sum -= mp[begin][i];
		}
	return ;
}
int main() {
	int tbe, tend, tlen, tcost;;
	cin >> n >> m >> be >> endd;
	for(int i = 0; i < m; i++) {
		cin >> tbe >> tend >> tlen >> tcost;
		mp[tbe][tend] = tlen*100000 + tcost;
		mp[tend][tbe] = tlen*100000 + tcost;
	}
	vis[be] = true;
	dfs(be);
	cout << be;
	while(!st2.empty()) {
		stans.push(st2.top());
		st2.pop();
	}
	while(!stans.empty()) {
		cout << ' ' << stans.top();
		stans.pop();
	}
	cout << ' ' << ans / 100000 << ' '  << ans % 100000;
	return 0;
}
