1068 Find More Coins（30 分）
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 10
​4
​​  coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10
​4
​​ , the total number of coins) and M (≤10
​2
​​ , the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the face values V
​1
​​ ≤V
​2
​​ ≤⋯≤V
​k
​​  such that V
​1
​​ +V
​2
​​ +⋯+V
​k
​​ =M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output "No Solution" instead.

Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k≥1 such that A[i]=B[i] for all i<k, and A[k] < B[k].

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
1.背包问题，重量等于容量，给定总钱数，则次包里的最大价值==总钱数，用choice标记是否这个物品更新过，待会回溯输出。
2.因为要按照字典序输出，先降序排序，回溯时，字典许最大的先输出的

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, m, w[10010], choice[10010][110] = {0}, dp[10010] = {0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w+1, w+n+1, greater<int>());
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = 1;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) cout << "No Solution\n";
    else {
        vector<int> ans;
        while (m > 0) {
            if(choice[n][m] == 1) {
                ans.push_back(w[n]);
                m -= w[n];
            }
            n--;
        }
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) cout << ' ';
            cout << ans[i];
        }
    }
    
}
