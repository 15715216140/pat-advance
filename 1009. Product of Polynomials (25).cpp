1009 Product of Polynomials (25)（25 分）
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input

2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output

3 3 3.6 2 6.0 1 1.6

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    float map[1005][2] = {0};
    float res[2005] = {0};
    int n, m, ex, cnt = 0;
    float co;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> ex >> co;
        map[ex][0] = co;
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ex >> co;
        map[ex][1] = co;
    }
    for(int i = 0; i <= 1000; i++) {//A中的每个元素*B中的每个元素
        for(int j = 0; j <= 1000; j++) {
            res[i+j] += map[i][0] * map[j][1];
        }
    }
    for(int i = 2000; i >= 0; i--) {
        if(res[i])
            cnt++;
    }
    cout << cnt;
    for(int i = 2000; i >= 0; i--) {
        if(res[i]) {
            cout  << ' ' << i << ' ' ;
            printf("%.1f",res[i]);
        }
    }
    return 0;
}



