1065. A+B and C (64bit) (20)
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.
Input Specification:
The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.
Output Specification:
For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1)."
Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

若a, b异号或有一个等于0不会溢出直接判断，
否则a,b同号，然后a若,c异号，可直接判断，
否则a,c同号，把b移到右面计算，不会溢出

Sample Output:
Case #1: false
Case #2: true
Case #3: false
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string ans;
        long long  a, b, c;
        cin >> a >> b >> c;
        if((a <= 0 && b >=0 ) || (a >= 0 && b <= 0)) {
            if(a + b > c) ans = "true";
            else ans = "false";
        }else {
            if(a > 0 && c <= 0) ans = "true";
            else if( a < 0 && c >= 0) ans = "false";
            else if(a > c - b) ans = "true";
            else ans = "false";
        }
        printf("Case #%d: %s\n", i, ans.c_str());
    }
}
