
1003. Emergency (25)

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4

遍历每条路径，输出最短路径条数，和最短路径中人数最多的总人数 

#include <iostream>
#include <algorithm>
using namespace std;
int map[510][510] = {0}, weight[510] = {0}, sum[510] = {0};
bool vis[510] = {false};
int cnt = 0, peo, minl = 999999, sump = 0,suml= 0, l = 0, n, m, c1, c2;
int dfs(int be) {
	if(be == c2) {//深搜遍历每条路径； 
		if(l < minl) {//如果新路径更小，此时最小路径数量重置为一，总人数为当前人数； 
			minl = l;
			suml = 1;
			sump = peo;
		} else if (l == minl) {//如果新路径长度==原路径长度；此时最小路径数量+1
								//，总认识为当前人数 = 当前人数和旧路径人数取最大值  
			suml++;
			sump = max(sump,peo);
		}
		return 0;
	} else {
		for(int i = 0; i < n; i++) {
			if(map[be][i] && vis[i] == false) {
				vis[i] = true;
				peo += weight[i];
				l += map[be][i];
				dfs(i);
				vis[i] = false;
				peo -= weight[i];
				l -= map[be][i];
			}
		}
	}
	return 0;
}
int main() {
	cin >> n >> m >> c1 >> c2;
	for(int i = 0; i < n; i++)
		cin >> weight[i];
	int a, b, c;
	for(int j = 0; j < m; j++) {
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}
	vis[c1] = true;
	peo = weight[c1];
	dfs(c1);
	cout << suml <<  " "<< sump;
	return 0;
}
