#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m[10000][10000] = {0};
struct stu {
	int t1, t2;
};
bool cmp (stu x, stu y) {
	if(x.t1 == y.t1)	return	x.t2 < y.t2 ;
	else				return	x.t1 < x.t1 ;
}
int main() {
	freopen("test.txt","r",stdin);
	int n, mm ;
	vector<int> v[10000];
	cin >> n >> mm;
	for(int i = 0;  i < mm; i++) {
		string	a, b;
		int ia, ib;
		cin >> a >> b;
		ia = abs(stoi(a));
		ib = abs(stoi(b));
		m[ia][ib] = m[ib][ia] = 1;
		if(a.size() == b.size() ) {
			v[ia].push_back(ib);
			v[ib].push_back(ia);
		}
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++) {
		vector<stu> ans;
		string a, b;
		cin >> a >> b;
		int ia, ib;
		ia = abs(stoi(a));
		ib = abs(stoi(b));
		for(int j = 0; j < v[ia].size(); j++)
			for(int jj = 0; jj < v[ib].size(); jj++)
				if(v[ia][j] != ib && v[ib][jj] != ia && m[v[ia][j]][v[ib][jj]] )
					ans.push_back(stu {v[ia][j] , v[ib][jj]});
		sort(ans.begin(),ans.end(),cmp);
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++)
			printf("%04d %04d\n",ans[i].t1,ans[i].t2);
	}
	return 0;

}

