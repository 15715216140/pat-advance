#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isp(int n) {
	if(n == 1) return false;// 1 is not prime
	if(n == 2 || n == 3 || n == 5)
		return true;
	for(int i = 2; i*i <= n; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n,t;
	while(cin >> n) {
		if(n >= 0) {
			cin >> t;
			int n1 = n;
			int s[32];
			int te = 0;
			while(n) {
				s[te++] = n % t;
				n = n / t;
			} //ȡ��ÿһλ //�������������� 
			int sum = 0, t1 = 1;
			for(int i = 0; i < te; i++) {//��Ҫ��ת���͵��ŵ��� 
				sum = sum*t + s[i]; 
			}//t����ת��10���� 
			if(isp(n1) && isp(sum)) 	cout << "Yes\n";
			else 							cout << "No\n";
		}
		else return 0;
	} 
	return 0;
}


