#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct stu{
	string name;
	char c;
	string id;
	int sco;
}; 
int main() {
	int n ;
	stu a[10000];
	cin >> n;
	int mins = 100, maxs = 0, minbe = 0, maxbe = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].name >> a[i].c >> a[i].id >> a[i].sco ;
		if(a[i].c == 'M') {
			if(a[i].sco < mins) {
				mins = a[i].sco ;
				minbe = i;
			}
		}
		if(a[i].c == 'F') {
			if(a[i].sco > maxs) {
				maxs = a[i].sco ;
				maxbe = i;
			}
		}
	}
	if(maxbe == 0) 	cout << "Absent\n";
	else 			cout << a[maxbe].name  << ' ' << a[maxbe].id << endl;
	
	if(minbe == 0) 	cout << "Absent\n";
	else			cout << a[minbe].name  << ' ' << a[minbe].id << endl;
	
	if(maxbe != 0 && minbe != 0)	cout << a[maxbe].sco - a[minbe].sco  << endl;
	else							cout << "NA\n";
	return 0;
}


