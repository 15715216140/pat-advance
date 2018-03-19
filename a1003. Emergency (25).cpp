#include <iostream>
#include <algorithm>
using namespace std;
int map[510][510] = {0}, weight[510] = {0}, sum[510] = {0};
bool vis[510] = {false};
int cnt = 0, peo, minl = 999999, sump = 0,suml= 0, l = 0, n, m, c1, c2;
int dfs(int be) {
	if(be == c2) {
		if(l < minl) {
			minl = l;
			suml = 1;
			sump = peo;
		} else if (l == minl) {
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
