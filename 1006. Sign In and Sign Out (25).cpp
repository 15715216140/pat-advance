#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct peo{
	string name;
	int a1, a2, a3, b1, b2, b3;
};
int main() {
	int n;
	cin >> n;
	peo be, ed, t;
	char c;
	be.a3 = 24*3600;//初始化开门最晚，以便每次更新
	ed.a3 = 0;		//初始化关门最早，以便每次更新 
	for(int i = 0; i < n; i++) {
		cin >> t.name >> t.a1>> c >>  t.a2 >> c >> t.a3 >> t.b1 >> c >>  t.b2 >> c >> t.b3;
		t.a3  = t.a1*3600 + t.a2*60 + t.a3;
		t.b3  = t.b1*3600 + t.b2*60 + t.b3;
		if(be.a3 > t.a3)
			be = t;
		if(ed.b3 < t.b3)
			ed = t;
	}
	cout << be.name  << ' ' << ed.name ;
	return 0;
}


