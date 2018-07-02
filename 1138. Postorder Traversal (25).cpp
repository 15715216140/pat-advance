1138. Postorder Traversal (25)

Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.

Sample Input:
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
  int pre[50005];
  int in[50005];
  int a[50005] = {0};
  int  maxn = 0;
 
int post(int root, int begin, int end) {
  if(begin > end)    return 0;
  int i = begin ;
  while(i < end && in[i] != pre[root])  i++; 
  post(root+1,begin,i-1);
  post(root+1+i-begin,i+1,end);
  a[maxn++] = in[i];
}
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) 
    cin >> pre[i];
  for(int i = 0; i < n; i++) 
    cin >> in[i];
  post(0,0,n-1);
  cout << a[0];
  
return 0;
}
