#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
int f(int b,int i) {
	int tt = 0;
	int sum = 0;
	while(b) {
		sum += (b%10)*pow(i,tt++);
		b /= 10;
		cout << sum <<' ';
	}
	cout << i<<sum;
	return sum;
} 
int main() {
	int a = 0, b = 0, num, jin, t,sum = 0;
	string s1,s2;
	cin >> s1 >> s2 >> num >> jin;
	for(int i = 0; i < s1.size() ; i++) {
		if(isdigit(s1[i]) )
			a += s1[i]-'0';
		else 
			a+= s1[i]-'a'+10;
	}
	for(int i = 0; i < s2.size() ; i++) {
		if(isdigit(s1[i]) )
			b += s2[i]-'0';
		else 
			b += s2[i]-'a'+10;
	}
	if(num == 2)
		swap(a,b);
	int tt = 0;
	while(a) {
		sum += (a%10)*pow(jin,tt++);
		a /= jin;
	}
	a = sum;
	cout << a <<endl;
	for(int i = 2; i <= 40; i++) {
		if(f(b,i) == a) {
			cout << i;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}


