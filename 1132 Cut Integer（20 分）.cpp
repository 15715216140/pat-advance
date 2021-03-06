1132 Cut Integer（20 分）
Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20). Then N lines follow, each gives an integer Z (10 ≤ Z <2
​31
​​ ). It is guaranteed that the number of digits of Z is an even number.

Output Specification:
For each case, print a single line Yes if it is such a number, or No if not.

Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int k, n;
    scanf("%d", &k);
    while(k--){
        scanf("%d", &n);
        string s = to_string(n);
        int si = s.size();
        int a = stoi(s.substr(0,si/2)), b = stoi(s.substr(si/2));
        if(a * b != 0 && n % (a * b) == 0) 
            cout << "Yes\n";
        else  
            cout << "No\n";
    }
    return 0;
}
