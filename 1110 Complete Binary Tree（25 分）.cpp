1110 Complete Binary Tree（25 分）
Given a tree, you are supposed to tell if it is a complete binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each case, print in one line YES and the index of the last node if the tree is a complete binary tree, or NO and the index of the root if not. There must be exactly one space separating the word and the number.

Sample Input 1:
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -
Sample Output 1:
YES 8
Sample Input 2:
8
- -
4 5
0 6
- -
2 3
- 7
- -
- -
Sample Output 2:
NO 1

递归出最大的下标值，
完全二叉树一定把前面的下标充满： 最大的下标值 == 最大的节点数
不完全二叉树前满一定有位置是空，会往后挤： 最大的下标值 > 最大的节点数


#include <iostream>
using namespace std;
struct node{
    int l, r;
}a[100];
int maxn = -1, ans;
void dfs(int root, int index) {
    if(index > maxn) {
        maxn = index;
        ans = root;
    }
    if(a[root].l != -1)
        dfs(a[root].l, index*2);
    if(a[root].r != -1)
        dfs(a[root].r, index*2+1);
}
int main() {
    int n, root = 0, have[100] = {0};
    cin >> n;
    for(int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if(l == "-"){
            a[i].l = -1;
        }else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if(r == "-"){
            a[i].r = -1;
        }else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    }
    while(have[root] != 0) root++;
    dfs(root, 1);
    if(maxn == n) {
        cout << "YES " << ans;
    }else {
        cout << "NO " << root;
    }
    return 0;
}
