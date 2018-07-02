1007 Maximum Subsequence Sum (25)（25 分）
Given a sequence of K integers { N~1~, N~2~, ..., N~K~ }. A continuous subsequence is defined to be { N~i~, N~i+1~, ..., N~j~ } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:

10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:

10 1 4

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

