#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, maxc = 0;
int cnt = 0;
int in[1000] = {0}, out[1000] = {0}, map[1000][1000] = {0};
int res[1000] ={0};
bool vis[1000] = {false};
int dfs(int be) {
	if(out[be] == 0) {
		res[cnt]++;
		if(cnt > maxc)
			maxc = cnt;
		return 0;
	}
	else {
		for(int i = 1; i <= n; i++) {
			if(vis[i] == false && map[be][i] == 1) {
				vis[i] == true;
				cnt++;
				dfs(i);
				vis[i] == false;
				cnt--;
			}
		}
	}
	return 0;
}
int main() {
	int r, c ,num;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> r >> num;
		for(int j = 1; j <= num; j++) {
			cin >> c;
			map[r][c] = 1;
			in[c] = 1;
			out[r] = 1;
		}
	} 
	dfs(1);
	cout << res[0];
	for(int i = 1; i <= maxc; i++) {
		cout << ' ' << res[i];
	}
	return 0;
}


