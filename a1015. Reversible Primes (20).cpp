#include <iostream>
using namespace std;
bool isprime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}
int main() {
    string s;
    while(cin >> s) {
    	if(stoi(s) < 0) 	return 0;
    	int n = stoi(s), m = stoi(s), t = 0, d;
		cin >> d;
        while(n) {
        	t  = t * d + n % d; 
        	n = n / d; 
		}
        if(isprime(m) && isprime(t))	cout <<  "Yes\n";
		else 							cout <<  "No\n";
    }
    return 0;
}
