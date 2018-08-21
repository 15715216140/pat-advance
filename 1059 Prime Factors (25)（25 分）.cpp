1059 Prime Factors (25)（25 分）
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:

Factor N in the format N = p~1~\^k~1~ * p~2~\^k~2~ *…*p~m~\^k~m~, where p~i~'s are prime factors of N in increasing order, and the exponent k~i~ is the number of p~i~ -- hence when there is only one p~i~, k~i~ is 1 and must NOT be printed out.

Sample Input:

97532468
Sample Output:

97532468=2^2*11*17*101*1291
#素数#
先用素数筛子把所有素数放入容器v中，一个个找，找出n中有几个此素数，标记并且放进容器ans中。
注意结果如果n除到最后没有除掉，说明它自己本身就是素数，或者n一开始就是1就直接输出
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a[50001] = {0}, nn, n;
    cin >> n;
    nn = n;
    vector<int> v, anse, ansc;
    for(int i = 2; i <= 5000; i++) {
        if(a[i] == 0) {
            v.push_back(i);
            for(int j = 2; j * i <= 50000; j++)
                a[i*j] = 1;
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(n % v[i] == 0) {
            int cnt = 0;
            while(n % v[i] == 0) {
                cnt++;
                n /= v[i];
            }
            ansc.push_back(v[i]);
            anse.push_back(cnt);
        }
    }
    printf("%ld=",nn);
    for(int i = 0; i < anse.size(); i++){
        if(i != 0) cout << '*';
        cout << ansc[i];
        if(anse[i] != 1)
            cout << '^' << anse[i];
    }
    if(n != 1 || nn == 1 ) cout << n;
}
