#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int map[1005][1005] = {0}; 
bool vis[1005] = {false};
int n, m , k;
int dfs(int be) {
	for(int i = 1; i <= n; i++) {
		if(map[be][i] == 1 && vis[i] == false) {
			vis[i] = true; 
			dfs(i);
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] =	map[b][a] = 1;
	}
	for(int iii = 1; iii <= k; iii++) {
		memset(vis,false,sizeof(vis));
		int num;
		cin >> num;
		vis[num] = true;
		int cnt = -1;
		for(int i = 1; i <= n; i++) {
			if(vis[i] == false  ) {
				vis[i] = true;
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


