#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int ar[10010],sum[10010] = {0}; 
int main() {
	int n, a, b, bi, ai;
	cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> ar[i];
  	}
	int maxn = 0;
    for(int i = 1; i <= n; i++) {//dp,sum[i]表示以i为结尾的子串的和的最大值 
      if(sum[i-1] < 0)
        sum[i] = ar[i];
      else
        sum[i] = sum[i-1] + ar[i];
      if(sum[i] > maxn) 
        maxn = sum[i];
    }
    for(int i = 1; i <=n; i++) {
      if(sum[i] == maxn) {
        b = ar[i];
        bi = i;
        break;
      }
    }
    for(int i = bi; i >= 0; i--) {
      ai = i;
      if(sum[i-1] <= 0)
      break;
    }
    //判断全部负数 
    bool isf = false;
 	for(int i = 1; i <= n; i++) {
		if(ar[i] >= 0) {
			isf = true;
			break;
		}
	}
	if(isf == false) {
		cout << 0   <<  ' '  << ar[1] << ' ' << ar[n];
		return 0;
	}
    cout << maxn <<  ' ' << ar[ai] << ' ' << ar[bi];
    return 0;
}

