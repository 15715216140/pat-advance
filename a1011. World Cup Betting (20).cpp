#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	float sum = 1;
	string s = "0WTL";
	for(int i = 1; i <= 3; i++) {
		float a, b, num = 1;
		cin >> a;
		float maxn = a;
		for(int j = 2; j <= 3; j++) {
			cin >> b;
			if(maxn < b) {
				num = j;
				maxn = b;
			}
		} 
		sum *= maxn;
		cout << s[num] << ' ';
	} 
	printf("%.2f",(sum*0.65 - 1)*2);
	return 0;
}


