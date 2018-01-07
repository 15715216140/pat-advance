#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int ismo(string s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1' || s[i] == 'l' || s[i] == '0' || s[i] == 'O')
			return 1;
	}
	return 0;
}
struct stu{
	string name; 
	string pass;
};
int main() {
	stu a[1005];
	int n, cnt = 0;
	bool isneed[1005] = {false};
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].name >> a[i].pass;
		if(ismo(a[i].pass)) {
			cnt++;
			isneed[i] = true;
		}
	}
	if(cnt)		cout << cnt << endl;
	for(int i = 1; i <= n; i++) {
		if(isneed[i]) {
			cout << a[i].name << ' ';
			for(int j = 0; j < a[i].pass.size() ; j++) {
				if(a[i].pass[j] == '1')		a[i].pass[j] = '@';
				if(a[i].pass[j] == '0')		a[i].pass[j] = '%';
				if(a[i].pass[j] == 'l')		a[i].pass[j] = 'L';
				if(a[i].pass[j] == 'O')		a[i].pass[j] = 'o';
				cout << a[i].pass[j];
			}
			cout << endl;
		}
	}
	if(cnt == 0 && n > 1) printf("There are %d accounts and no account is modified\n",n);
	if(cnt == 0 && n == 1) printf("There is %d account and no account is modified\n",n);
	return 0;
}


