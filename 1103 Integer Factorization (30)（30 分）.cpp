1103 Integer Factorization (30)（30 分）
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:

Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a line are separated by a space.

Output Specification:

For each case, if the solution exists, output in the format:

N = n~1~\^P + ... n~K~\^P

where n~i~ (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 12^2^ + 4^2^ + 2^2^ + 2^2^ + 1^2^, or 11^2^ + 6^2^ + 2^2^ + 2^2^ + 2^2^, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a~1~, a~2~, ... a~K~ } is said to be larger than { b~1~, b~2~, ... b~K~ } if there exists 1<=L<=K such that a~i~=b~i~ for i<L and a~L~>b~L~

If there is no solution, simple output "Impossible".

Sample Input 1:

169 5 2
Sample Output 1:

169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
Sample Input 2:

169 167 3
Sample Output 2:

Impossible
#
给出n, k , p 找出k个不为0的数，使得他们的p次方之和等于n。
若存在多个这样的序列，找出底数和大的那个，还存在多个这样的序列，字典序最大的那个，
#
用fac标记，fac[i] = a;表示 i^p = a。从后往前搜索，这样每次最先搜到的结果字典序一定最大。
对于一个数，选：index不变，nowk+1, sum+fac[index]，facsum+index
		 不选：index-1, 其他不变
剪枝与边界条件:
	1 如果 nowk 或者 sum 有一个超出，即可减掉
	2 如果 nowk 或者 sum 有一个达到标准，另一个为达标，即可减掉

	3 如果 nowk 和 sum 都达标，合格序列
	4 前三个条件都不满足，继续递归
#


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n, k, p, maxn = -1;
vector<int> fac, ans, temp;
void init() {
	for(int i = 0; pow(i,p) <= n; i++) 
		fac.push_back(pow(i,p));
}
void dfs(int index, int nowk, int sum, int facsum) {
	if(sum > n || nowk > k) return ;
	if((sum == n && nowk != k) || (sum != n && nowk == k)) return ;
	if(k == nowk && sum == n) {
		if(facsum > maxn) {
			ans = temp;
			maxn = facsum;
		}
		return ;
	}
	if(index >= 1) {
		temp.push_back(index);
		dfs(index, nowk + 1, sum + fac[index], facsum + index);
		temp.pop_back();
		dfs(index - 1, nowk, sum, facsum);
	}
}
int main(){	
	cin >> n >> k >> p;
	init();
	dfs(fac.size() - 1, 0, 0 ,0);
	if(maxn == -1)	cout <<"Impossible\n";
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for(int i = 1; i < ans.size(); i++)
			printf(" + %d^%d",ans[i], p);;
	}
	
	return 0;
}
