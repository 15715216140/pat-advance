#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int main() {
	stack <int> s; 
	int a, b, sum, count = 0, j = 0,jj = 0;
	int ar[10],br[10];
	cin >> a >> b;
	sum = a + b;
	if(sum < 0 ) {
		cout << '-' ;
		sum = sum * -1;
	} 
	if(sum == 0) {
		cout << 0;
		return 0;//不要忘记0的情况 
	} 
	while(sum) {
		ar[count++] = sum % 10;
		sum /= 10;
	}
	for(int i = 0; i < count; i++) {
		br[i] = ar[count - i -1];
	}
	for(int i = 0; i < count ; i++) {
		j = count - i;
		if((j == 3 || j == 6 || j == 9) && i != 0 ) {
			cout << ',';
		}
		cout << br[i];
	}
	return 0;
}


