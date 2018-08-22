1078 Hashing（25 分）
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10
​4
​​ ) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
平方探法，探测步长[0 ~ size-1];时停止
#include <iostream>
using namespace std;
int m, n, a[10100];
bool isprime(int num) {
    if(num == 1) return false;
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}
void insert(int num) {
    for(int i = 0; i < m; i++) {
        if(a[(num + i * i) % m] == 0) {
            a[(num + i * i) % m] = 1;
            cout << (num + i * i) % m;
            return ;
        }
    }
    cout << '-';
}
int main() {
    cin >> m >> n;
    while(!isprime(m)) m++;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(i != 0) cout << ' ';
        insert(num);
    }
    return 0;
}
