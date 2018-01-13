#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
	map<string,set<int>> mp1, mp2, mp3, mp4, mp5;
void f(map<string,set<int>> &mp, string &t) {//传参用引用，否则会超时 
	if(mp.find(t) != mp.end()) {//判断是否查找到 
        for(auto it = mp[t].begin(); it != mp[t].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
//	freopen("test.txt","r",stdin);
	string t;
	int n , id;
	cin >> n;
	for(int i = 1; i<= n; i++) {
		scanf("%d\n", &id);
		getline(cin,t);
		mp1[t].insert(id); 
		getline(cin,t);
		mp2[t].insert(id); 
		while (cin >> t) {
			mp3[t].insert(id); 
			char c = getchar();
			if(c == '\n')	break;
		}
		getline(cin,t);
		mp4[t].insert(id); 
		getline(cin,t);
		mp5[t].insert(id);   
	}
	int m;
	cin >> m;
	int num;
	for(int i = 1; i <= m; i++) {
		scanf("%d: ",&num);
		getline(cin,t);
		cout << num << ": " << t << endl;
		if(num == 1)	f(mp1,t);
		if(num == 2)	f(mp2,t);
		if(num == 3)	f(mp3,t);
		if(num == 4)	f(mp4,t);
		if(num == 5)	f(mp5,t);
	}
	return 0;
}


